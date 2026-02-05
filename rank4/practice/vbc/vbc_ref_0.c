#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

// We define three kinds of nodes we will create in the syntax tree
typedef struct node {
    enum { VAL, ADD, MULTI } type;   // What kind of node: number, + or *
    int val;                         // Only used when type == VAL
    struct node *left;               // left child
    struct node *right;              // right child
} node;

// Helper function to create a new node
node *new_node(int type, int val, node *l, node *r) {
    node *n = calloc(1, sizeof(node));
    if (!n) exit(1);                 // very simple error handling for memory failure
    n->type  = type;
    n->val   = val;
    n->left  = l;
    n->right = r;
    return n;
}

// Recursive function to free the whole tree
void free_tree(node *n) {
    if (!n) return;
    if (n->type != VAL) {            // if it's not a leaf (number)
        free_tree(n->left);
        free_tree(n->right);
    }
    free(n);
}

// Simple error reporting + exit
void error(char c) {
    if (c)
        printf("Unexpected token '%c'\n", c);
    else
        printf("Unexpected end of input\n");
    exit(1);
}

// ────────────────────────────────────────────────────────────────
//                        PARSER FUNCTIONS
// ────────────────────────────────────────────────────────────────
//
// We use the classic recursive descent approach with 3 levels of precedence:
//
//   expr   → term   ( ( "+" term )* )
//   term   → factor ( ( "*" factor )* )
//   factor → number | "(" expr ")"
//

// Lowest precedence: addition and subtraction (in our case only +)
// Returns a tree representing expr
node *parse_expr(char **s) {
    node *left = parse_term(s);     // parse the first term

    // Keep consuming + term + term + ...
    while (**s == '+') {
        (*s)++;                     // eat the '+'
        node *right = parse_term(s);
        left = new_node(ADD, 0, left, right);
        // Note: this makes + left-associative (which is correct)
    }

    return left;
}

// Medium precedence: multiplication
// Returns a tree representing term
node *parse_term(char **s) {
    node *left = parse_factor(s);   // parse the first factor

    // Keep consuming * factor * factor * ...
    while (**s == '*') {
        (*s)++;                     // eat the '*'
        node *right = parse_factor(s);
        left = new_node(MULTI, 0, left, right);
        // Again: left-associative multiplication (correct)
    }

    return left;
}

// Highest precedence: numbers and parenthesized expressions
// Returns a tree representing factor
node *parse_factor(char **s) {
    if (!**s)                       // end of string before we expected anything
        error(0);

    // Case 1: single digit number (0-9)
    if (isdigit(**s)) {
        int val = **s - '0';        // convert char '5' → int 5
        (*s)++;                     // move pointer forward
        return new_node(VAL, val, NULL, NULL);
    }

    // Case 2: parenthesis ( )
    if (**s == '(') {
        (*s)++;                     // eat '('
        node *expr = parse_expr(s); // parse full expression inside
        if (**s != ')')             // must have closing parenthesis
            error(**s ? **s : 0);
        (*s)++;                     // eat ')'
        return expr;                // the whole ( ... ) becomes one factor
    }

    // Anything else → syntax error
    error(**s);
    return NULL;                    // never reached (error() exits)
}

// Main parsing entry point
node *parse(char *input) {
    char *s = input;                // we will move this pointer
    node *result = parse_expr(&s);

    // After parsing we must have consumed ALL input
    if (*s != '\0') {
        error(*s);                  // leftover characters → error
    }

    return result;
}

// Evaluate the syntax tree recursively
int evaluate(node *n) {
    if (!n) return 0;

    switch (n->type) {
        case VAL:
            return n->val;
        case ADD:
            return evaluate(n->left) + evaluate(n->right);
        case MULTI:
            return evaluate(n->left) * evaluate(n->right);
    }
    return 0; // unreachable
}

int main(int argc, char **argv) {
    if (argc != 2) {
        return 1;
    }

    node *tree = parse(argv[1]);
    if (!tree) {          // actually parse() never returns NULL, but keeps style
        return 1;
    }

    printf("%d\n", evaluate(tree));

    free_tree(tree);
    return 0;
}