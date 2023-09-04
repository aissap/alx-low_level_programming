#include "main.h"
#include <stdlib.h>

/**
 * read_textfile- read text file print to STDOUT.
 * @max_chars: The maximum number of characters to read and print.
 * @filename: text file being read
 * Return: w- actual number of bytes read and printed
 * 0 when function fails or filename is NULL.
 */
ssize_t read_textfile(const char *filename, size_t max_chars)
{
	char *buffer;
	ssize_t file_descriptor;
	ssize_t bytes_read;
	ssize_t bytes_written;

	file_descriptor = open(filename, O_RDONLY);
	if (file_descriptor == -1)
		return (0;)
	
	buffer = malloc(sizeof(char) * max_chars);
	if (buffer == NULL)
	{
	close(file_descriptor);
	return (0);
	}
	
	bytes_read = read(file_descriptor, buffer, max_chars);
	bytes_written = write(STDOUT_FILENO, buffer, bytes_read);

	free(buffer);
	close(file_descriptor);
	return (bytes_written);
}
