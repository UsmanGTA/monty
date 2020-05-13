#include "monty.h"

void _push(stack_t **stack, unsigned int n)
{
	stack_t *top;
	top = malloc(sizeof(stack_t));
	if (top == NULL)
	{
		fprintf(stderr, "Error: failed to allocate memory\n");
		freestack(stack);
		free(stack);
		exit(EXIT_FAILURE);
	}
	top->n = data;
	if (*stack != NULL)
	{
		(*stack)->prev = top;
		top->next = *stack;
	}
	else
		top->next = NULL;
	*stack = top;
}
