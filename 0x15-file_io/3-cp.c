#include <stdio.h>
#include <stdlib.h>
#include "main.h"

#define BUFFER_SIZE 1024
/**
 * main: the program that copies the content of a file to another file.
 * @argc: number of arguments passed to the program.
 * @argv: array of pointers to the arguments passed to the program.
 * Return: always 0
 */

int main(int argc, char *argv[])
{
	FILE *file_from, *file_to;
	char buffer[BUFFER_SIZE];
	size_t bytes_read;

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}
	file_from = fopen(argv[1], "r");
	if (file_from == NULL)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n",
		argv[1]);
		exit(98);
	}
	file_to = fopen(argv[2], "w");
	if (file_to == NULL)
	{
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
		exit(99);
	}
	while ((bytes_read = fread(buffer, sizeof(char), BUFFER_SIZE, file_from
	)) > 0)
	{
		if (fwrite(buffer, sizeof(char), bytes_read, file_to) !=
		bytes_read)
		{
			dprintf(STDERR_FILENO, "Error: Can't write to %s\n",
			argv[2]);
			exit(99);
		}
	}
	if (fclose(file_from) != 0)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n",
		fileno(file_from));
		exit(100);
	}
	if (fclose(file_to) != 0)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n",
		fileno(file_to));
		exit(100);
	}
	return (0);
}
