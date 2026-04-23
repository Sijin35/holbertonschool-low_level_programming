#include "main.h"

/**
 * read_textfile - Reads a text afile and prints to the POSIX standard output
 *
 * @filename: Name of file
 *
 * @letters: Number of letters to be read and printed
 *
 * Return: Number of letters it could read/print, 0 if cannot be opened/read
 * || filename = NULL || write fails
 */

ssize_t read_textfile(const char *filename, size_t letters)
{
	int fd;
	char *buffer = malloc(letters);
	ssize_t r, w;

	if (!filename)
	{
		return (0);
	}
	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		return (0);
	}
	if (!buffer)
	{
		close(fd);
		return (0);
	}
	r = read(fd, buffer, letters);
	if (r == -1)
	{
		free(buffer);
		close(fd);
		return (0);
	}
	w = write(STDOUT_FILENO, buffer, r);
	if (w == -1 || w != r)
	{
		free(buffer);
		close(fd);
		return (0);
	}
	free(buffer);
	close(fd);
	return (w);
}
