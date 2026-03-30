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
	ssize_t bytes, write_bytes;
	int fd;
	char *buffer;

	if (filename == NULL)
	{return (0); }
	buffer = malloc(sizeof(char) * letters);
	if (buffer == NULL)
	{return (0); }
	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		free(buffer);
		return (0);
	}
	bytes = read(fd, buffer, letters);
	if (bytes == -1)
	{
		close(fd);
		free(buffer);
		return (0);
	}
	write_bytes = write(1, buffer, bytes);
	if (write_bytes != bytes)
	{
		close(fd);
		free(buffer);
		return (0);
	}
	close(fd);
	free(buffer);
	return (bytes);
}
