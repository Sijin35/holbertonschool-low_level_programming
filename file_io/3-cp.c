#include "main.h"
/**
 *main - Copies from one file to another
 *
 *@argc: Argument counter
 *
 *@argv: Argument vector
 *
 *Return: Success or fail
 */
int main(int argc, char *argv[])
{
	int f_from, f_to, r, w;
	char buffer[1024];

	if (argc != 3)
  {
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n"), exit(97);
  }
	f_to = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0664);
	if (f_to == -1)
  {
    dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]), exit(99);
  }
	f_from = open(argv[1], O_RDONLY);
	if (f_from == -1)
  {
    dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]), exit(98);
  }

	while ((r = read(f_from, buffer, 1024)) > 0)
	{
		w = write(f_to, buffer, r);
		if (w == -1)
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]), exit(99);
	}

	if (r == -1)
  {
    dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]), exit(98);
  }
	if (close(f_from) == -1)
  {
    dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", f_from), exit(100);
  }

	if (close(f_to) == -1)
  {
    dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", f_to), exit(100);
  }
return (0);
}
