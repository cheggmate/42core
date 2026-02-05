# VBC (Very Basic Calculator) Explanation (`my_vbc.c`)

A detailed step-by-step guide explaining how `my_vbc.c` implements an expression parser and evaluator.

---

## Table of Contents

1. [What is VBC?](#what-is-vbc)
2. [The Subject Requirements](#the-subject-requirements)
3. [Key Concepts](#key-concepts)
4. [Step-by-Step Code Walkthrough](#step-by-step-code-walkthrough)
5. [Visual Diagrams](#visual-diagrams)
6. [Summary](#summary)

---

## What is VBC?

**VBC** (Very Basic Calculator) is an arithmetic expression evaluator that:

1. Parses mathematical expressions with `+`, `*`, and `()`
2. Respects operator precedence (`*` before `+`)
3. Builds an Abstract Syntax Tree (AST)
4. Evaluates the tree to compute the result

```bash
./vbc '3+4*5'     # Output: 23 (not 35, because * is done first)
./vbc '(3+4)*5'   # Output: 35 (parentheses override precedence)
```

---

## The Subject Requirements

| Requirement | Description |
|-------------|-------------|
| **Operators** | `+` (addition), `*` (multiplication) |
| **Grouping** | Parentheses `()` |
| **Values** | Single digits 0-9 only |
| **Error handling** | Print `Unexpected token 'X'` or `Unexpected end of input` |
| **No whitespace** | Spaces not handled |

---

## Key Concepts

### 1. Operator Precedence

Multiplication has higher precedence than addition:

| Expression | Interpretation | Result |
|------------|----------------|--------|
| `3+4*5` | `3 + (4*5)` | 23 |
| `3*4+5` | `(3*4) + 5` | 17 |

### 2. The Grammar

The precedence is encoded in a **grammar**:

```
expr   → term   (('+') term)*     ← Addition (lowest precedence)
term   → factor (('*') factor)*   ← Multiplication (higher)
factor → digit | '(' expr ')'     ← Values and parens (highest)
```

By having `expr` call `term`, and `term` call `factor`, we ensure multiplication "groups" before addition.

### 3. Recursive Descent Parsing

Each grammar rule becomes a function:
- `parse_expr()` → handles `+`
- `parse_term()` → handles `*`
- `parse_factor()` → handles digits and `()`

These functions call each other recursively.

---

## Step-by-Step Code Walkthrough

### Phase 1: The AST Node Structure

```c
typedef struct node {
    enum { ADD, MULTI, VAL } type;
    int val;                    // For VAL nodes
    struct node *l;             // Left child
    struct node *r;             // Right child
} node;
```

Three types of nodes:
- **VAL**: A leaf node containing a number
- **ADD**: An internal node representing `left + right`
- **MULTI**: An internal node representing `left * right`

---

### Phase 2: Parsing Factors (Digits and Parentheses)

```c
static node *parse_factor(char **s)
{
    if (isdigit(**s))
    {
        node n = {.type = VAL, .val = **s - '0'};
        (*s)++;
        return (new_node(n));
    }
    if (accept(s, '('))
    {
        node *e = parse_expr_r(s);   // Recursively parse expression
        expect(s, ')');              // Must have closing paren
        return (e);
    }
    unexpected(**s);
    return (NULL);
}
```

A factor is:
- A digit: create a VAL node
- `(expr)`: recursively parse the inner expression

---

### Phase 3: Parsing Terms (Multiplication)

```c
static node *parse_term(char **s)
{
    node *left = parse_factor(s);    // Get first factor
    
    while (accept(s, '*'))           // While we see '*'
    {
        node *right = parse_factor(s);
        node n = {.type = MULTI, .l = left, .r = right};
        left = new_node(n);          // Build tree left-to-right
    }
    return (left);
}
```

Builds a left-associative tree for multiplication:
- `2*3*4` → `((2*3)*4)`

---

### Phase 4: Parsing Expressions (Addition)

```c
static node *parse_expr_r(char **s)
{
    node *left = parse_term(s);      // Get first term
    
    while (accept(s, '+'))           // While we see '+'
    {
        node *right = parse_term(s);
        node n = {.type = ADD, .l = left, .r = right};
        left = new_node(n);
    }
    return (left);
}
```

Identical structure to `parse_term`, but for addition.

---

### Phase 5: Evaluating the Tree

```c
int eval_tree(node *tree)
{
    switch (tree->type)
    {
        case ADD:
            return (eval_tree(tree->l) + eval_tree(tree->r));
        case MULTI:
            return (eval_tree(tree->l) * eval_tree(tree->r));
        case VAL:
            return (tree->val);
    }
}
```

Simple recursive evaluation:
- For operators: evaluate children, apply operator
- For values: return the stored number

---

## Visual Diagrams

### Example: Parsing "3+4*5"

**Step 1: parse_expr_r starts, calls parse_term**

```
parse_expr_r("3+4*5")
  └── parse_term("3+4*5")
        └── parse_factor("3+4*5") → VAL(3), pos moves to "+4*5"
        └── no '*' found, return VAL(3)
```

**Step 2: parse_expr_r sees '+', calls parse_term again**

```
parse_expr_r continues with "+4*5"
  └── accept('+') → success, pos moves to "4*5"
  └── parse_term("4*5")
        └── parse_factor("4*5") → VAL(4), pos moves to "*5"
        └── accept('*') → success, pos moves to "5"
        └── parse_factor("5") → VAL(5), pos moves to ""
        └── no more '*', return MULTI(4,5)
```

**Step 3: Final tree**

```
         ADD
        /   \
     VAL(3)  MULTI
            /     \
         VAL(4)  VAL(5)

eval_tree:
  ADD → eval(left) + eval(right)
      → 3 + (4 * 5)
      → 3 + 20
      → 23
```

### Tree for "(3+4)*5"

```
Input: (3+4)*5

Parsing:
1. parse_factor sees '('
2. parse_expr_r("3+4") builds ADD(3,4)
3. expect ')' consumes ')'
4. parse_term sees '*', gets factor 5
5. Result: MULTI(ADD(3,4), 5)

        MULTI
       /     \
     ADD     VAL(5)
    /   \
 VAL(3) VAL(4)

eval_tree:
  MULTI → (3 + 4) * 5
        → 7 * 5
        → 35
```

### Why Precedence Works

The grammar structure creates the precedence:

```
parse_expr (addition)
    │
    └── calls parse_term (multiplication)
                │
                └── calls parse_factor (numbers/parens)
```

**Lower functions are called first**, so they "bind tighter"!

When parsing `3+4*5`:
1. `parse_expr` gets `3` from `parse_term`
2. Sees `+`, needs another term
3. `parse_term` gets `4`, sees `*`, gets `5`, builds `MULTI(4,5)`
4. `parse_expr` combines: `ADD(3, MULTI(4,5))`

---

## Summary

### The Algorithm

1. **Parse** expression into AST using recursive descent
2. **Respect precedence** by grammar structure
3. **Evaluate** tree recursively

### Function Call Hierarchy

```
parse_expr (handles +)
    │
    ├── parse_term (handles *)
    │       │
    │       └── parse_factor (handles digits and parens)
    │               │
    │               └── parse_expr (for parenthesized expressions)
    │
    └── parse_term ...
```

### Error Handling

| Error | Message |
|-------|---------|
| Unexpected char | `Unexpected token 'X'` |
| Premature end | `Unexpected end of input` |
| Leftover input | `Unexpected token 'X'` (first extra char) |

---

## Files Reference

- [my_vbc.c](file:///home/jc/Videos/42e4/my04/vbc/my_vbc.c) - The annotated implementation
- [subject_6.txt](file:///home/jc/Videos/42e4/my04/vbc/subject_6.txt) - The original subject/requirements
