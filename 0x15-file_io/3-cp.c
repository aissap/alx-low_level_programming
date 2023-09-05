#include "main.h"
#include <stdio.h>
#include <stdlib.h>

char *allocate_buffer(size_t size);
void safely_close_fd(int fd);

/**
 *allocate_buffer:  Allocates memory for a buffer.
 *@size: The size of the buffer to allocate.
 *Return: A pointer to the newly-allocated buffer.
 */
char *allocate_buffer(size_t size)
{
	char *buffer = malloc(size);

	if (buffer == NULL)
	{
		fprintf(stderr, "error: Unable to allocate memory\n");
		exit(EXIT_FAILURE);
	}

	return (buffer);
}

/**
 * safely_close_fd - closes a file descriptor and checks for errors.
 * @fd: the file descriptor to close.
 */

void safely_close_fd(int fd)
{
	if (close(fd) == -1)
	{
		fprintf(stderr, "error: unable to close file descriptor %d\n", fd);
		exit(EXIT_FAILURE);
	}
}
/**
 * main - Copies the contents of one file to another file.
 * @argc: The number of command-line arguments.
 *
 * @argv: An array of strings containing the command-line arguments.
 *
 * Return: 0 on success, or an exit code on failure.
 */

int main(int argc, char *argv[])
{
	int source_fd, dest_fd;
	ssize_t bytes_read, bytes_written;
	char *buffer;
	size_t buffer_size = 1024;

	if (argc != 3)
	{
		fprintf(stderr, "usage: %s file_from file_to\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	buffer = allocate_buffer(buffer_size);
	source_fd = open(argv[1], O_RDONLY);
	dest_fd = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);

	if (source_fd == -1 || dest_fd == -1)
	{
		fprintf(stderr, "error: unable to open files\n");
		free(buffer);
		exit(EXIT_FAILURE);
	}

	do	{
		bytes_read = read(source_fd, buffer, buffer_size);

		if (bytes_read == -1)
		{
			fprintf(stderr, "error: unable to read from filrs %s\n", argv[1]);
			free(buffer);
			exit(EXIT_FAILURE);
		}

		bytes_written = write(dest_fd, buffer, bytes_read);

		if (bytes_written == -1)
		{
			fprintf(stderr, "error: unable to write to file %s\n", argv[2]);
			free(buffer);
			exit(EXIT_FAILURE);
		}

	} while (bytes_read > 0);

		free(buffer);
		safely_close_fd(source_fd);
		safely_close_fd(dest_fd);

	return (0);
}
