#include "monty.h"

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
	FILE *fp;

	if (argv[2] == NULL)
		isatty(STDIN_FILENO);

	fp = fopen(argv[1], "r");
	if (!fp)
	{
		fprintf(stderr, "Error: cannot open file\n");
		return (EXIT_FAILURE);
	}
	rd = getline(&buf, &bufSize, fp);
	while (rd >= 0)
	{
		line_count++;
		rd = getline(&buf, &bufSize, fp);
	}
	free(buf);
	buf = NULL;
	fclose(fp);
	printf("linecount: %d\n", line_count);
	return (0);
}
