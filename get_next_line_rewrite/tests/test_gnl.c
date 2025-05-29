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
	printf("Test 2: Read one paragraph\n");
	int		fd2;
	if (access("tests/example_longsentence.txt", F_OK) == -1)
	{
		printf("file doesnt exist, are you running the test from 'get_next_line'?\n");
		fd2 = open("example_longsentence.txt", O_RDONLY);
	}
	else
		fd2 = open("tests/example_longsentence.txt", O_RDONLY);
	char	*b_read2 = get_next_line(fd2);
	printf("b_read: '%s'\n", b_read2);
	char	output2[] = "However little known the feelings or views of such a man may be on his first entering a neighbourhood, this truth is so well fixed in the minds of the surrounding families, that he is considered as the rightful property of some one or other of their daughters.";
	assert(strcmp(b_read2, output2) == 0);
	free(b_read2);
	printf("\n-------\n");

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
	char	*b_read9 = get_next_line(fd9);
	printf("b_read: '%s'\n", b_read9);
	char	output9[] = "\n";
	assert(strcmp(b_read9, output9) == 0);
	free(b_read9);
	printf("\n-------\n");

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
