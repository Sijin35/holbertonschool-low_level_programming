#include "main.h"

/**
 * create_file - Creates a file
 * If file exists, truncates it
 *
 * @filename: Name of file to be created
 *
 * @text_content: NULL terminated string to write to the file
 * If text_content = NULL, creates empty file
 *
 * Return: Success = 1, Failure = -1, filename = NULL = -1
 * Cannot create file, cannot write file, write fails, etc.
 */

int create_file(const char *filename, char *text_content)
{
	int fd;
	int len = 0;
	ssize_t write_bytes;

	if (filename == NULL)
	{
		return (-1);
	}

	fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0600);

	if (fd == -1)
	{
		return (-1);
	}

	if (text_content == NULL)
	{
		close(fd);
		return (1);
	}

	while (text_content[len])
	{
		len++;
	}

	write_bytes = write(fd, text_content, len);

	if (write_bytes != len)
	{
		close(fd);
		return (-1);
	}

	close(fd);
	return (1);
}
