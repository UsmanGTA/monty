#include "monty.h"

#define INTERPRETER argv[0] /* INTERPRETER */
#define PROGRAM argv[1] /* PROGRAM */
#define CMD args[0] /* push/pint/pall/nop */
#define DATA args[1] /* Used for push */
#define OPEN_F "Error: cannot open file %s\n"
#define BADCMD_F "%d: unknown instruction %s\n"

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
	char *tokens, *args[64];
	size_t bufSize = 0;
	int index, flag; /* Flag resets to 0 to check if any program was executed */
	ssize_t bytes;
	stack_t *head = NULL;
	FILE *fp = fopen(PROGRAM, "r");
	/* instruction_t opcodes[] = {
			{"pall", pall_s},
			{"pop", pop_s},
			{"add", add_s},
			{"pint", pint_s},
			{"swap", swap_s},
			{ NULL, NULL },
		}; */

	if (argc != 2)
		dprintf(2, "USAGE: monty file\n"), exit(EXIT_FAILURE);

	if (fp == NULL)
		dprintf(2, OPEN_F, argv[1]);

	/* EXECUTION LOOP BEGINS */
	while (1)
	{
		bytes = getline(&buf, &bufSize, fp);
		if (bytes >= 0)
			buf[bytes - 1] = '\0';
		else
			break;

		/* Generate argvs */
		for (index = 0, tokens = strtok(buf, " "); tokens != NULL; index++)
			args[index] = tokens, tokens = strtok(NULL, " ");
		args[index] = NULL;

		if (args[0][0] == '#')
				continue;
	
		/* Search if function exists, then execute */
		for (index = 0; opcodes[index].opcode != NULL; index++)
		{
			/* Check if function exists in struct */
			if (strcmp(CMD, opcodes[index].opcode) == 0)
				opcodes[index].f(&head, line_count), flag = 1, printf("GOOD\n");

			/* Check if push exists and data has been given */
			else if (strcmp(CMD, "push") == 0)
			{
				push_s(&head, line_count, DATA), flag = 1;
				break;
			}
		}
		if (flag == 0) /* Check if flag flipped, if not, cmd not found */
			dprintf(2, BADCMD_F, line_count, CMD), exit(EXIT_FAILURE);
		/* Reset flag = 0 to give functions another chance, then line++ */
		flag = 0, line_count++;
	}

	/* CLEANUP */
	free(buf), free_stack(head), fclose(fp);
	return (0);
}
