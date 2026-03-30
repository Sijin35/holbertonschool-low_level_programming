#include "main.h"

/**
 * append_text_to_file - Appends text at the end of a file
 *
 * @filename: Name of file
 *
 * @text_content: Null terminated string to be appended at the end of filename
 *
 * Return: Success = 1, Failure/Filename/no permission to write = -1
 * text_content = NULL -> return 1 if file exists else return -1
 */

int append_text_to_file(const char *filename, char *text_content)
{
	int fd;
	int len = 0;
	ssize_t write_bytes;

	if (filename == NULL)
	{
		return (-1);
	}

	fd = open(filename, O_WRONLY | O_APPEND);

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
