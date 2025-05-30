#include "../get_next_line.h"
#include <assert.h>
#include <string.h>
#include <stdio.h>

int	main(void)
{
	//---------- Tests, read from file
	// Test 1: Read one sentence.
	printf("Test 1: Read one sentence\n");
	int		fd1;
	if (access("tests/example_simple.txt", F_OK) == -1)
	{
		printf("file doesnt exist, are you running the test from 'get_next_line'?\n");
		fd1 = open("example_simple.txt", O_RDONLY);
	}
	else
	
		fd1 = open("tests/example_simple.txt", O_RDONLY);
	printf("fd in test is %d\n", fd1);
	char	*b_read1 = get_next_line(fd1);
	printf("b_read: '%s'\n", b_read1);
	char	output1[] = "Hello world!\n";
	assert(strcmp(b_read1, output1) == 0);
	free(b_read1);
	printf("\n-------\n");

	// Test 2: Read one paragraph.
	// printf("Test 2: Read one paragraph\n");
	// int		fd2;
	// if (access("tests/example_longsentence.txt", F_OK) == -1)
	// {
	// 	printf("file doesnt exist, are you running the test from 'get_next_line'?\n");
	// 	fd2 = open("example_longsentence.txt", O_RDONLY);
	// }
	// else
	// 	fd2 = open("tests/example_longsentence.txt", O_RDONLY);
	// char	*b_read2 = get_next_line(fd2);
	// printf("b_read: '%s'\n", b_read2);
	// char	output2[] = "However little known the feelings or views of such a man may be on his first entering a neighbourhood, this truth is so well fixed in the minds of the surrounding families, that he is considered as the rightful property of some one or other of their daughters.";
	// assert(strcmp(b_read2, output2) == 0);
	// free(b_read2);
	// printf("\n-------\n");

	// Test 3: Read empty input
	printf("Test 3:  Read empty input\n");
	int		fd3;
	if (access("tests/example_emptyfile.txt", F_OK) == -1)
	{
		printf("file doesnt exist, are you running the test from 'get_next_line'?\n");
		fd3 = open("example_emptyfile.txt", O_RDONLY);
	}
	else
		fd3 = open("tests/example_emptyfile.txt", O_RDONLY);
	char	*b_read3 = get_next_line(fd3);
	printf("b_read: '%s'\n", b_read3);
	assert(!b_read3);
	free(b_read3);
	printf("\n-------\n");

	// Test 4: Read contents with no terminating \n char
	printf("Test 4: Read contents with no terminating \\n char\n");
	int		fd4;
	if (access("tests/example_nonewline.txt", F_OK) == -1)
	{
		printf("file doesnt exist, are you running the test from 'get_next_line'?\n");
		fd4 = open("example_nonewline.txt", O_RDONLY);
	}
	else
		fd4 = open("tests/example_nonewline.txt", O_RDONLY);
	char	*b_read4 = get_next_line(fd4);
	printf("b_read: '%s'\n", b_read4);
	char	output4[] = "Hello world!";
	assert(strncmp(b_read4, output4, BUFFER_SIZE) == 0);
	printf("\n-------\n");

	// Test 5: Read contents with special characters
	printf("Test 5: Read contents with special characters\n");
	int		fd5;
	if (access("tests/example_specialchars.txt", F_OK) == -1)
	{
		printf("file doesnt exist, are you running the test from 'get_next_line'?\n");
		fd5 = open("example_specialchars.txt", O_RDONLY);
	}
	else
		fd5 = open("tests/example_specialchars.txt", O_RDONLY);
	char	*b_read5 = get_next_line(fd5);
	printf("b_read: '%s'\n", b_read5);
	char	output5[] = "hello @@@@@#####%%^^&&** there!\n";
	assert(strncmp(b_read5, output5, BUFFER_SIZE) == 0);
	free(b_read4);
	printf("\n-------\n");

	// Test 6: Read contents with multiple paragraphs , with intermediat
	// empty spaces, 
	printf("Test 6: Read contents with multiple paragraphs, with intermediate empty spaces\n");
	int		fd6;
	if (access("tests/example_longerpara.txt", F_OK) == -1)
	{
		printf("file doesnt exist, are you running the test from 'get_next_line'?\n");
		fd6 = open("example_longerpara.txt", O_RDONLY);
	}
	else
		fd6 = open("tests/example_longerpara.txt", O_RDONLY);
	char	*b_read6a = get_next_line(fd6);
	printf("b_read: '%s'\n", b_read6a);
	char	output6a[] = "There was no possibility of taking a walk that day. \n";
	assert(strncmp(b_read6a, output6a, BUFFER_SIZE) == 0);
	// This part may not be valid if the BUFFER size < len of each row.
	// char	*b_read6b = get_next_line(fd6);
	// char	output6b[] = "We had been wandering, indeed, in the leafless shrubbery an hour in the morning; but since dinner (Mrs. Reed, when there was no company, dined early) the cold winter wind had brought with it clouds so sombre, and a rain so penetrating, that further out-door exercise was now out of the question. \n";
	// assert(strcmp(b_read6b, output6b) == 0);
	free(b_read6a);
	// free(b_read6b);
	printf("\n-------\n");

	// Test 7: Read contents till end of file, and subequently returns NULL
	printf("Test 7: Read contents till end of file, and subsequently returns NULL\n");
	int		fd7;
	if (access("tests/example_twolines.txt", F_OK) == -1)
	{
		printf("file doesnt exist, are you running the test from 'get_next_line'?\n");
		fd7 = open("example_twolines.txt", O_RDONLY);
	}
	else
		fd7 = open("tests/example_twolines.txt", O_RDONLY);
	char	*b_read7a = get_next_line(fd7);
	printf("b_read: '%s'\n", b_read7a);
	char	output7a[] = "Hello world;\n";
	assert(strcmp(b_read7a, output7a) == 0);
	// This part may not be valid if the BUFFER size < len of each row.
	char	*b_read7b = get_next_line(fd7);
	printf("b_read: '%s'\n", b_read7b);
	char	output7b[] = "I am a bot.";
	assert(strcmp(b_read7b, output7b) == 0);
	// char	*b_read7c = get_next_line(fd7);
	// assert(!b_read7c);
	free(b_read7a);
	free(b_read7b);
	// free(b_read7c);
	printf("\n-------\n");

	// Test 8: single newline
	printf("Test 8: single newline\n");
	int		fd8;
	if (access("tests/example_singlenl.txt", F_OK) == -1)
	{
		printf("file doesnt exist, are you running the test from 'get_next_line'?\n");
		fd8 = open("example_singlenl.txt", O_RDONLY);
	}
	else
		fd8 = open("tests/example_singlenl.txt", O_RDONLY);
	char	*b_read8 = get_next_line(fd8);
	printf("b_read: '%s'\n", b_read8);
	char	output8[] = "\n";
	assert(strcmp(b_read8, output8) == 0);
	free(b_read8);
	printf("\n-------\n");

	// Test 9: Multiple new lines
	printf("Test 9: multiple newlines\n");
	int		fd9;
	if(access("tests/example_multiplenl.txt", F_OK) == -1)
	{
		printf("file doesnt exist, are you running the test from 'get_next_line'?\n");
		fd9 = open("example_multiplenl.txt", O_RDONLY);
	}
	else
		fd9 = open("tests/example_multiplenl.txt", O_RDONLY);
	char	*b_read9a = get_next_line(fd9);
	printf("b_read: '%s'\n", b_read9a);
	char	output9a[] = "\n";
	assert(strcmp(b_read9a, output9a) == 0);
	char	output9b[] = "\n";
	char	output9c[] = "\n";
	char	output9d[] = "\n";
	char	output9e[] = "\n";
	assert(strcmp(b_read9a, output9b) == 0);
	assert(strcmp(b_read9a, output9c) == 0);
	assert(strcmp(b_read9a, output9d) == 0);
	assert(strcmp(b_read9a, output9e) == 0);
	free(b_read9a);
	printf("\n-------\n");

	// Test 10: multiple lines with nl
	printf("Test 10: multiple lines with newlines\n");
	int		fd10;
	if(access("tests/example_multiplelinewithnl.txt", F_OK) == -1)
	{
		printf("file doesnt exist, are you running the test from 'get_next_line'?\n");
		fd10 = open("example_multiplelinewithnl.txt", O_RDONLY);
	}
	else
		fd10 = open("tests/example_multiplelinewithnl.txt", O_RDONLY);
	char	*b_read10a = get_next_line(fd10);
	printf("b_read: '%s'\n", b_read10a);
	char	output10a[] = "This is a test to see\n";
	char	output10b[] = "\n";
	char	output10c[] = "If the program\n";
	char	output10d[] = "\n";
	char	output10e[] = "is able\n";
	char	output10f[] = "\n";
	char	output10g[] = "\n";
	char	output10h[] = "to\n";
	char	output10i[] = "\n";
	char	output10j[] = "Defy\n";
	char	output10k[] = "\n";
	char	output10l[] = "the\n";
	char	output10m[] = "\n";
	char	output10n[] = "odds\n";
	char	output10o[] = "\n";
	char	output10p[] = ";";
	assert(strcmp(b_read10a, output10a) == 0);
	char	*b_read10b = get_next_line(fd10);
	printf("b_read: '%s'\n", b_read10b);
	assert(strcmp(b_read10b, output10b) == 0);
	char	*b_read10c = get_next_line(fd10);
	printf("b_read: '%s'\n", b_read10c);
	assert(strcmp(b_read10c, output10c) == 0);
	char	*b_read10d = get_next_line(fd10);
	printf("b_read: '%s'\n", b_read10d);
	assert(strcmp(b_read10d, output10d) == 0);
	char	*b_read10e = get_next_line(fd10);
	printf("b_read: '%s'\n", b_read10e);
	assert(strcmp(b_read10e, output10e) == 0);
	char	*b_read10f = get_next_line(fd10);
	printf("b_read: '%s'\n", b_read10f);
	assert(strcmp(b_read10f, output10f) == 0);
	char	*b_read10g = get_next_line(fd10);
	printf("b_read: '%s'\n", b_read10g);
	assert(strcmp(b_read10g, output10g) == 0);
	char	*b_read10h = get_next_line(fd10);
	printf("b_read: '%s'\n", b_read10h);
	assert(strcmp(b_read10h, output10h) == 0);
	char	*b_read10i = get_next_line(fd10);
	printf("b_read: '%s'\n", b_read10i);
	assert(strcmp(b_read10i, output10i) == 0);
	char	*b_read10j = get_next_line(fd10);
	printf("b_read: '%s'\n", b_read10j);
	assert(strcmp(b_read10j, output10j) == 0);
	char	*b_read10k = get_next_line(fd10);
	printf("b_read: '%s'\n", b_read10k);
	assert(strcmp(b_read10k, output10k) == 0);
	char	*b_read10l = get_next_line(fd10);
	printf("b_read: '%s'\n", b_read10l);
	assert(strcmp(b_read10l, output10l) == 0);
	char	*b_read10m = get_next_line(fd10);
	printf("b_read: '%s'\n", b_read10m);
	assert(strcmp(b_read10m, output10m) == 0);
	char	*b_read10n = get_next_line(fd10);
	printf("b_read: '%s'\n", b_read10n);
	assert(strcmp(b_read10n, output10n) == 0);
	char	*b_read10o = get_next_line(fd10);
	printf("b_read: '%s'\n", b_read10o);
	assert(strcmp(b_read10o, output10o) == 0);
	char	*b_read10p = get_next_line(fd10);
	printf("b_read: '%s'\n", b_read10p);
	assert(strcmp(b_read10p, output10p) == 0);


	//---------- Tests, read from standard input
	// Test 1: Read one sentence.

	// Test 2: Read one paragraph.

	// Test 3: Read empty file

	// Test 4: Read contents with no terminating \n char

	// Test 5: Read contents with special characters

	// Test 6: reading till end of line subsequently returns null


	//---------- Tests, complex scenarios
	// Test 1: Read contents with varying fd types (e.g. 3, 4 ,5)
	printf("all tests passed!\n");
}
