#include "monty.h"

#define INTERPRETER argv[0] /* INTERPRETER */
#define PROGRAM argv[1] /* PROGRAM */
#define CMD args[0] /* push/pint/pall/nop */
#define DATA args[1] /* Used for push */
#define OPEN_F "Error: cannot open file %s\n"
#define BADCMD_F "L%d: unknown instruction %s\n"

global_data univ = {NULL, NULL, NULL};

/**
 * main - gets lines from bytecode file
 * @argc: number of arguments
 * @argv: argument vector
 * Return: always 0
 */
int main(int argc, char **argv)
{
	char *buf = NULL, *args[2];
	size_t bufSize = 0;
	ssize_t index, flag = 0, bytes;
	stack_t *head = NULL;
	unsigned int line_num = 0;
	FILE *fp;
	instruction_t func[] = {
		{"pall", pall_s}, {"pop", pop_s}, {"add", add_s}, {"nop", nop_s},
		{"pint", pint_s}, {"swap", swap_s}, {"sub", sub_s}, {"mul", mul_s},
		{"div", div_s}, {"mod", mod_s}, {"pchar", pchar_s}, {"pstr", pstr_s},
		{"push", push_s},
	};
	
	/* FILE OPERATIONS */
	if (argc != 2)
		dprintf(2, "USAGE: monty file\n"), exit(EXIT_FAILURE);
	if (access(PROGRAM, R_OK) == -1)
		dprintf(2, OPEN_F, argv[1]), exit(EXIT_FAILURE);
	fp = fopen(PROGRAM, "r");
	if (fp == NULL)
		dprintf(2, "Error: malloc failed\n"), exit(EXIT_FAILURE);
	univ.fp = fp; /* If all the above tests passed, assign fp */

	/* EXECUTION LOOP */
	while ((bytes = getline(&buf, &bufSize, fp)) != -1)
	{
		buf[bytes - 1] = '\0', univ.buf = buf, line_num++;
		args[0] = strtok(buf, " ");
		if (args[0] == NULL || args[0][0] == '#')
			continue;
		args[1] = strtok(NULL, " "), univ.data = DATA;
		for (index = 0; index < 13; index++)
			if (strcmp(CMD, func[index].opcode) == 0)
				func[index].f(&head, line_num), flag = 1;
		if (flag == 0) /* Check if flag flipped, if not, cmd not found */
		{
			dprintf(2, BADCMD_F, line_num, CMD),
			free_stack(head), free(buf), fclose(fp), exit(EXIT_FAILURE);
		}
		flag = 0; /* Reset flag to check next loop */
	}
	free_stack(head), rip();
	return (0);
}
