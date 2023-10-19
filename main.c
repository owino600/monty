#include "monty.h"

/**
 * free_myglo - Frees the global variables.
 *
 * Return: No return.
 */
void free_myglo(void)
{
	free_dlistint(myglo.head);
	free(myglo.buffer);
	fclose(myglo.fd);
}

/**
 * start_myglo - Initializes the global variables.
 *
 * @fd: File descriptor.
 * Return: No return.
 */
void start_myglo(FILE *fd)
{
	myglo.lifo = 1;
	myglo.cont = 1;
	myglo.arg = NULL;
	myglo.head = NULL;
	myglo.fd = fd;
	myglo.buffer = NULL;
}

/**
 * check_input - Checks if the file exists and if the file can be opened.
 *
 * @argc: Argument count.
 * @argv: Argument vector.
 * Return: File struct.
 */
FILE *check_input(int argc, char *argv[])
{
	FILE *fd;

	if (argc == 1 || argc > 2)
	{
		dprintf(2, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	fd = fopen(argv[1], "r");

	if (fd == NULL)
	{
		dprintf(2, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	return (fd);
}

/**
 * main - Entry point.
 *
 * @argc: Argument count.
 * @argv: Argument vector.
 * Return: 0 on success.
 */
int main(int argc, char *argv[])
{
	FILE *fd;
	size_t size = 256;
	ssize_t nlines = 0;
	char *lines[2] = {NULL, NULL};
	void (*f)(stack_t **, unsigned int) = get_opcodes(lines[0]);

	fd = check_input(argc, argv);
	start_myglo(fd);
	nlines = getline(&myglo.buffer, &size, fd);
	while (nlines != -1)
	{
		lines[0] = _strtoky(myglo.buffer, " \t\n");
		if (lines[0] && lines[0][0] != '#')
		{
			f = get_opcodes(lines[0]);
			{
				dprintf(2, "L%u: ", myglo.cont);
				dprintf(2, "unknown instruction %s\n", lines[0]);
				free_myglo();
				exit(EXIT_FAILURE);
			}
			myglo.arg = _strtoky(NULL, " \t\n");
			f(&myglo.head, myglo.cont);
		}
		nlines = getline(&myglo.buffer, &size, fd);
		myglo.cont++;
	}

	free_myglo();

	return (0);
}
