/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vbc_my.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wchoo <wchoo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 0000/09/01 00:00:00 by                   #+#    #+#             */
/*   Updated: 2026/01/21 11:58:56 by wchoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>      /* printf() */
#include <stdlib.h>     /* calloc(), free() */
#include <ctype.h>      /* isdigit() */

/* ========================================================================== */
/*                           DATA STRUCTURES                                  */
/* ========================================================================== */

/*
** node - A node in the Abstract Syntax Tree (AST)
** 
** The expression is parsed into a tree structure where:
** - Leaf nodes (VAL) contain single-digit numbers
** - Internal nodes (ADD, MULTI) contain an operator and two children
** 
** Example: "3+4*5" becomes:
**            ADD
**           /   \
**         3     MULTI
**              /     \
**             4       5
*/
typedef struct node {
    enum {
        ADD,    /* '+' operator: result = left + right */
        MULTI,  /* '*' operator: result = left * right */
        VAL     /* Value: a single-digit number */
    } type;     /* Type of this node */

    int val;                    /* The number (only used when type == VAL) */
    struct node *l;             /* Left child (for ADD and MULTI) */
    struct node *r;             /* Right child (for ADD and MULTI) */
} node;

/* ========================================================================== */
/*                          HELPER FUNCTIONS                                  */
/* ========================================================================== */

/*
** new_node - Allocate and initialize a new node
** 
** @param n: A node structure with desired values (passed by value)
** @return: Pointer to heap-allocated copy, or NULL on failure
*/
node *new_node(node n)
{
    node *ret = calloc(1, sizeof(*ret));    /* Allocate zeroed memory */
    if (!ret)
        return (NULL);
    *ret = n;                               /* Copy the values */
    return (ret);
}

/*
** destroy_tree - Recursively free all nodes in the tree
** 
** @param n: Root of tree to destroy
*/
void destroy_tree(node *n)
{
    if (!n)
        return;
    if (n->type != VAL)                     /* If not a leaf node */
    {
        destroy_tree(n->l);                 /* Free left subtree */
        destroy_tree(n->r);                 /* Free right subtree */
    }
    free(n);                                /* Free this node */
}

/*
** unexpected - Print error message for unexpected token
** 
** @param c: The unexpected character (or '\0' for end of input)
*/
void unexpected(char c)
{
    if (c)
        printf("Unexpected token '%c'\n", c);
    else
        printf("Unexpected end of input\n");
}

/*
** accept - Try to consume a specific character
** 
** If current character matches 'c', advance the pointer and return true.
** 
** @param s: Pointer to the string pointer (double pointer for modification)
** @param c: Character to look for
** @return: 1 if matched and consumed, 0 otherwise
*/
int accept(char **s, char c)
{
    if (**s == c)
    {
        (*s)++;                             /* Advance past the character */
        return (1);
    }
    return (0);
}

/*
** expect - Require a specific character
** 
** Like accept(), but prints error if character not found.
** 
** @param s: Pointer to the string pointer
** @param c: Required character
** @return: 1 if found, 0 if not (error printed)
*/
int expect(char **s, char c)
{
    if (accept(s, c))
        return (1);
    unexpected(**s);
    return (0);
}

/* ========================================================================== */
/*                     RECURSIVE DESCENT PARSER                               */
/* ========================================================================== */

/*
** Grammar being parsed (operator precedence is built into the grammar):
** 
**   expr   → term (('+') term)*       // Addition (lowest precedence)
**   term   → factor (('*') factor)*   // Multiplication (higher precedence)
**   factor → digit | '(' expr ')'     // Numbers and parentheses (highest)
** 
** This grammar ensures that multiplication binds tighter than addition.
** Example: "3+4*5" is parsed as "3+(4*5)" = 23, not "(3+4)*5" = 35
*/

/* Forward declarations for mutual recursion */
static node *parse_expr_r(char **s);
static node *parse_term(char **s);
static node *parse_factor(char **s);

