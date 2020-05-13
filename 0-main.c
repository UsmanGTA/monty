#include "monty.h"

#define INTCMD argv[0] /* int mode command */
#define INTDATA argv[1] /* data to be added to nodes */
#define GETLINE (bytes = getline(&buf, &bufSize, stdin))
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
	char *tokens;
	char *args[10];
	size_t bufSize = 0, index;
	ssize_t bytes;
	stack_t *head = NULL;
	/* FILE *fp; */
	instruction_t opcodes[] = {
			{"pall", pall_s},
			{"pop", pop_s},
			{"add", add_s},
			{ NULL, NULL },
		};

	/* NON-INTERACTIVE MODE */
	/* if (argv[1])
	{ */
		/* Open the monte file as read only */
		/* fp = fopen(argv[1], "r"); */

		/* Check if file open failed */
		/* if (!fp)
			fprintf(stderr, "Error: cannot open file\n"), exit(EXIT_FAILURE);
	}*/

	/* INTERACTIVE MODE */
	while (GETLINE >= 0)
	{
		buf[bytes - 1] = '\0'; /* Replace \n with '\0' */

		for (index = 0, tokens = strtok(buf, " "); tokens != NULL; index++)
			args[index] = tokens, tokens = strtok(NULL, " ");
		args[index] = NULL;

		for (index = 0; opcodes[index].opcode != NULL; index++)
		{
				/* Check if function exists in struct */
				if(strcmp(args[0], opcodes[index].opcode) == 0)
					opcodes[index].f(&head, line_count);

				/* Check if push exists and data has been given */
				else if (strcmp(args[0], "push") == 0)
					push_s(&head, line_count, INTDATA);
		}
		line_count++;
	}

	/* CLEANUP */
	free(buf)/* fclose(fp) */;
	return (0);
}
