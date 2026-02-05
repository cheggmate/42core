# Argo Explanation (`my_argo.c`)

A detailed step-by-step guide explaining how `my_argo.c` implements a JSON parser.

---

## Table of Contents

1. [What is Argo?](#what-is-argo)
2. [The Subject Requirements](#the-subject-requirements)
3. [Key Concepts](#key-concepts)
4. [Data Structures](#data-structures)
5. [Step-by-Step Code Walkthrough](#step-by-step-code-walkthrough)
6. [Visual Diagram](#visual-diagram)
7. [Summary](#summary)

---

## What is Argo?

**Argo** is a JSON parser that reads JSON text from a file and builds an Abstract Syntax Tree (AST) representation. It supports three JSON types:

| Type | JSON Example | C Representation |
|------|--------------|------------------|
| **Integer** | `42` | `int` |
| **String** | `"hello"` | `char *` |
| **Map** | `{"key": value}` | Array of key-value pairs |

---

## The Subject Requirements

| Requirement | Description |
|-------------|-------------|
| **Function** | `int argo(json *dst, FILE *stream)` |
| **Input** | FILE stream containing JSON data |
| **Output** | Returns `1` on success, `-1` on error |
| **Allowed Functions** | `getc`, `ungetc`, `printf`, `malloc`, `calloc`, `realloc`, `free`, `isdigit`, `fscanf`, `write` |
| **Supported Types** | Numbers (int), Strings, Maps/Objects |
| **Special Handling** | Escape sequences `\"` and `\\` in strings |
| **No Whitespace** | Spaces are treated as invalid tokens |

---

## Key Concepts

### 1. Recursive Descent Parsing

The parser uses a technique called **recursive descent parsing**:
- Each JSON type has its own parsing function
- Functions call each other recursively for nested structures
- The parser "descends" into nested structures and returns back up

```
parse_map() calls parser() for values
    └──> parser() might call parse_map() again for nested objects
            └──> and so on...
```

### 2. Lookahead with `peek()`

The parser needs to see what's coming next without consuming the character:

```c
int peek(FILE *stream)
{
    int c = getc(stream);   // Read character
    ungetc(c, stream);      // Put it back
    return c;               // Return what we saw
}
```

### 3. Tagged Union for JSON Values

A **tagged union** combines:
- An `enum` tag indicating the active type
- A `union` of possible values (only one valid at a time)

```c
typedef struct json {
    enum { MAP, INTEGER, STRING } type;  // The tag
    union {                              // The value (one of these)
        struct { ... } map;
        int integer;
        char *string;
    };
} json;
```

---

## Data Structures

### The `json` Type

```
json structure:
┌─────────────────────────────────────────────────────┐
│ type: enum { MAP, INTEGER, STRING }                 │
├─────────────────────────────────────────────────────┤
│ union {                                             │
│   ┌─── if type == MAP ────────────────────────────┐ │
│   │ map.data: pair* ──► [pair, pair, pair, ...]   │ │
│   │ map.size: number of pairs                     │ │
│   └───────────────────────────────────────────────┘ │
│   ┌─── if type == INTEGER ────────────────────────┐ │
│   │ integer: int value (e.g., 42)                 │ │
│   └───────────────────────────────────────────────┘ │
│   ┌─── if type == STRING ─────────────────────────┐ │
│   │ string: char* ──► "hello world"               │ │
│   └───────────────────────────────────────────────┘ │
│ }                                                   │
└─────────────────────────────────────────────────────┘
```

### The `pair` Type (for Maps)

```
pair structure (used inside MAP):
┌─────────────────────────────────────┐
│ key:   char* ──► "propertyName"     │
│ value: json  ──► (recursive struct) │
└─────────────────────────────────────┘
```

---

## Step-by-Step Code Walkthrough

### Phase 1: Entry Point

```c
int argo(json *dst, FILE *stream)
{
    return (parser(dst, stream));
}
```

Simply delegates to the main parser function.

---

### Phase 2: Main Parser Dispatch

```c
int parser(json *dst, FILE *stream)
{
    int c = peek(stream);              // Look at first character
    
    if (c == '"')                      // String starts with quote
        return (parse_string(dst, stream));
    else if (isdigit(c) || c == '-')   // Number starts with digit or minus
        return (parse_int(dst, stream));
    else if (c == '{')                 // Map starts with brace
        return (parse_map(dst, stream));
    else
    {
        unexpected(stream);
        return (-1);
    }
}
```

**Decision tree:**
```
             peek()
               │
     ┌─────────┼─────────┐
     │         │         │
    '"'    digit/'-'    '{'
     │         │         │
     ▼         ▼         ▼
  STRING   INTEGER      MAP
```

---

### Phase 3: Parsing Integers

```c
int parse_int(json *dst, FILE *stream)
{
    int n;
    
    if (fscanf(stream, "%d", &n) == 1)  // Try to read integer
    {
        dst->type = INTEGER;             // Set type tag
        dst->integer = n;                // Store value
        return (1);
    }
    unexpected(stream);
    return (-1);
}
```

Uses `fscanf` with `%d` format to handle:
- Positive numbers: `42`
- Negative numbers: `-7`
- Multi-digit numbers: `12345`

---

### Phase 4: Parsing Strings

```c
int parse_string(json *dst, FILE *stream)
{
    char buffer[4096];
    int i = 0;
    
    if (!expect(stream, '"'))           // Must start with quote
        return (-1);
    
    while (1)
    {
        char c = getc(stream);
        
        if (c == EOF)                   // Unexpected end
            return error;
        if (c == '"')                   // End of string
            break;
        if (c == '\\')                  // Escape sequence
            c = getc(stream);           // Get escaped character
        
        buffer[i++] = c;                // Store character
    }
    buffer[i] = '\0';
    
    dst->type = STRING;
    dst->string = strdup(buffer);       // Allocate copy
    return (1);
}
```

**Escape sequence handling:**
```
Input: "say \"hi\""
       │   ││  ││
       │   │└──┘│
       │   │ hi │
       │   └────┘
       └─ say "hi"
       
\" → literal "
\\ → literal \
```

---

### Phase 5: Parsing Maps

```c
int parse_map(json *dst, FILE *stream)
{
    pair *items = NULL;
    size_t size = 0;
    
    if (!expect(stream, '{'))           // Must start with {
        return (-1);
    
    while (!accept(stream, '}'))        // Until closing }
    {
        // Grow array
        items = realloc(items, sizeof(pair) * (size + 1));
        
        // Parse key (must be string)
        json key;
        parse_string(&key, stream);
        
        // Expect colon
        expect(stream, ':');
        
        // Parse value (any type - recursive!)
        parser(&items[size].value, stream);
        
        items[size].key = key.string;
        size++;
        
        // Expect comma or closing brace
        if (!accept(stream, ',') && peek(stream) != '}')
            return error;
    }
    
    dst->type = MAP;
    dst->map.data = items;
    dst->map.size = size;
    return (1);
}
```

**Map structure:**
```
Input: {"name":"John","age":30}

Parsed as:
┌───────────────────────────────────────┐
│ type: MAP                             │
│ map.size: 2                           │
│ map.data: ─────────┐                  │
│                    ▼                  │
│   ┌────────────────────────────────┐  │
│   │ [0] key: "name"                │  │
│   │     value: {STRING, "John"}    │  │
│   ├────────────────────────────────┤  │
│   │ [1] key: "age"                 │  │
│   │     value: {INTEGER, 30}       │  │
│   └────────────────────────────────┘  │
└───────────────────────────────────────┘
```

---

### Phase 6: Memory Management

```c
void free_json(json j)
{
    switch (j.type)
    {
        case MAP:
            for (size_t i = 0; i < j.map.size; i++)
            {
                free(j.map.data[i].key);        // Free each key
                free_json(j.map.data[i].value); // Recursively free values
            }
            free(j.map.data);                   // Free the array
            break;
        case STRING:
            free(j.string);                     // Free string buffer
            break;
        default:
            break;                              // INTEGER has no heap memory
    }
}
```

---

## Visual Diagram

### Parsing Flow for Nested JSON

```
Input: {"user":{"name":"John","id":42}}

Step 1: parse_map() sees '{'
        │
        └─▶ Step 2: parse_string() reads "user"
        │
        └─▶ Step 3: expect(:)
        │
        └─▶ Step 4: parser() sees '{' → recursive parse_map()
                    │
                    └─▶ Step 5: parse_string() reads "name"
                    │
                    └─▶ Step 6: expect(:)
                    │
                    └─▶ Step 7: parser() sees '"' → parse_string() reads "John"
                    │
                    └─▶ Step 8: accept(',')
                    │
                    └─▶ Step 9: parse_string() reads "id"
                    │
                    └─▶ Step 10: expect(:)
                    │
                    └─▶ Step 11: parser() sees '4' → parse_int() reads 42
                    │
                    └─▶ Step 12: accept('}') ─ inner map done
        │
        └─▶ Step 13: accept('}') ─ outer map done

Result Tree:
    MAP
     │
     └── "user" : MAP
                   │
                   ├── "name" : STRING "John"
                   │
                   └── "id" : INTEGER 42
```

---

## Summary

### The Algorithm in Simple Terms

1. **Look at first character** to determine type
2. **Integer**: Use `fscanf` to read number
3. **String**: Read characters until closing quote, handle escapes
4. **Map**: Loop reading key:value pairs until `}`
5. **Recurse** for nested values (maps can contain maps, etc.)

### Key Helper Functions

| Function | Purpose |
|----------|---------|
| `peek()` | Look at next character without consuming |
| `accept()` | Try to consume a specific character |
| `expect()` | Require a specific character (error if not found) |
| `unexpected()` | Print appropriate error message |

### Error Handling

- Returns `-1` on any parsing error
- Prints descriptive message: `Unexpected token 'X'` or `Unexpected end of input`
- Memory is cleaned up on error (though shown simplified here)

---

## Files Reference

- [my_argo.c](file:///home/jc/Videos/42e4/my04/argo/my_argo.c) - The annotated implementation
- [subject_argo_1.txt](file:///home/jc/Videos/42e4/my04/argo/subject_argo_1.txt) - The original subject/requirements
