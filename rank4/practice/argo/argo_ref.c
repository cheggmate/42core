/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argo_my.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wchoo <wchoo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: Invalid date        by printf, mal       #+#    #+#             */
/*   Updated: 2026/02/02 15:18:19 by wchoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>     /* malloc(), calloc(), realloc(), free() */
#include <ctype.h>      /* isdigit() */
#include <string.h>     /* strdup() - for convenience in string allocation */
#include <stdio.h>

/* ========================================================================== */
/*                           DATA STRUCTURES                                  */
/* ========================================================================== */

/*
** json - A tagged union representing a JSON value
** 
** The 'type' field indicates which union member is active:
** - MAP:     A key-value object like {"name": "John", "age": 30}
** - INTEGER: A numeric value like 42 or -7
** - STRING:  A text value like "hello world"
*/
typedef struct json {
    enum {              /* Type tag - tells us which union member to use */
        MAP,            /* JSON object: {...} */
        INTEGER,        /* JSON number: 42 */
        STRING          /* JSON string: "hello" */
    } type;             /* The type of this JSON node */

    union {             /* Union - only one of these is valid at a time */
        struct {                    /* For MAP type: */
            struct pair *data;      /*   Array of key-value pairs */
            size_t      size;       /*   Number of pairs in the map */
        } map;
        int     integer;            /* For INTEGER type: the numeric value */
        char    *string;            /* For STRING type: the string (heap allocated) */
    };
} json;

/*
** pair - A key-value pair for JSON objects
** 
** Used inside MAP type json nodes. Each pair has:
** - key:   The property name (always a string)
** - value: The property value (can be any json type)
*/
typedef struct pair {
    char    *key;       /* Property name (heap allocated string) */
    json    value;      /* Property value (can be MAP, INTEGER, or STRING) */
} pair;

/* ========================================================================== */
/*                          FUNCTION DECLARATIONS                             */
/* ========================================================================== */

int     argo(json *dst, FILE *stream);          /* Main entry point */
int     parser(json *dst, FILE *stream);        /* Parse any JSON value */
int     parse_int(json *dst, FILE *stream);     /* Parse an integer */
int     parse_string(json *dst, FILE *stream);  /* Parse a string */
int     parse_map(json *dst, FILE *stream);     /* Parse a map/object */
void    free_json(json j);                      /* Free all memory in json tree */

/* ========================================================================== */
/*                           HELPER FUNCTIONS                                 */
/* ========================================================================== */

/*
** peek - Look at the next character without consuming it
** 
** Reads a character from stream, then puts it back using ungetc().
** This lets us "preview" what's coming next to decide how to parse.
** 
** @param stream: The file stream to peek from
** @return: The next character in stream (or EOF)
*/
int peek(FILE *stream)
{
    int c = getc(stream);   /* Read next character */
    ungetc(c, stream);      /* Put it back so next read will see it again */
    return (c);             /* Return what we saw */
}

/*
** unexpected - Print an error message for unexpected token
** 
** Called when we encounter a character we weren't expecting.
** Prints different messages for EOF vs regular characters.
** 
** @param stream: The stream (used to check current character)
*/
void unexpected(FILE *stream)
{
    if (peek(stream) != EOF)
        printf("unexpected token '%c'\n", peek(stream));  /* Show the bad char */
    else
        printf("unexpected end of input\n");              /* Reached EOF too early */
}

/*
** accept - Try to consume a specific character
** 
** If the next character matches 'c', consume it and return success.
** Otherwise, leave the stream unchanged and return failure.
** 
** @param stream: The file stream
** @param c: The character we're looking for
** @return: 1 if matched and consumed, 0 if not matched
*/
int accept(FILE *stream, char c)
{
    if (peek(stream) == c)      /* Check if next char matches */
    {
        (void)getc(stream);     /* Consume it (discard return value) */
        return (1);             /* Success - we found and ate the character */
    }
    return (0);                 /* Failure - character didn't match */
}

/*
** expect - Require a specific character (error if not found)
** 
** Like accept(), but prints an error if the character isn't found.
** Used when a character is mandatory (like ':' after a key in a map).
** 
** @param stream: The file stream
** @param c: The required character
** @return: 1 if found, 0 if not (and error printed)
*/
int expect(FILE *stream, char c)
{
    if (accept(stream, c))      /* Try to consume the character */
        return (1);             /* Success */
    unexpected(stream);          /* Print error message */
    return (0);                 /* Failure */
}

