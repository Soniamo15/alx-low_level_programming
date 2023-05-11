#include "main.h"

/**
 * create_buffer - Allocates 1024 bytes for a buffer.
 *
 * @file: The name of the file buffer is storing chars for.
 *
 * Return: A pointer to the newly-allocated buffer.
 */
char *create_buffer(char *file)
{
	char *buffer;

	buffer = malloc(sizeof(char) * 1024);
	if (buffer == NULL)
	{
		dprintf(STDERR_FILENO,
				"Error: Can't write to %s\n", file);
		exit(99);
	}
	return (buffer);
}

/**
 * close_file - Closes file descriptors.
 *
 * @fd: The file descriptor to be closed.
 */
void close_file(int fd)
{
	int c;

	c = close(fd);
	if (c == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd);
		exit(100);
	}
}

/**
 * read_file - Reads from one file descriptor and writes to another.
 *
 * @from: The file descriptor to read from.
 * @to: The file descriptor to write to.
 * @buffer: The buffer to store the data being read.
 *
 * Return: The number of bytes read.
 */
ssize_t read_file(int from, int to, char *buffer)
{
	ssize_t r, w;

	r = read(from, buffer, 1024);
	if (r == -1)
	{
		return (-1);
	}

	w = write(to, buffer, r);
	if (w == -1)
	{
		return (-1);
	}

	return (r);
}

/**
 * copy_file - Copies the contents of a file to another file.
 *
 * @from_path: The path to the file to be copied.
 * @to_path: The path to the file to copy to.
 *
 * Return: 0 on success.
 *
 * Description: If file_from does not exist or cannot br read - exit code
 * If file_to cannot be created or written to - exit code 99.
 * If file_to or file_from cannot be closed - exit code 100.
 */
int copy_file(char *from_path, char *to_path)
{
	int from, to;
	char *buffer;
	ssize_t r;

	from = open(from_path, O_RDONLY);
	if (from == -1)
	{
		dprintf(STDERR_FILENO,
				"Error: Can't read from file %s\n", from_path);
		exit(98);
	}

	buffer = create_buffer(to_path);

	to = open(to_path, O_CREAT | O_WRONLY | O_TRUNC, 0664);
	if (to == -1)
	{
		dprintf(STDERR_FILENO,
				"Error: Can't write to %s\n", to_path);
		free(buffer);
		exit(99);
	}

	do {
		r = read_file(from, to, buffer);
		if (r == -1)
		{
			dprintf(STDERR_FILENO,
					"Error: Can't read from file %s\n", from_path);
			free(buffer);
			exit(98);
		}

	} while (r > 0);

	close_file(from);
	close_file(to);
	free(buffer);

	return (0);
}

/**
 * main - Entry point for the program.
 *
 * @argc: The number of arguments supplied to the program.
 * @argv: An array of pointers to the arguments.
 *
 * Return: 0 on success.
 *
 * Description: If the argument count is incorrect - exit code 97.
 */
int main(int argc, char *argv[])
