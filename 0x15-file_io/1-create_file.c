#include "main.h"

/**
 * create_file - Creates a file with optional content.
 * @filename: A pointer to the name of the file to create.
 * @content: A pointer to a string to write to the file.
 *
 * Return: If the function fails - -1.
 * otherwise -1.
 */

int create_file(const char *filename, char *content)
{
	int file_description, write_result, lenght = 0;

	if (filename == NULL)
		return (-1);

	if (content != NULL)
	{
	for (lenght = 0; content[lenght];)
		lenght++;
	}

	file_descriptor = open(filename, O_CREAT | O_RDWR | O_TRUNC, 0600);
	write_result = write(file_descriptor, content, lenght);

	if (file_e_descriptor == -1 || write_result == -1)

		return (-1);
	close(file_descriptor);

	return (1);
}