/* ========================================================================== */
/*                        MEMORY MANAGEMENT                                   */
/* ========================================================================== */

/*
** free_json - Recursively free all memory in a json structure
** 
** This function deallocates all heap memory used by a json value.
** For MAPs, it recursively frees all keys and nested values.
** 
** @param j: The json value to free (passed by value, not pointer!)
*/
void free_json(json j)
{
    switch (j.type)
    {
        case MAP:
            /* Free each key-value pair in the map */
            for (size_t i = 0; i < j.map.size; i++)
            {
                free(j.map.data[i].key);        /* Free the key string */
                free_json(j.map.data[i].value); /* Recursively free the value */
            }
            free(j.map.data);                   /* Free the array of pairs */
            break;
        case STRING:
            free(j.string);                     /* Free the string buffer */
            break;
        default:
            break;                              /* INTEGER has no heap memory */
    }
}

/* ========================================================================== */
/*                          PARSER FUNCTIONS                                  */
/* ========================================================================== */

/*
** parser - Parse any JSON value based on the first character
** 
** This is the main dispatch function. It peeks at the next character
** to determine what type of value is coming, then calls the appropriate
** specialized parser.
** 
** @param dst: Pointer to json struct to fill with parsed result
** @param stream: The file stream to parse from
** @return: 1 on success, -1 on error
*/
int parser(json *dst, FILE *stream)
{
    int c;

    c = peek(stream);               /* Look at first character */

    if (c == '"')                   /* Starts with quote? It's a string */
        return (parse_string(dst, stream));
    else if (isdigit(c) || c == '-') /* Digit or minus? It's a number */
        return (parse_int(dst, stream));
    else if (c == '{')              /* Opening brace? It's a map/object */
        return (parse_map(dst, stream));
    else                            /* Anything else is unexpected */
    {
        unexpected(stream);
        return (-1);
    }
}

/*
** parse_int - Parse an integer value
** 
** Uses fscanf with "%d" format to read an integer.
** Handles negative numbers automatically.
** 
** @param dst: Pointer to json struct to fill
** @param stream: The file stream to parse from
** @return: 1 on success, -1 on error
*/
int parse_int(json *dst, FILE *stream)
{
    int n;

    /* fscanf returns number of items successfully matched */
    if (fscanf(stream, "%d", &n) == 1)  /* Try to read an integer */
    {
        dst->type = INTEGER;            /* Set type tag */
        dst->integer = n;               /* Store the value */
        return (1);                     /* Success */
    }
    unexpected(stream);                 /* fscanf failed to match a number */
    return (-1);                        /* Error */
}

/*
** parse_string - Parse a JSON string (handles escape sequences)
** 
** A JSON string starts and ends with double quotes.
** Inside, backslash escapes the next character (\" for quote, \\ for backslash).
** 
** Example: "hello" -> hello
** Example: "say \"hi\"" -> say "hi"
** 
** @param dst: Pointer to json struct to fill
** @param stream: The file stream to parse from
** @return: 1 on success, -1 on error
*/
int parse_string(json *dst, FILE *stream)
{
    char    buffer[4096];   /* Temporary buffer for string content */
    char    c;              /* Current character being processed */
    int     i;              /* Position in buffer */

    if (!expect(stream, '"'))   /* Must start with opening quote */
        return (-1);

    i = 0;
    while (1)                   /* Read characters until closing quote */
    {
        c = getc(stream);       /* Read next character */

        if (c == EOF)           /* Unexpected end of file */
        {
            unexpected(stream);
            return (-1);
        }
        if (c == '"')           /* Found closing quote - done! */
            break;
        if (c == '\\')          /* Backslash = escape sequence */
        {
            c = getc(stream);   /* Get the escaped character */
            if (c == EOF)       /* File ended mid-escape */
            {
                unexpected(stream);
                return (-1);
            }
            /* The escaped character (after backslash) is used literally */
            /* This handles \" and \\ correctly */
        }
        buffer[i++] = c;        /* Store character in buffer */
    }
    buffer[i] = '\0';           /* Null-terminate the string */

    dst->type = STRING;                 /* Set type tag */
    dst->string = strdup(buffer);       /* Allocate and copy string */

    return (1);                         /* Success */
}

