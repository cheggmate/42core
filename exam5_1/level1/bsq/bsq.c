#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <sys/types.h>

typedef struct s_map
{
    char **lines;
    int declared_lines;
    int line_length;

    char full;
    char empty;
    char obstacle;

} t_map;

typedef struct s_square
{
    int size;
    int top_x;
    int left_y;
} t_square;

void initi_map(t_map *map)
{
    map->lines = 0;
    map->declared_lines = 0;
    map->line_length = 0;
    map->empty = 0;
    map->full = 0;
    map->obstacle = 0;
}

int is_printable(char c)
{
    if (c == '\n' || c < 32 || c == 127)
        return -1;
    else
        return 0;
}

// Robust left-to-right parser for space-separated headers (e.g., "9 . o x\n")
int parse_header(char *line, t_map **map)
{
    int i = 0;

    // 1. Parse the number of lines
    long num = 0;
    while (line[i] >= '0' && line[i] <= '9')
    {
        num = num * 10 + (line[i] - '0');
        if (num > INT_MAX)
            return -1;
        i++;
    }

    if (i == 0 || num <= 0)
        return -1;

    (*map)->declared_lines = num;

    // 2. Read "empty" character
    if (line[i++] != ' ') return -1;
    (*map)->empty = line[i++];

    // 3. Read "obstacle" character
    if (line[i++] != ' ') return -1;
    (*map)->obstacle = line[i++];

    // 4. Read "full" character
    if (line[i++] != ' ') return -1;
    (*map)->full = line[i++];

    // Skip trailing carriage return if file has Windows/DOS line endings
    if (line[i] == '\r')
        i++;

    // 5. Must end with newline or null terminator
    if (line[i] != '\n' && line[i] != '\0')
        return -1;

    // 6. Validate characters are printable and completely unique
    if (is_printable((*map)->empty) != 0 || is_printable((*map)->obstacle) != 0 || is_printable((*map)->full) != 0)
        return -1;

    if ((*map)->empty == (*map)->obstacle || (*map)->empty == (*map)->full || (*map)->full == (*map)->obstacle)
        return -1;

    return 0;
}

int parse_map_lines(t_map **map)
{
    int i = 0;
    int j = 0;

    if ((*map)->declared_lines <= 0 || !(*map)->lines || !(*map)->lines[0])
        return -1;

    while ((*map)->lines[0][j])
        j++;

    (*map)->line_length = j;
    if (j == 0) // At least one box required [cite: 12]
        return -1;

    while (i < (*map)->declared_lines)
    {
        j = 0;
        while ((*map)->lines[i][j])
        {
            // Only allow characters introduced in the header [cite: 14]
            if ((*map)->lines[i][j] != (*map)->empty && (*map)->lines[i][j] != (*map)->obstacle)
                return -1;
            j++;
        }
        // All lines must have identical lengths [cite: 11]
        if (j != (*map)->line_length)
            return -1;
        i++;
    }
    return 0;
}

int process_file(char *filename, t_map **map)
{
    FILE *file;

    if (filename == NULL)
        file = stdin;
    else
    {
        file = fopen(filename, "r");
        if (!file)
            return -1;
    }

    size_t len = 0;
    char *line = NULL;
    
    if (getline(&line, &len, file) == -1)
    {
        free(line);
        if (filename != NULL) fclose(file);
        return -1;
    }

    if (parse_header(line, map) != 0)
    {
        free(line);
        if (filename != NULL) fclose(file);
        return -1;
    }

    (*map)->lines = calloc((*map)->declared_lines, sizeof *(*map)->lines);
    if (!(*map)->lines)
    {
        free(line);
        if (filename != NULL) fclose(file);
        return -1;
    }

    int i = 0;
    ssize_t n_read;
    int error = 0;
    while ((n_read = getline(&line, &len, file)) != -1)
    {
        if (i >= (*map)->declared_lines)
        {
            error = -1;
            break;
        }
        
        // Clean up trailing newlines and potential carriage returns safely
        if (n_read > 0 && line[n_read - 1] == '\n')
            line[--n_read] = '\0';
        if (n_read > 0 && line[n_read - 1] == '\r')
            line[--n_read] = '\0';

        (*map)->lines[i] = strdup(line);
        i++;
    }
    free(line);
    if (filename != NULL) 
        fclose(file);

    if (error == -1 || i != (*map)->declared_lines)
        return -1;

    if (parse_map_lines(map) != 0)
        return -1;

    return 0;
}

void print_map(t_map *map)
{
    int i = 0;
    char **str = map->lines;

    while (i < map->declared_lines)
    {
        printf("%s\n", str[i]);
        i++;
    }
}

void free_map(t_map *map)
{
    if (!map) return;
    if (map->lines)
    {
        for (int i = 0; i < map->declared_lines; i++)
        {
            if (map->lines[i])
                free(map->lines[i]);
        }
        free(map->lines);
    }
    free(map);
}

int min3(int a, int b, int c)
{
    int min = a;
    if (b < min) min = b;
    if (c < min) min = c;
    return min;
}

t_square solve_bsq_dp(t_map *map)
{
    t_square best;
    best.left_y = 0, best.top_x = 0, best.size = 0;

    int height = map->declared_lines;
    int width = map->line_length;

    int **dp = malloc(height * sizeof(int *));
    for (int i = 0; i < height; i++)
        dp[i] = malloc(width * sizeof(int));

    int i = 0;
    while (i < height)
    {
        int j = 0;
        while (j < width)
        {
            if (map->lines[i][j] == map->obstacle)
                dp[i][j] = 0;
            else if (i == 0 || j == 0)
                dp[i][j] = 1;
            else
                dp[i][j] = 1 + min3(dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]);

            if (dp[i][j] > best.size)
            {
                best.size = dp[i][j];
                best.top_x = i - dp[i][j] + 1;
                best.left_y = j - dp[i][j] + 1;
            }
            j++;
        }
        i++;
    }

    for (int k = 0; k < height; k++)
        free(dp[k]);
    free(dp);

    return best;
}

void apply_square(t_map *map, t_square sq)
{
    if (sq.size <= 0)
        return;

    int x = 0;
    while (x < sq.size)
    {
        int y = 0;
        while (y < sq.size)
        {
            int xx = sq.top_x + x;
            int yy = sq.left_y + y;
            map->lines[xx][yy] = map->full;
            y++;
        }
        x++;
    }
}

void run_bsq(char *filename)
{
    t_map *map = malloc(sizeof(t_map));
    if (!map) return;
    
    initi_map(map);
    if (process_file(filename, &map) == 0)
    {
        t_square best = solve_bsq_dp(map);
        apply_square(map, best);
        print_map(map);
    }
    else
    {
        fprintf(stderr, "map error\n"); // Print error to stderr with line break 
    }
    free_map(map);
}

int main(int argc, char **argv)
{
    if (argc == 1)
    {
        // Fallback to standard input if no file arguments exist [cite: 10]
        run_bsq(NULL);
    }
    else
    {
        // Safely loop through multiple file arguments [cite: 9, 18]
        for (int i = 1; i < argc; i++)
        {
            run_bsq(argv[i]);
        }
    }
    return 0;
}