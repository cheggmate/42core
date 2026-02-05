# ft_popen Explanation (`my_popen.c`)

A detailed step-by-step guide explaining how `my_popen.c` implements a simplified popen().

---

## Table of Contents

1. [What is ft_popen?](#what-is-ft_popen)
2. [The Subject Requirements](#the-subject-requirements)
3. [Key Concepts](#key-concepts)
4. [Step-by-Step Code Walkthrough](#step-by-step-code-walkthrough)
5. [Visual Diagrams](#visual-diagrams)
6. [Summary](#summary)

---

## What is ft_popen?

**ft_popen** is a reimplementation of the standard C library's `popen()` function. It:

1. Executes a command in a child process
2. Returns a file descriptor to either:
   - **Read** the command's output (type = 'r')
   - **Write** to the command's input (type = 'w')

### Comparison with Standard popen()

| Feature | Standard popen() | ft_popen() |
|---------|------------------|------------|
| Return type | `FILE *` | `int` (raw fd) |
| Close function | `pclose()` | `close()` |
| Uses | Shell command string | execvp with argv |

---

## The Subject Requirements

| Requirement | Description |
|-------------|-------------|
| **Function** | `int ft_popen(const char *file, char *const argv[], char type)` |
| **type='r'** | Return fd connected to command's stdout |
| **type='w'** | Return fd connected to command's stdin |
| **Return** | File descriptor on success, -1 on error |
| **Allowed Functions** | `pipe`, `fork`, `dup2`, `execvp`, `close`, `exit` |

---

## Key Concepts

### 1. Pipe Direction

A pipe is **unidirectional**: data flows from `fd[1]` (write end) to `fd[0]` (read end).

```
fd[1] ─────────────────────► fd[0]
(write end)    DATA FLOW     (read end)
```

### 2. The Two Modes

#### Mode 'r' (Read from command)
Parent wants to read what the command outputs.

```
┌──────────────┐         PIPE          ┌──────────────┐
│    Child     │                       │    Parent    │
│  (command)   │ stdout ───────────────► reads from   │
│              │        fd[1] → fd[0]  │   returned   │
└──────────────┘                       └──────────────┘
```

#### Mode 'w' (Write to command)
Parent wants to send data to command's input.

```
┌──────────────┐         PIPE          ┌──────────────┐
│    Parent    │                       │    Child     │
│ writes to ───────────────────► stdin │  (command)   │
│  returned    │        fd[1] → fd[0]  │              │
└──────────────┘                       └──────────────┘
```

---

## Step-by-Step Code Walkthrough

### Phase 1: Validation

```c
if (!file || !av || (type != 'r' && type != 'w') || pipe(fd) < 0)
    return (-1);
```

Check that:
- `file` is not NULL
- `av` (argument vector) is not NULL
- `type` is either 'r' or 'w'
- `pipe()` succeeds

---

### Phase 2: Fork Child Process

```c
pid = fork();
if (pid < 0)
{
    close(fd[0]);
    close(fd[1]);
    return (-1);
}
```

Fork fails: clean up the pipe and return error.

---

### Phase 3: Child Process

```c
if (pid == 0)
{
    dup2(fd[type == 'r' ? 1 : 0], type == 'r' ? 1 : 0);
    close(fd[0]);
    close(fd[1]);
    execvp(file, av);
    exit(1);
}
```

#### The Ternary Expressions Explained

| type | `fd[type == 'r' ? 1 : 0]` | `type == 'r' ? 1 : 0` | Meaning |
|------|---------------------------|----------------------|---------|
| 'r' | `fd[1]` (write end) | `1` (stdout) | Child's stdout → pipe write end |
| 'w' | `fd[0]` (read end) | `0` (stdin) | Child's stdin ← pipe read end |

So the `dup2` call redirects:
- **For 'r'**: Child's stdout to pipe's write end
- **For 'w'**: Child's stdin to pipe's read end

---

### Phase 4: Parent Process

```c
close(fd[type == 'r' ? 1 : 0]);
return (fd[type == 'r' ? 0 : 1]);
```

| type | Close this end | Return this end |
|------|----------------|-----------------|
| 'r' | `fd[1]` (write) | `fd[0]` (read) |
| 'w' | `fd[0]` (read) | `fd[1]` (write) |

- **For 'r'**: Parent doesn't write, so close `fd[1]`. Return `fd[0]` to read from.
- **For 'w'**: Parent doesn't read, so close `fd[0]`. Return `fd[1]` to write to.

---

## Visual Diagrams

### Mode 'r': Reading Command Output

```
SETUP:
1. pipe(fd) creates:    fd[0] ◄──────────────── fd[1]
                         read                   write

2. fork() creates child process

3. Child does:
   dup2(fd[1], STDOUT)  → stdout now writes to pipe
   close(fd[0])
   close(fd[1])
   execvp("ls", argv)

4. Parent does:
   close(fd[1])         → parent doesn't write
   return fd[0]         → parent reads from here

RESULT:
┌─────────────────┐                    ┌─────────────────┐
│     Child       │                    │     Parent      │
│                 │    ╔═══════════╗   │                 │
│  execvp("ls")   │    ║   PIPE    ║   │  fd = ft_popen()│
│       │         │    ║           ║   │       │         │
│       ▼         │    ║           ║   │       ▼         │
│    stdout ──────────►║───────────╠───────► fd (read)   │
│  (fd 1)         │    ║           ║   │                 │
│                 │    ╚═══════════╝   │  read(fd,...)   │
└─────────────────┘                    └─────────────────┘

Output from "ls" flows through pipe to parent's fd
```

### Mode 'w': Writing to Command Input

```
SETUP:
1. pipe(fd) creates:    fd[0] ◄──────────────── fd[1]
                         read                   write

2. fork() creates child process

3. Child does:
   dup2(fd[0], STDIN)   → stdin now reads from pipe
   close(fd[0])
   close(fd[1])
   execvp("cat", argv)

4. Parent does:
   close(fd[0])         → parent doesn't read
   return fd[1]         → parent writes to here

RESULT:
┌─────────────────┐                    ┌─────────────────┐
│     Parent      │                    │     Child       │
│                 │    ╔═══════════╗   │                 │
│  fd = ft_popen()│    ║   PIPE    ║   │  execvp("cat")  │
│       │         │    ║           ║   │       │         │
│       ▼         │    ║           ║   │       ▼         │
│   fd (write) ────────╠───────────║──────► stdin        │
│                 │    ║           ║   │   (fd 0)        │
│  write(fd,...)  │    ╚═══════════╝   │                 │
└─────────────────┘                    └─────────────────┘

Data from parent flows through pipe to child's stdin
```

---

## Summary

### The Algorithm

1. **Validate** parameters (file, av, type)
2. **Create pipe** for communication
3. **Fork** child process
4. **Child**: Redirect stdout/stdin to pipe, execute command
5. **Parent**: Close unused pipe end, return useful end

### Key Insight: The Ternary Pattern

```c
// Child redirects
dup2(fd[type == 'r' ? 1 : 0], type == 'r' ? 1 : 0);
//    └── which pipe end     └── which std fd

// Parent returns
return fd[type == 'r' ? 0 : 1];
//        └── opposite end from child
```

### Common Use Cases

```c
// Read directory listing
int fd = ft_popen("ls", (char *[]){ "ls", "-l", NULL }, 'r');
while (read(fd, buf, sizeof(buf)) > 0)
    // process output...
close(fd);

// Write to a command
int fd = ft_popen("cat", (char *[]){ "cat", NULL }, 'w');
write(fd, "Hello from parent!\n", 19);
close(fd);
```

---

## Files Reference

- [my_popen.c](file:///home/jc/Videos/42e4/my04/popen/my_popen.c) - The annotated implementation
- [subject_6.txt](file:///home/jc/Videos/42e4/my04/popen/subject_6.txt) - The original subject/requirements
