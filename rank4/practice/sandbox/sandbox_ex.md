# Sandbox Explanation (`my_sandbox.c`)

A detailed step-by-step guide explaining how `my_sandbox.c` implements a function tester with timeout protection.

---

## Table of Contents

1. [What is Sandbox?](#what-is-sandbox)
2. [The Subject Requirements](#the-subject-requirements)
3. [Key Concepts](#key-concepts)
4. [Step-by-Step Code Walkthrough](#step-by-step-code-walkthrough)
5. [Visual Diagrams](#visual-diagrams)
6. [Summary](#summary)

---

## What is Sandbox?

**Sandbox** is a function tester that safely determines if a function is "nice" (safe) or "bad" (dangerous). It:

1. Runs the function in a child process (isolation)
2. Sets a timeout to prevent infinite loops
3. Detects crashes, signals, and abnormal exits

| Function Behavior | Result | Return Value |
|-------------------|--------|--------------|
| Returns normally, exit(0) | Nice | 1 |
| Exits with non-zero code | Bad | 0 |
| Times out | Bad | 0 |
| Crashes (segfault, etc.) | Bad | 0 |
| Sandbox error | Error | -1 |

---

## The Subject Requirements

| Requirement | Description |
|-------------|-------------|
| **Function** | `int sandbox(void (*f)(void), unsigned int timeout, bool verbose)` |
| **Nice function** | Returns 1 if function exits normally with code 0 |
| **Bad function** | Returns 0 if function crashes, times out, or has non-zero exit |
| **Error** | Returns -1 if sandbox itself fails |
| **Verbose messages** | Print specific messages when verbose is true |

---

## Key Concepts

### 1. Process Isolation

By running the function in a child process:
- Crashes don't affect the parent
- Infinite loops can be killed
- Exit codes can be captured

```
┌─────────────────┐         fork()         ┌─────────────────┐
│  Parent Process │ ─────────────────────► │  Child Process  │
│  (Safe Observer)│                        │  (Runs function)│
│                 │ ◄───────waitpid()───── │                 │
│  Checks result  │                        │  f(); exit(0);  │
└─────────────────┘                        └─────────────────┘
```

### 2. Signal Handling with SIGALRM

The `alarm()` function sets a timer. When it expires, SIGALRM is sent.

```c
alarm(timeout);     // Start timer
// ... wait for child ...
alarm(0);           // Cancel timer
```

### 3. Analyzing Exit Status

After `waitpid()`, the status variable tells us *how* the child terminated:

| Macro | What it checks |
|-------|----------------|
| `WIFEXITED(status)` | Did child call exit()? |
| `WEXITSTATUS(status)` | What was the exit code? |
| `WIFSIGNALED(status)` | Was child killed by a signal? |
| `WTERMSIG(status)` | Which signal killed it? |

---

## Step-by-Step Code Walkthrough

### Phase 0: Global Variables

```c
static volatile sig_atomic_t g_timed_out = 0;
static volatile sig_atomic_t g_child_pid = -1;
```

- `volatile`: Tell compiler the value can change unexpectedly
- `sig_atomic_t`: Special type for safe access in signal handlers
- These let the signal handler communicate with main code

---

### Phase 1: The Signal Handler

```c
static void alarm_handler(int sig)
{
    (void)sig;
    g_timed_out = 1;
    if (g_child_pid > 0)
        kill((pid_t)g_child_pid, SIGKILL);
}
```

When timeout occurs:
1. Set flag so parent knows timeout happened
2. Kill the child process (it's taking too long)

---

### Phase 2: Fork and Execute Function

```c
pid = fork();
if (pid == 0)  // Child
{
    f();        // Run the function
    exit(0);    // If we get here, function succeeded
}
```

The child simply runs the function. If function:
- Returns normally → child exits with 0
- Crashes → OS terminates child with a signal

---

### Phase 3: Set Up Alarm

```c
g_child_pid = pid;              // Save PID for signal handler

sigemptyset(&sa.sa_mask);       // Don't block other signals
sa.sa_flags = 0;                // Default behavior
sa.sa_handler = alarm_handler;  // Our handler function
sigaction(SIGALRM, &sa, NULL);  // Register the handler

alarm(timeout);                 // Start the countdown!
```

After `timeout` seconds, if child hasn't finished, alarm fires.

---

### Phase 4: Wait and Analyze

```c
waitpid(pid, &status, 0);       // Block until child terminates
alarm(0);                       // Cancel timer (child is done)

if (g_timed_out)
    // Timeout occurred → Bad

if (WIFEXITED(status))
    if (WEXITSTATUS(status) == 0)
        // Normal exit with 0 → Nice
    else
        // Non-zero exit code → Bad

if (WIFSIGNALED(status))
    // Killed by signal → Bad
```

---

## Visual Diagrams

### Happy Path: Nice Function

```
┌─────────────────────────────────────────────────────────────┐
│                         TIMELINE                             │
├─────────────────────────────────────────────────────────────┤
│  Parent          │              │                 │         │
│    │             │              │                 │         │
│    │ fork()      │              │                 │         │
│    │─────────────┼──►Child      │                 │         │
│    │             │    │         │                 │         │
│    │ alarm(2)    │    │ f()     │                 │         │
│    │ ┌───────┐   │    │ runs... │                 │         │
│    │ │ 2 sec │   │    │         │                 │         │
│    │ │ timer │   │    │ exit(0) │                 │         │
│    │ └───────┘   │    ▼         │                 │         │
│    │             │   Done       │                 │         │
│    │◄────────────┼── waitpid() returns            │         │
│    │             │              │                 │         │
│    │ alarm(0)    │              │                 │         │
│    │ (cancel)    │              │                 │         │
│    │             │              │                 │         │
│    ▼             │              │                 │         │
│  return 1        │              │                 │         │
│  (Nice!)         │              │                 │         │
└─────────────────────────────────────────────────────────────┘
```

### Timeout Path: Infinite Loop

```
┌─────────────────────────────────────────────────────────────┐
│                         TIMELINE                             │
├─────────────────────────────────────────────────────────────┤
│  Parent          │              │        SIGALRM! │         │
│    │             │              │           │     │         │
│    │ fork()      │              │           │     │         │
│    │─────────────┼──►Child      │           │     │         │
│    │             │    │         │           │     │         │
│    │ alarm(2)    │    │ f()     │           │     │         │
│    │ ┌───────┐   │    │ while(1)│           │     │         │
│    │ │ 2 sec │   │    │ ......  │           │     │         │
│    │ │ timer │   │    │ ......  │   *RING*  ▼     │         │
│    │ │ ──────│───────────────────────►alarm_handler()       │
│    │ └───────┘   │    │ ......  │     │           │         │
│    │             │    │         │  kill(SIGKILL)  │         │
│    │             │    X─────────│◄────┘           │         │
│    │             │   Killed     │                 │         │
│    │◄────────────┼── waitpid() returns            │         │
│    │             │              │                 │         │
│    │ g_timed_out == 1           │                 │         │
│    ▼             │              │                 │         │
│  return 0        │              │                 │         │
│  (Bad - timeout) │              │                 │         │
└─────────────────────────────────────────────────────────────┘
```

### Crash Path: Segfault

```
┌─────────────────────────────────────────────────────────────┐
│                         TIMELINE                             │
├─────────────────────────────────────────────────────────────┤
│  Parent          │              │                 │         │
│    │             │              │                 │         │
│    │ fork()      │              │                 │         │
│    │─────────────┼──►Child      │                 │         │
│    │             │    │         │                 │         │
│    │ alarm(2)    │    │ f()     │                 │         │
│    │             │    │         │                 │         │
│    │             │    │ *p=NULL │                 │         │
│    │             │    │ *p = 42 │                 │         │
│    │             │    X ◄───────┼── SIGSEGV!      │         │
│    │             │   Crashed    │  (from kernel)  │         │
│    │             │              │                 │         │
│    │◄────────────┼── waitpid() returns            │         │
│    │             │              │                 │         │
│    │ WIFSIGNALED(status) == true                  │         │
│    │ WTERMSIG(status) == SIGSEGV                  │         │
│    ▼             │              │                 │         │
│  return 0        │              │                 │         │
│  (Bad - crashed) │              │                 │         │
└─────────────────────────────────────────────────────────────┘
```

---

## Summary

### The Algorithm

1. **Validate** input (function pointer not NULL)
2. **Fork** child process
3. **Child**: Execute function, exit(0) on success
4. **Parent**: Set up alarm timer, wait for child
5. **Analyze**: Check timeout flag and exit status

### Key Functions Used

| Function | Purpose |
|----------|---------|
| `fork()` | Create isolated child process |
| `alarm(n)` | Set n-second timeout |
| `sigaction()` | Register signal handler |
| `kill()` | Terminate child on timeout |
| `waitpid()` | Wait for child and get status |
| `strsignal()` | Convert signal number to string |

### Verbose Messages

| Situation | Message |
|-----------|---------|
| Success | `Nice function!` |
| Non-zero exit | `Bad function: exited with code <n>` |
| Signal death | `Bad function: <signal description>` |
| Timeout | `Bad function: timed out after <n> seconds` |

---

## Files Reference

- [my_sandbox.c](file:///home/jc/Videos/42e4/my04/sandbox/my_sandbox.c) - The annotated implementation
- [subject_6.txt](file:///home/jc/Videos/42e4/my04/sandbox/subject_6.txt) - The original subject/requirements
