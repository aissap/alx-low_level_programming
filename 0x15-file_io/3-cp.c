#include "main.h"
#include <stdio.h>
#include <stdlib.h>


/**
 * errorHandling - Handles errors related to file operations.
 * @from: the source file descriptor.
 * @to: the destination file descriptor.
 * @argv: the array of command-line argument.
 */

void errorHandling(int from, int to, char *argv[])
{
	if (from == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
		exit(98);
	}
	if (to == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
		exit(99);
	}
}

/**
 * main - Entry point for the cp program.
 * @argc: the argument count.
 * @argv: the argument vector.
 * Return: Always 0 (Success).
 */

int main(int argc, char *argv[])
{
	int source_fd, dest_fd, close_result;
	ssize_t num_chars, num_written;
	char buffer[1024];

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "%s\n", "Usage: cp file_from file_to");
		exit(97);
	}

	source_fd = open(argv[1], O_RDONLY);
	dest_fd = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC | O_APPEND, 0664);
	errorHandling(source_fd, dest_fd, argv);
	num_chars = 1024;
	while ((num_chars = read(source_fd, buffer, 1024)) > 0)
	{
		if (num_chars == -1)

		errorHandling(-1, 0, argv);

		num_written = write(dest_fd, buffer, num_chars);
		if (num_written == -1)
			errorHandling(0, -1, argv);
	close_result = close(source_fd);
	if (close_result == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", source_fd);
		exit(100);
	}

	close_result = close(dest_fd);

	if (close_result == -1)
	{
	dprintf(STDERR_FILENO, "Error:Cant close fd %d\n", dest_fd);
	exit(100);
	}
	return (0);
	}
