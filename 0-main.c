#include "monty.h"

#define INTERPRETER argv[0] /* INTERPRETER */
#define PROGRAM argv[1] /* PROGRAM */
#define CMD args[0] /* push/pint/pall/nop */
#define DATA args[1] /* Used for push */
#define OPEN_F "Error: cannot open file %s\n"
#define BADCMD_F "%d: unknown instruction %s\n"

char *data = NULL;

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
	ssize_t index, flag, bytes;
	stack_t *head = NULL;
	unsigned int line_count = 0;
	FILE *fp;
	instruction_t opcodes[] = {
		{"pall", pall_s}, {"pop", pop_s}, {"add", add_s}, {"pint", pint_s},
		{"swap", swap_s}, {"sub", sub_s}, {"mul", mul_s}, {"div", div_s},
		{"mod", mod_s}, {"pchar", pchar_s}, {"pstr", pstr_s}, {"push", push_s}
	};
	if (argc != 2)
		dprintf(2, "USAGE: monty file\n"), exit(EXIT_FAILURE);
	if (access(PROGRAM, R_OK) == -1)
		dprintf(2, OPEN_F, argv[1]), exit(EXIT_FAILURE);
	fp = fopen(PROGRAM, "r");
	if (fp == NULL)
		dprintf(2, "Error: malloc failed\n"), exit(EXIT_FAILURE);
	while ((bytes = getline(&buf, &bufSize, fp)) != -1)
	{
		line_count++, buf[bytes - 1] = '\0';
		args[0] = strtok(buf, " "), args[1] = strtok(NULL, " "); data = DATA;
		if (args[0][0] == '#' || args[0] == NULL)
			continue;

		for (index = 0; index < 12; index++)
			if (strcmp(CMD, opcodes[index].opcode) == 0)
				opcodes[index].f(&head, line_count), flag = 1;

		if (flag == 0) /* Check if flag flipped, if not, cmd not found */
			dprintf(2, BADCMD_F, line_count, CMD), exit(EXIT_FAILURE);
		flag = 0, /* Reset flag to check next loop */
	}
	free(buf), free_stack(head), fclose(fp);
	return (0);
}