/*
** parse_factor - Parse a factor (number or parenthesized expression)
** 
** A factor is either:
** - A single digit (0-9)
** - An expression in parentheses
** 
** @param s: Pointer to current position in input string
** @return: AST node for the factor, or NULL on error
*/
static node *parse_factor(char **s)
{
    /* ----- Case 1: Digit ----- */
    if (isdigit((unsigned char)**s))
    {
        /* Create a VAL node with the digit's numeric value */
        node n = {.type = VAL, .val = **s - '0', .l = NULL, .r = NULL};
        (*s)++;                             /* Consume the digit */
        return (new_node(n));
    }

    /* ----- Case 2: Parenthesized expression ----- */
    if (accept(s, '('))
    {
        node *e = parse_expr_r(s);          /* Parse the inner expression */
        if (!e)
            return (NULL);
        if (!expect(s, ')'))                /* Expect closing paren */
        {
            destroy_tree(e);
            return (NULL);
        }
        return (e);
    }

    /* ----- Error: unexpected character ----- */
    unexpected(**s);
    return (NULL);
}

/*
** parse_term - Parse a term (sequence of factors with multiplication)
** 
** A term is: factor (* factor)*
** 
** This builds a left-associative tree:
** "2*3*4" becomes:
**        MULTI
**       /     \
**    MULTI     4
**   /     \
**  2       3
** 
** @param s: Pointer to current position in input string
** @return: AST node for the term, or NULL on error
*/
static node *parse_term(char **s)
{
    /* Parse the first factor */
    node *left = parse_factor(s);
    if (!left)
        return (NULL);

    /* Keep consuming '*' and more factors */
    while (accept(s, '*'))
    {
        node *right = parse_factor(s);
        if (!right)
        {
            destroy_tree(left);
            return (NULL);
        }
        /* Create MULTI node combining left and right */
        node n = {.type = MULTI, .l = left, .r = right};
        left = new_node(n);
        if (!left)
            return (NULL);
    }
    return (left);
}

/*
** parse_expr_r - Parse an expression (sequence of terms with addition)
** 
** An expression is: term (+ term)*
** 
** This builds a left-associative tree:
** "1+2+3" becomes:
**       ADD
**      /   \
**    ADD    3
**   /   \
**  1     2
** 
** @param s: Pointer to current position in input string
** @return: AST node for the expression, or NULL on error
*/
static node *parse_expr_r(char **s)
{
    /* Parse the first term */
    node *left = parse_term(s);
    if (!left)
        return (NULL);

    /* Keep consuming '+' and more terms */
    while (accept(s, '+'))
    {
        node *right = parse_term(s);
        if (!right)
        {
            destroy_tree(left);
            return (NULL);
        }
        /* Create ADD node combining left and right */
        node n = {.type = ADD, .l = left, .r = right};
        left = new_node(n);
        if (!left)
            return (NULL);
    }

    return (left);
}

/*
** parse_expr - Parse a complete expression (entry point)
** 
** This is the public parsing function. It:
** 1. Parses the expression
** 2. Checks that we consumed the entire input
** 
** @param s: The input string to parse
** @return: AST root on success, NULL on error
*/
node *parse_expr(char *s)
{
    char *p = s;                            /* Working pointer */
    node *ret = parse_expr_r(&p);

    if (!ret)
        return (NULL);

    /* Make sure we consumed entire input */
    if (*p)
    {
        unexpected(*p);                     /* There's leftover input */
        destroy_tree(ret);
        return (NULL);
    }

    return (ret);
}

/* ========================================================================== */
/*                          TREE EVALUATION                                   */
/* ========================================================================== */

/*
** eval_tree - Recursively evaluate the AST to get the result
** 
** For each node type:
** - ADD: evaluate both children and add results
** - MULTI: evaluate both children and multiply results
** - VAL: return the stored value
** 
** @param tree: The root of the AST to evaluate
** @return: The computed result
*/
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
    return (0);                             /* Should never reach here */
}

/* ========================================================================== */
/*                              MAIN FUNCTION                                 */
/* ========================================================================== */

int main(int argc, char **argv)
{
    if (argc != 2)
        return (1);

    /* Parse the expression from command line argument */
    node *tree = parse_expr(argv[1]);
    if (!tree)
        return (1);

    /* Evaluate and print the result */
    printf("%d\n", eval_tree(tree));

    /* Clean up */
    destroy_tree(tree);

    return (0);
}
