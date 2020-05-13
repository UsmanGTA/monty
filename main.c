#include "monty.h"

#define CHUNK 1024
int main(int ac, char **av)
{
	char str_buf[CHUNK];
	FILE *fp;
	size_t nread;
	char *newBuf;
	fp = fopen(av[1], "r");
	if (fp == NULL)
	{
		perror("error while opening\n");
		exit(EXIT_FAILURE);
	}
	if (fp)
	{
		if (nread = fread(str_buf, sizeof(char), CHUNK, fp) < 0)
		{
			fprintf(stderr, "Error: Can't open file");
			exit(EXIT_FAILURE);
		}
		else	
			str_buf[nread] = '\0';
	}
	newBuf = str_buf;
	fclose(fp);
	return (0);
}
