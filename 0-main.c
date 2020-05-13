#include "monty.h"

#define INTCMD argv[0] /* int mode command */
#define INTDATA argv[1] /* data to be added to nodes */

int line_count = 0;

/**
 * main - gets lines from bytecode file
 * @argc: number of arguments
 * @argv: argument vector
 * Return: always 0
 */
int main(int argc, char **argv)
{
	char *buf = NULL;
	size_t bufSize = 0;
	ssize_t rd;
	stack_t *head == NULL;

	FILE *fp;
	instruction_t opcodes[] =
		{
			{"pall", pall_s},
			{"pop", pop_s},
			{"add", add_s},
			{ NULL, NULL }
		}

	/* Check if a file is trying to be fed */
	if (argv[1] == NULL)
		isatty(STDIN_FILENO);

	/* Open the monte file as read only */
	fp = fopen(argv[1], "r");

	/* Check if file open failed */
	if (!fp)
		fprintf(stderr, "Error: cannot open file\n"), exit(EXIT_FAILURE);

	/* INTERACTIVE MODE */
	while (1)
	{
		rd = getline(&buf, &bufSize, stdin);
		for (index = 0; opcodes[index] != NULL; index++)
		{
				/* Check if function exists in struct */
				if(strcmp(INTCMD, opcodes[index]) == 0)
					opcodes[index].f(&head, line_count);

				/* Check if push exists and data has been given */
				else if (strcmp(INTCMD, "push") == 0 && INTDATA)
					push_s(&head, line_count, argv[1]);
		}
		line_count++;
	}
	/* CLEANUP */
	free(buf), fclose(fp);
	return (0);
}
