#include "monty.h"


void freestack(stack_t *bottom)
{
	while (bottom != NULL)
	{
		free(bottom);
		bottom = bottom->next;
	}
	while (bottom != NULL)
	{
		free(bottom);
		bottom = bottom->prev;
	}
}
