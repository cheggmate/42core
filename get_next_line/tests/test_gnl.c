#include "get_next_line.h"
#include <assert.h>
#include <string.h>

int	main(void)
{
	//---------- Tests, read from file
	// Test 1: Read one sentence.
	char	buffer1[BUFFER_SIZE];
	int 	fd1 = open("example_simple.txt", O_RDONLY);
	char	*b_read1 = get_next_line(fd1);
	char	output1[] = "Hello world!\n";
	assert(strncmp(b_read1, output1, BUFFER_SIZE) == 0);

	// Test 2: Read one paragraph.
	char	buffer2[BUFFER_SIZE];
	int		fd2 = open("example_longsentence.txt", O_RDONLY);
	char	*b_read2 = get_next_line(fd2);
	char	output2[] = "However little known the feelings or views of such a man may be on his first entering a neighbourhood, this truth is so well fixed in the minds of the surrounding families, that he is considered as the rightful property of some one or other of their daughters.\n";
	assert(strncmp(b_read2, output2, BUFFER_SIZE) == 0);

	// Test 3: Read empty input
	char	buffer3[BUFFER_SIZE];
	int		fd3 = open("example_emptyfile.txt", O_RDONLY);
	char	*b_read3 = get_next_line(fd3);
	assert(strcmp(b_read3, "") == 0);

	// Test 4: Read contents with no terminating \n char
	char	buffer4[BUFFER_SIZE];
	int		fd4 = open("example_nonewline.txt", O_RDONLY);
	char	*b_read4 = get_next_line(fd4);
	char	output4[] = "Hello world!";
	assert(strcnmp(b_read4, output4, BUFFER_SIZE) == 0);

	// Test 5: Read contents with special characters
	char	buffer5[BUFFER_SIZE];
	int		fd5 = open("example_specialchars.txt", O_RDONLY);
	char	*b_read5 = get_next_line(fd5);
	char	output5[] = "hello @@@@@#####%%^^&&** there!\n";
	assert(strncmp(b_read5, output5, BUFFER_SIZE) == 0);

	// Test 6: Read contents with multiple paragraphs , with intermediat
	// empty spaces, 
	char	buffer6[BUFFER_SIZE];
	int		fd6 = open("example_longerpara.txt", O_RDONLY);
	char	*b_read6a = get_next_line(fd6);
	char	output6a[] = "There was no possibility of taking a walk that day. \n";
	assert(strncmp(b_read6a, output6a, BUFFER_SIZE) == 0);
	// This part may not be valid if the BUFFER size < len of each row.
	// char	*b_read6b = get_next_line(fd6);
	// char	output6b[] = "We had been wandering, indeed, in the leafless shrubbery an hour in the morning; but since dinner (Mrs. Reed, when there was no company, dined early) the cold winter wind had brought with it clouds so sombre, and a rain so penetrating, that further out-door exercise was now out of the question. \n";
	// assert(strcmp(b_read6b, output6b) == 0);

	// Test 7: Read contents till end of file, and subequently returns NULL
	char	buffer7[BUFFER_SIZE];
	int		fd7 = open("example_twolines.txt", O_RDONLY);
	char	*b_read7a = get_next_line(fd7);
	char	output7a[] = "Hello world;\n";
	assert(strcmp(b_read7a, output7a) == 0);
	// This part may not be valid if the BUFFER size < len of each row.
	// char	*b_read7b = get_next_line(fd7);
	// char	output7b[] = "I am a bot.";
	// assert(strcmp(b_read7b, output7b) == 0);
	// char	*b_read7c = get_next_line(fd7);
	// assert(!b_read7c);



	//---------- Tests, read from standard input
	// Test 1: Read one sentence.

	// Test 2: Read one paragraph.

	// Test 3: Read empty file

	// Test 4: Read contents with no terminating \n char

	// Test 5: Read contents with special characters

	// Test 6: reading till end of line subsequently returns null


	//---------- Tests, complex scenarios
	// Test 1: Read contents with varying fd types (e.g. 3, 4 ,5)
}