#include "monty.h"

#define PINT_F 	"L%d: can't pint, stack empty\n"
#define POP_F 	"L%d: can't pop an empty stack\n"
#define SWAP_F	"L%d: can't swap, stack too short\n"
#define CALC_F 	"L%d: can't %s, stack too short\n"
#define ZERO 	"L%d: division by zero\n"

/**
 * pop_s - pops from top of stack
 * @stack: double pointer to stack
 * @line_number: line count
 * Return: Always void
 */

void pop_s(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;

	if (stack == NULL || *stack == NULL)
		dprintf(2, POP_F, line_number), rip('f');

	/* Move head to the next node while old head's in temp */
	*stack = temp->next;
	if (*stack != NULL)
		(*stack)->prev = NULL;

	free(temp); /* Free the old head */
}

/**
 * swap_s - swaps data between the first two nodes
 * @stack: doubly linked list
 * @line_number: contains the line number
 * Return: Always Void
 */
void swap_s(stack_t **stack, unsigned int line_number)
{
	int firstnodedata, secondnodedata;
	stack_t *temp = *stack;

	/* While two nodes exist, swap the data */
	if (temp && temp->next)
	{
		/* Pull the values from the two nodes */
		firstnodedata = temp->n;
		secondnodedata = temp->next->n;

		/* Then swap them */
		temp->n = secondnodedata, temp->next->n = firstnodedata;
	}
	else
		dprintf(2, SWAP_F, line_number), rip('f');
}

/**
 * pint_s - prints the value of the head node
 * @stack: doubly linked list
 * @line_number: line number
 * Return: Always void
 */
void pint_s(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
		dprintf(2, PINT_F, line_number), rip('f');
	else
		dprintf(1, "%d\n", (*stack)->n);
}

/**
 * calc_s -  divides all the very last two elements added
 * to the stack
 * @line_number: line_number for errors
 * @stack: doubly linked list
 */
void calc_s(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;
	int secondlast, last;
	int total;
	int ncount;

	for (ncount = 0; temp != NULL; temp = temp->next, ncount++)
		;

	/* Check if we have two nodes to add */
	if (stack == NULL || *stack == NULL || ncount < 2)
		dprintf(2, CALC_F, line_number, univ.funcstr), rip('f');

	/* Pull the values from the last two nodes, then add */
	secondlast = (*stack)->next->n, last = (*stack)->n;

	if (strcmp("div", univ.funcstr) == 0 || strcmp("mod", univ.funcstr) == 0)
	{
		/* Check if the top stack has 0 */
		if (last == 0)
			dprintf(2, ZERO, line_number), rip('f');
	}

	if (strcmp("div", univ.funcstr) == 0)
		total = secondlast / last;
	else if (strcmp("mod", univ.funcstr) == 0)
		total = secondlast % last;
	else if (strcmp("add", univ.funcstr) == 0)
		total = secondlast + last;
	else if (strcmp("sub", univ.funcstr) == 0)
		total = secondlast - last;
	else if (strcmp("mul", univ.funcstr) == 0)
		total = secondlast * last;

	/* Free the node */
	temp = (*stack)->next;
	pop_s(stack, line_number);
	(*stack)->n = total;
}
