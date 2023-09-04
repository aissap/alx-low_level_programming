#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

/**
 * append_to_existing_file - Appends text at the end of an existing file.
 *
 * @filename: The name of the file to append to.
 * @text_content: The string to append at the end of the file.
 *
 * Return: 1 on success, -1 on failure.
 *-1 if the file does not exist or if write permissions are insufficient.
 *-1 if filename is NULL.
 */
int append_to_existing_file(const char *filename, char *text_content)
{
	int file_descriptor, write_result;

	if (filename == NULL)
		return (-1);
	file_descriptor = open(filename, O_WRONLY | O_APPEND);

	if (file_descriptor == -1)
		return (-1);
	if (text_content != NULL)
	{
		write_result = write(file_descriptor, text_content, strlen(text_content));
	if (write_result == -1)
	{
		close(file_descriptor);
	return (-1);
	}
	{

	close(file_descriptor);
	return (1);
}

