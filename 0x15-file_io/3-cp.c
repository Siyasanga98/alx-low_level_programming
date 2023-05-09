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
	dprintf(STDERR_FILENO, format, args);
	va_end(args);

	exit(errcode);
}

/**
 * main - copy the content of a file to another file
 * @argc: the number of command-line arguments
 * @argv: an array of command-line arguments
 *
 * Return: 0 on success, or an exit on failure
 */
int main(int argc, char *argv[])
{
	int fd_from, fd_to;
	ssize_t num_read = 0, num_written = 0;
	char buf[BUF_SIZE];

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}

	fd_from = open(argv[1], O_RDONLY);
	if (fd_from == -1)
	{
		dprintf(STDERR_FILENO, "Can't read from file %s\n", argv[1]);
		exit(98);
	}

	fd_to = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0664);
	if (fd_to == -1)
	{
		dprintf(STDERR_FILENO, "Can't write to file %s\n", argv[2]);
		exit(99);
	}

	while ((num_read = read(fd_from, buf, BUF_SIZE)) > 0) 
	{
		num_written = write(fd_to, buf, num_read);
		if (num_written != num_read)
		{
			dprintf(STDERR_FILENO, "Can't write to file %s\n", argv[2]);
			exit(99);
		}
	}


	if (num_read == -1)
	{
		dprintf(STDERR_FILENO, "Can't read from file %s\n", argv[1]);
		exit(98);
	}

	if (close(fd_from) == -1)
	{
		dprintf(STDERR_FILENO, "Can't close fd %d\n", fd_from);
		exit(100);
	}

	if (close(fd_to) == -1)
	{
		dprintf(STDERR_FILENO, "Can't close fd %d\n", fd_to);
		exit(100);
	}

	return(0);
}
