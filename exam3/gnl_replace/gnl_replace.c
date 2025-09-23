#include "gnl_replace.h"

int chk_str(char *chk, char *replace, int s_len) {
    int i;
    int c_len = strlen(chk);

    if (c_len < s_len)
        return 1;

    for (i = 0; i < s_len; i++) {
        if (chk[i] != replace[i])
            return chk[i] - replace[i];
    }
    return 0;
}

void get_next_line(int fd, char *x) {
    static char s[9999999] = {'\0'};
    int j;
    int k = 0;
    int r;
    int x_len = strlen(x);
    if (fd < 0 || BUFFER_SIZE <= 0)
        return;

    while (1) {
        j = read(fd, s + k, BUFFER_SIZE);
        if (j <= 0)
            break;

        k += j;
        s[k] = '\0';

        char *newline_pos = strchr(s, '\n');    // Find the first newline in the buffer
        if (newline_pos) {
            int line_len = newline_pos - s;  // Length of the line before the newline
            for (r = 0; r < line_len - x_len + 1; r++) {
                if (s[r] == x[0] && chk_str(&s[r], x, x_len) == 0) {    // Try to match the pattern 'x' in the line
                    // Replace matched part with asterisks
                    for (int a = 0; a < x_len; a++) {
                        s[r + a] = '*';
                    }
                }
            }

            write(1, s, line_len);   // Print the modified line
			write(1, "\n", 1);
            memmove(s, s + line_len + 1, k - line_len - 1); // Shift the rest of the string to remove the processed line
            k -= (line_len + 1);  // Update the buffer size after the shift
        }
    }
}

int main(int argc, char **argv) {
    if (argc != 2)
        return 1;
    get_next_line(0, argv[1]);
    return 0;
}
