#include "main.h"
#include <stdlib.h>
/**
 *read_textfile- Read text file print to STDOUT.
 *@filename: text file being read
 *@letters: number of letters to be read
 *Return: w- actual number of bytes read and printed
 *0 when function fails or filename is NULL.
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	char *b;
	ssize_t fd;
	ssize_t a;
	ssize_t t;
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (0);
	b = malloc(sizeof(char) * letters);
	t = read(fd, b, letters);
	a = write(STDOUT_FILENO, b, t);
	free(b);
	close(fd);
	return (a);
}
