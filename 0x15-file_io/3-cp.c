#include "main.h"
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>
#include <errno.h>

#define BUF_SIZE 1024

/**
 * error_file - print an error message and exit with the given status code
 * @errcode: the exit status code
 * @format: the error message format string
 * @...: arguments to the format string
 */
void error_file(int errcode, const char *format, ...)
{
	va_list args;

	va_start(args, format);
	dprintf(STDERR_FILENO, "Error: ");
	vdprintf(STDERR_FILENO, format, args);
	va_end(args);

	exit(errcode);
}

/**
 * main - copy the content of a file to another file
 * @argc: the number of command-line arguments
 * @argv: an array of command-line arguments
 *
 * Return: 0 on success, or an exit status code on failure
 */
int main(int argc, char *argv[])
{
	int fd_from, fd_to, num_read, num_written;
	char buf[BUF_SIZE];

	if (argc != 3)
		error_file(97, "Usage: cp file_from file_to\n");

	fd_from = open(argv[1], O_RDONLY);
	if (fd_from == -1)
		error_file(98, "Can't read from file %s\n", argv[1]);

	fd_to = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd_to == -1)
		error_file(99, "Can't write to file %s\n", argv[2]);

	while ((num_read = read(fd_from, buf, BUF_SIZE)) > 0) {
		num_written = write(fd_to, buf, num_read);
		if (num_written != num_read)
			error_file(99, "Can't write to file %s\n", argv[2]);
	}

	if (num_read == -1)
		error_file(98, "Can't read from file %s\n", argv[1]);

	if (close(fd_from) == -1)
		error_file(100, "Can't close fd %d\n", fd_from);

	if (close(fd_to) == -1)
		error_file(100, "Can't close fd %d\n", fd_to);

	return 0;
}

