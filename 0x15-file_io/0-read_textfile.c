#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

/**
 * read_textfile - Reads text file and prints to STDOUT.
 * @filename: Text file to read.
 * @letters: The number of letters to read
 *
 * Return: actual number of bytes read and printed, or 0
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	ssize_t fd;
	ssize_t bytes_read;
	ssize_t bytes_written;
	char *buf;

	if (filename == NULL)
		return (0);

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (0);

	buf = malloc(sizeof(char) * letters);
	if (buf == NULL)
	{
		close(fd);
		return (0);
	}

	bytes_read = read(fd, buf, letters);
	if (bytes_read == -1)
	{
		free(buf);
		close(fd);
		return (0);
	}

	bytes_written = write(STDOUT_FILENO, buf, bytes_read);
	{
		free(buf);
		close(fd);
	return (bytes_written);
	}
}

