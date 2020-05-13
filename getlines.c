#include "monty.h"

void _getlines(char *opfile)
{
	unsigned int lines;
	char *fstream, *tok;
	stack_t **stack;
	stack = malloc(sizeof(char *));
	if (stack == NULL)
	{
		fprintf(stderr, "Error: failed to allocate memory\n");
		exit(EXIT_FAILURE);
	}
}

char *readfile(char *file)
{
	char ch;
	FILE *f;
	f = fopen(file, "r");
	if (fp == NULL)
	{
		fprintf(stderr, "Error while opening file.\n");
		exit(EXIT_FAILURE);
	}
	
