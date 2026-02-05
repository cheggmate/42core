# Picoshell Explanation (`my_picoshell.c`)

A detailed step-by-step guide explaining how `my_picoshell.c` implements a shell pipeline executor.

---

## Table of Contents

1. [What is Picoshell?](#what-is-picoshell)
2. [The Subject Requirements](#the-subject-requirements)
3. [Key Concepts](#key-concepts)
4. [Step-by-Step Code Walkthrough](#step-by-step-code-walkthrough)
5. [Visual Diagram](#visual-diagram)
6. [Common Pitfalls](#common-pitfalls)
7. [Summary](#summary)

---

## What is Picoshell?

**Picoshell** is a mini shell implementation that executes a pipeline of commands. When you type in a shell:

```bash
ls | grep txt | wc -l
```

The shell:
1. Executes `ls` (list files)
2. Pipes its output to `grep txt` (filter lines containing "txt")
3. Pipes that output to `wc -l` (count lines)

Picoshell does exactly this: it takes an array of commands and connects them with pipes, so the output of one becomes the input of the next.

---

## The Subject Requirements

| Requirement | Description |
|-------------|-------------|
| **Function** | `int picoshell(char **cmds[])` |
| **Input** | NULL-terminated array of commands (each command is argv-style array) |
| **Output** | Returns `0` on success, `1` on any error |
| **Allowed Functions** | `close`, `fork`, `wait`, `exit`, `execvp`, `dup2`, `pipe` |
| **Key Constraint** | Must not leak file descriptors! |

---

## Key Concepts

### 1. Pipes (`pipe()`)

A pipe is a one-way communication channel between processes.

```c
int fd[2];
pipe(fd);   // Creates a pipe
// fd[0] = read end  (use to read data)
// fd[1] = write end (use to write data)
```

```
                    PIPE
    Write End                Read End
    fd[1] ─────────────────► fd[0]
    (cmd1 writes)            (cmd2 reads)
```

### 2. Fork (`fork()`)

Creates an exact copy of the current process.

```c
pid_t pid = fork();
// Returns:
//   0      → in child process
//   > 0    → in parent process (value is child's PID)
//   -1     → error
```

### 3. File Descriptor Redirection (`dup2()`)

Redirects one file descriptor to another.

```c
dup2(old_fd, new_fd);  // new_fd now points to same place as old_fd
```

For piping, we use:
- `dup2(in_fd, 0)` → Make stdin read from pipe
- `dup2(fd[1], 1)` → Make stdout write to pipe

### 4. Execute Command (`execvp()`)

Replaces the current process with a new program.

```c
execvp(cmd[0], cmd);  // cmd = {"ls", "-l", NULL}
// Executes "ls -l"
// Only returns if it fails!
```

---

## Step-by-Step Code Walkthrough

### Phase 0: Initialization

```c
int     i = 0;          // Command index
int     in_fd = 0;      // Input from previous command (starts as stdin)
int     fd[2];          // Current pipe: fd[0]=read, fd[1]=write
pid_t   pid;            // Process ID
```

- `i = 0`: We start with the first command
- `in_fd = 0`: First command reads from real stdin (fd 0)

---

### Phase 1: Main Loop - Process Each Command

```c
while (cmds[i])     // Loop until NULL (end of commands)
```

For each command, we do these steps:

#### Step 1.1: Create Pipe (if not last command)

```c
if (cmds[i + 1] && pipe(fd) < 0)
    return (1);
```

- Check if there's a next command (`cmds[i + 1]`)
- If yes, create a pipe for communication
- If pipe creation fails, return error

**Why only if not last?** The last command outputs to real stdout, no pipe needed.

---

#### Step 1.2: Fork to Create Child Process

```c
pid = fork();
if (pid < 0)
    return (1);
```

- `fork()` creates child process
- Parent and child continue from same point
- Check `pid` value to know which process we're in

---

#### Step 1.3: Child Process Code (`pid == 0`)

The child process does three things:

##### 1.3a: Redirect Input (if not first command)

```c
if (in_fd != 0)
{
    dup2(in_fd, 0);     // Make stdin read from previous pipe
    close(in_fd);       // Close original (not needed after dup2)
}
```

**What this does:**
- `in_fd` holds the read end of the PREVIOUS pipe
- `dup2(in_fd, 0)` makes stdin (fd 0) read from that pipe
- Now when the command reads stdin, it gets previous command's output

##### 1.3b: Redirect Output (if not last command)

```c
if (cmds[i + 1])
{
    dup2(fd[1], 1);     // Make stdout write to current pipe
    close(fd[0]);       // Close read end (child only writes)
    close(fd[1]);       // Close write end (stdout is copy now)
}
```

**What this does:**
- `fd[1]` is the write end of the CURRENT pipe
- `dup2(fd[1], 1)` makes stdout (fd 1) write to that pipe
- Now when command writes to stdout, it goes into the pipe

##### 1.3c: Execute the Command

```c
execvp(cmds[i][0], cmds[i]);
exit(1);
```

**What this does:**
- `execvp` replaces child process with the command
- `cmds[i][0]` = command name (e.g., "ls")
- `cmds[i]` = full argument array (e.g., {"ls", "-l", NULL})
- If `execvp` fails, we call `exit(1)` (it only returns on error)

---

#### Step 1.4: Parent Process Code (`pid > 0`)

The parent does cleanup and prepares for next iteration:

##### 1.4a: Close Previous Pipe's Read End

```c
if (in_fd != 0)
    close(in_fd);
```

**Why?** Parent doesn't need to read from previous pipe. Only the child we just created uses it.

##### 1.4b: Prepare for Next Command

```c
if (cmds[i + 1])
{
    close(fd[1]);       // Close write end (only child uses it)
    in_fd = fd[0];      // Save read end for next command
}
```

**What this does:**
- Close write end of current pipe (parent doesn't write)
- Save read end (`fd[0]`) in `in_fd` for the NEXT iteration
- Next child will read from this pipe!

##### 1.4c: Move to Next Command

```c
i++;
```

---

### Phase 2: Wait for All Children

```c
while (wait(NULL) > 0)
    ;
```

- `wait(NULL)` waits for any child to finish
- Loop until no more children (returns -1)
- We don't check exit status here (simplified version)

---

### Phase 3: Return Success

```c
return (0);
```

---

## Visual Diagram

### For Command: `ls | grep txt | wc -l`

```
Commands array: {{"ls", NULL}, {"grep", "txt", NULL}, {"wc", "-l", NULL}, NULL}

ITERATION 0: Process "ls"
╔═══════════════════════════════════════════════════════════════════╗
║                                                                   ║
║  stdin (fd 0) ──► [Child 1: ls] ──► fd[1] ═══════╗               ║
║                         │                         ║               ║
║                         │                    Pipe 1               ║
║                         │                         ║               ║
║                         ▼                    fd[0] (saved as in_fd)
║                   execvp("ls")                    ║               ║
╚═══════════════════════════════════════════════════════════════════╝

ITERATION 1: Process "grep txt"
╔═══════════════════════════════════════════════════════════════════╗
║                                                                   ║
║  in_fd (from Pipe 1) ──► [Child 2: grep txt] ──► fd[1] ═══════╗  ║
║      (was fd[0])                │                              ║  ║
║           │                     │                         Pipe 2  ║
║           │                     ▼                              ║  ║
║           │              execvp("grep")                   fd[0]   ║
║           │                                         (saved as in_fd)
║           ▼                                                       ║
║      close(in_fd)                                                 ║
╚═══════════════════════════════════════════════════════════════════╝

ITERATION 2: Process "wc -l" (LAST command)
╔═══════════════════════════════════════════════════════════════════╗
║                                                                   ║
║  in_fd (from Pipe 2) ──► [Child 3: wc -l] ──► stdout (fd 1)      ║
║      (was fd[0])                │                                 ║
║           │                     │                                 ║
║           │                     ▼                                 ║
║           │              execvp("wc")                             ║
║           │                                                       ║
║           ▼                                                       ║
║      close(in_fd)                                                 ║
╚═══════════════════════════════════════════════════════════════════╝

No pipe created for last command (outputs directly to terminal)
```

### Why We Close File Descriptors

```
After fork(), both parent and child have copies of all fds:

BEFORE cleanup:
┌─────────────────┐          ┌─────────────────┐
│     Parent      │          │      Child      │
├─────────────────┤          ├─────────────────┤
│ fd[0] = pipe rd │          │ fd[0] = pipe rd │
│ fd[1] = pipe wr │          │ fd[1] = pipe wr │
│ in_fd = prev rd │          │ in_fd = prev rd │
└─────────────────┘          └─────────────────┘

AFTER cleanup:
┌─────────────────┐          ┌─────────────────┐
│     Parent      │          │      Child      │
├─────────────────┤          ├─────────────────┤
│ fd[0] = SAVED   │          │ stdin = in_fd   │ (via dup2)
│ fd[1] = CLOSED  │          │ stdout = fd[1]  │ (via dup2)
│ in_fd = CLOSED  │          │ others = CLOSED │
└─────────────────┘          └─────────────────┘
```

---

## Common Pitfalls

### 1. File Descriptor Leaks

> [!CAUTION]
> If you don't close unused file descriptors, processes may hang forever!

**Why?** A pipe's read end only receives EOF when ALL write ends are closed. If parent keeps write end open, child reading from pipe never gets EOF.

### 2. Forgetting to Close After `dup2()`

```c
dup2(fd[1], 1);     // stdout now points to pipe
close(fd[1]);       // MUST close original fd[1]!
```

After `dup2()`, you have TWO descriptors pointing to the same pipe. Close the original!

### 3. Creating Pipe for Last Command

```c
if (cmds[i + 1] && pipe(fd) < 0)  // CORRECT: only if next exists
```

Last command should output to real stdout, not a pipe.

### 4. Not Handling `execvp` Failure

```c
execvp(cmds[i][0], cmds[i]);
exit(1);  // MUST have this - execvp only returns on failure
```

---

## Summary

### The Algorithm in Simple Terms

1. **For each command:**
   - Create a pipe (except for last command)
   - Fork a child process
   - **Child:** 
     - Redirect stdin from previous pipe (if not first)
     - Redirect stdout to current pipe (if not last)
     - Execute the command
   - **Parent:**
     - Close unused pipe ends
     - Save current pipe's read end for next command

2. **After all commands:**
   - Wait for all children to finish

### Key Points to Remember

| Concept | Purpose |
|---------|---------|
| `pipe(fd)` | Creates communication channel between processes |
| `fork()` | Creates child process to run command |
| `dup2(old, new)` | Redirects file descriptors |
| `execvp()` | Replaces process with command |
| `close()` | Prevents file descriptor leaks |
| `wait()` | Waits for children to finish |

### The Flow

```
cmd1 ──pipe──► cmd2 ──pipe──► cmd3 ──► stdout
  │               │               │
  └── fork()      └── fork()      └── fork()
       │               │               │
       ▼               ▼               ▼
    execvp()       execvp()       execvp()
```

---

## Files Reference

- [my_picoshell.c](file:///home/jc/Videos/42e4/my04/picoshell/my_picoshell.c) - The annotated implementation
- [subject_6.txt](file:///home/jc/Videos/42e4/my04/picoshell/subject_6.txt) - The original subject/requirements
