#include "main.h"
#include <stdio.h>
#include <stdlib.h>

char *allocate_memory_buffer(void);
void close_descriptor(int fd);

/**
 * allocate_memory_buffer - Allocates a buffer of.
 *
 * Return: A pointer to the newly-allocated buffer.
 */
char *allocate_memory_buffer(void)
{
	char *buffer = malloc(sizeof(char) * 1024);

	if (buffer == NULL)
	{
		dprintf(STDERR_FILENO, "Error: Unable to allocate memory\n");
		exit(EXIT_FAILURE);
	}

	return (buffer);
}

/**
 * close_descriptor - Closes file descriptors.
 * @fd: The file descriptor to be closed.
 */

void close_descriptor(int fd)

{

	if (close(fd) == -1)
	{
		dprintf(STDERR_FILENO, "Error: Unable to close file descriptor %d\n", fd);
		exit(100);
	}
}

/**
 * main - Copies the contents of one file to another file.
 * @argc: The number of arguments supplied to the program.
 * @argv: An array of pointers to the arguments.
 *
 * Return: 0 on success, or an exit code on failure.
 */

int main(int argc, char *argv[])
{
	int source_fd, destination_fd, bytes_read, bytes_written;
	char *buffer;


	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: file_from file_to\n");
		exit(97);
	}

	buffer = allocate_memory_buffer();
	source_fd = open(argv[1], O_RDONLY);
	bytes_read = read(source_fd, buffer, 1024);
	destination_fd = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);

	do

	{
		if (source_fd == -1 || bytes_read == -1)
		{
			dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
			free(buffer);
			exit(98);
		}

		bytes_written = write(destination_fd, buffer, bytes_read);

		if (destination_fd == -1 || bytes_written == -1)
		{
			dprintf(STDERR_FILENO, "Error: Can't write to file %s\n", argv[2]);
			free(buffer);
			exit(99);
		}
		bytes_read = read(source_fd, buffer, 1024);
		destination_fd = open(argv[2], O_WRONLY | O_APPEND);

	} while (bytes_read > 0);

	free(buffer);
	close_descriptor(source_fd);
	close_descriptor(destination_fd);

	return (0);
}
