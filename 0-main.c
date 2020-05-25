#include "monty.h"

#define LOGICFILE 	argv[1] /* LOGICFILE */
#define OPCODE 		args[0] /* push/pint/pall/nop */
#define DATA 		args[1] /* Used for push */
#define OPEN_F 		"Error: Can't open file %s\n"
#define BADCMD_F 	"L%d: unknown instruction %s\n"
#define DELIM 		" \t\n\r\a"

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
		{"pall", pall_s}, {"pop", pop_s}, {"add", calc_s}, {"nop", nop_s},
		{"pint", pint_s}, {"swap", swap_s}, {"sub", calc_s}, {"mul", calc_s},
		{"div", calc_s}, {"mod", calc_s}, {"pchar", pchar_s}, {"pstr", pstr_s},
		{"push", push_s},
	};

	/* FILE OPERATIONS */
	if (argc != 2)
		dprintf(2, "USAGE: monty file\n"), exit(EXIT_FAILURE);
	if (access(LOGICFILE, R_OK) == -1)
		dprintf(2, OPEN_F, argv[1]), exit(EXIT_FAILURE);
	fp = fopen(LOGICFILE, "r");
	if (fp == NULL)
		dprintf(2, "Error: malloc failed\n"), exit(EXIT_FAILURE);
	univ.fp = fp; /* If all the above tests passed, assign fp */

	/* EXECUTION LOOP / BEGIN PULLING CMDs FROM FILE */
	while ((bytes = getline(&buf, &bufSize, fp)) != -1)
	{
		buf[bytes - 1] = '\0', univ.buf = buf, line_num++;
		OPCODE = strtok(buf, DELIM);
		if (OPCODE == NULL || OPCODE[0] == '#')
			continue;
		DATA = strtok(NULL, DELIM), univ.data = DATA;
		for (index = 0; index < 13; index++)
			if (strcmp(OPCODE, func[index].opcode) == 0)
				func[index].f(&head, line_num), univ.funcstr = OPCODE, flag = 1;
		if (flag == 0) /* Check if flag flipped, if not, cmd not found */
			dprintf(2, BADCMD_F, line_num, OPCODE), rip();
		flag = 0; /* Reset flag to check next loop */
	}
	rip();
	return (0);
}