/*
** parse_map - Parse a JSON object/map
** 
** A map is: { "key1": value1, "key2": value2, ... }
** 
** Structure:
** - Starts with '{'
** - Contains zero or more key:value pairs
** - Pairs are separated by commas
** - Ends with '}'
** 
** @param dst: Pointer to json struct to fill
** @param stream: The file stream to parse from
** @return: 1 on success, -1 on error
*/
int parse_map(json *dst, FILE *stream)
{
    pair    *items;     /* Dynamic array of key-value pairs */
    size_t  size;       /* Current number of pairs */
    json    key;        /* Temporary storage for parsing keys */

    if (!expect(stream, '{'))   /* Must start with opening brace */
        return (-1);

    items = NULL;               /* Start with empty array */
    size = 0;

    /* Loop until we see closing brace */
    while (!accept(stream, '}'))
    {
        /* Grow the array by one slot */
        items = realloc(items, sizeof(pair) * (size + 1));

        /* --- Parse the key (must be a string) --- */
        if (parse_string(&key, stream) == -1)
        {
            free(items);        /* Clean up on error */
            return (-1);
        }

        /* --- Expect colon between key and value --- */
        if (!expect(stream, ':'))
        {
            free(key.string);   /* Clean up key */
            free(items);        /* Clean up array */
            return (-1);
        }

        /* --- Parse the value (can be any type) --- */
        if (parser(&items[size].value, stream) == -1)
        {
            free(key.string);   /* Clean up key */
            free(items);        /* Clean up array */
            return (-1);
        }

        items[size].key = key.string;   /* Store key in pair */
        size++;                         /* Increment pair count */

        /* After a pair, expect comma or closing brace */
        if (!accept(stream, ',') && peek(stream) != '}')
        {
            unexpected(stream);
            free(items);
            return (-1);
        }
    }

    /* Successfully parsed the map - fill in dst */
    dst->type = MAP;
    dst->map.size = size;
    dst->map.data = items;

    return (1);
}

/*
** argo - Main entry point for JSON parsing
** 
** This is the public function that users call.
** Simply delegates to the parser function.
** 
** @param dst: Pointer to json struct to fill with parsed result
** @param stream: The file stream containing JSON data
** @return: 1 on success, -1 on error
*/
int argo(json *dst, FILE *stream)
{
    return (parser(dst, stream));
}

/* ========================================================================== */
/*                        SERIALIZATION (OUTPUT)                              */
/* ========================================================================== */

/*
** serialize - Convert a json structure back to JSON text
** 
** Prints the json value in valid JSON format.
** Handles escaping for strings (backslash and quotes).
** 
** @param j: The json value to serialize (passed by value)
*/
void serialize(json j)
{
    switch (j.type)
    {
        case INTEGER:
            printf("%d", j.integer);        /* Just print the number */
            break;
        case STRING:
            putchar('"');                   /* Opening quote */
            for (int i = 0; j.string[i]; i++)
            {
                /* Escape backslashes and quotes */
                if (j.string[i] == '\\' || j.string[i] == '"')
                    putchar('\\');          /* Add escape backslash */
                putchar(j.string[i]);       /* Print the character */
            }
            putchar('"');                   /* Closing quote */
            break;
        case MAP:
            putchar('{');                   /* Opening brace */
            for (size_t i = 0; i < j.map.size; i++)
            {
                if (i != 0)
                    putchar(',');           /* Comma between pairs */
                /* Print key as string */
                serialize((json){.type = STRING, .string = j.map.data[i].key});
                putchar(':');               /* Colon separator */
                serialize(j.map.data[i].value);  /* Print value */
            }
            putchar('}');                   /* Closing brace */
            break;
    }
}

/* ========================================================================== */
/*                              TEST CODE                                     */
/* ========================================================================== */

int main(int argc, char **argv)
{
    if (argc != 2)
        return (1);

    /* Open the file specified in command line argument */
    char *filename = argv[1];
    FILE *stream = fopen(filename, "r");
    if (!stream)
        return (1);

    /* Parse the JSON from the file */
    json file;
    if (argo(&file, stream) != 1)
    {
        fclose(stream);
        return (1);
    }

    /* Output the parsed JSON back to stdout */
    serialize(file);
    printf("\n");

    /* Clean up */
    free_json(file);
    fclose(stream);

    return (0);
}
