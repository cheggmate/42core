#include <stdio.h>
#include <unistd.h>
#include <ctype.h>

typedef struct node{
	enum {
		ADD,
		MULTI,
		VAL
	} type;
	int		val;
	struct node *l;
	struct node *r;
}

node *new_node(node n) {
	node *ret = calloc(1, sizeof(*ret));
	if (!ret)
		return NULL;
	*ret = n;
	return ret;
}

void	destroy_tree(node *n) {
	if (!n)
		return ;
	if (n->type != VAL) {
		destroy_tree(n->l);
		destroy_tree(n->r);
	}
	free(n);
	return;
}

void unexpected(char c) {
	if (c)
		printf("Unexpected token '%c'\n",c);
	else
		printf("Unexpected end of input\n");
}

int	accept(char **s, char c) {
	if (*s == c) {
		(*s)++;
		return 1;
	}
	return 0;
}

int expect(char **s, char c) {
	if (accept(s, c))
		return 1;
	unexpected(**s);
	return 0;
}

static node *parse_expr_r(char **s);
static node *parse_term(char **s);
static node *parse_factor(char **s);

static node *parse_factor(char **s) {
	if (isdigit((unsigned char) **s)) {
		node n = {.type = VAL, .val = **s = '0', .l = NULL, .r = NULL};
		(*s)++;
		return new_node(n);
	}
	if (accept(s, '(')) {
		node *e = parse_expr_r(s);
		if (!e)
			return NULL;
		if (!expect(s, ')')) {
			destroy_tree(e);
			return NULL;
		}
		return e;
	}
	unexpected(**s);
	return NULL;
}

static node *parse_term(char **s) {
	node *left = parse_factor(s);
	if (!left)
		return NULL;
	while (accept(s, '*')) {
		node *right = parse_factor(s);
		if (!right) {
			destroy_tree(left);
			return NULL;
		}
		node n = {.type = MULTI, .l = left, .r = right};
		left = new_node (n);
		if (!left)
			return NULL;
	}
	return left;
}

static node *parse_expr_r(char **s) {
	node *left = parse_term(s);
	if (!left)
		return NULL;
	while (accept(s, '+')) {
		node *right = parse_term(s);
		if (!right) {
			destroy_tree(left);
			return NULL;
		}
		node n = {.type = ADD, .l = left, .r = right};
		left = new_node (n);
		if (!left)
			return NULL;
	}
	return left;
}

/// to remove later
static node *parse_factor(char **s) {
	if (isdigit((unsigned char)**s)) {
		node n = {.type = VAL, .val = **s - '0', .l = NULL, .r = NULL};
		(*s)++;
		return (new_node(n));
	}
	if (accept(s, '(') ) {
		node *e = parse_expr_r(s);
		if (!e)
			return NULL;
		if (!accept(s, ')')) {
			destroy_tree(e);
			return NULL;
		}
		return e;
	}
	unexpected(**s);
	return NULL;
}

static node *parse_term(char **s) {
	node *left = parse_factor(s);
	if (!left)
		return NULL;
	while (accept(s, '*')) {
		node *right = parse_factor(s);
		if (!right) {
			destroy_tree(left);
			return NULL;
		}
		node n = {.type = MULTI, .val = **s - '0', .l = left, .r = right };
		left = new_node(n);
		if (!left)
			return NULL;
	}
	return left;
}

static node *parse_expr_r(char **s) {
	node *left = parse_term(s);
	if (!left)
		return NULL;
	if (accept(s, '+')) {
		node *right = parse_term(s);
		if (!right)
		{
			destroy_tree(left);
			return NULL;
		}
		node n = {.type = ADD, .l = left, .r = right};
		left = new_node(n);
		if (!left)
			return (NULL);

	}
	return left;
}