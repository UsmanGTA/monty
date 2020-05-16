#include "monty.h"

#define MALLOC_F "Error: malloc failed\n"
#define EMPTYSTACK "L%d: usage: push integer\n"
#define MISSINGDATA "L%d: usage: push integer\n"
#define CANTADD "L%d: can't add, stack too short\n"
#define PINT_F "L%d: can't pint, stack empty\n"
#define POP_F "L%d: can't pop an empty stack\n"

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
		dprintf(2, POP_F, line_number), rip();

	/* Move head to the next node while old head's in temp */
	*stack = temp->next;
	if (*stack != NULL)
		(*stack)->prev = NULL;

	free(temp); /* Free the old head */
}

/**
 * add_s - adds the very last two nodes added to the stack
 * then frees both of them
 * @stack: doubly linked list
 * @line_number: line number
 * Return: Void Always
 */
void add_s(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack; /* *secondlastnode, *lastnode; */
	int secondlast, last;
	int total;
	int nodecount;

	for (temp = *stack, nodecount = 0; temp != NULL;
	     temp = temp->next, nodecount++)
		;

	/* Check if we have two nodes to add */
	if (stack == NULL || *stack == NULL || nodecount < 2)
	{
		dprintf(2, CANTADD, line_number);
		free_stack(*stack), fclose(univ.fp);
		free(univ.buf), exit(EXIT_FAILURE);
	}
	/* Pull the values from the last two nodes, then add */
	secondlast = (*stack)->next->n, last = (*stack)->n;
	total = secondlast + last;
	temp = (*stack)->next;
	      pop_s(stack, line_number);
	      (*stack)->n = total;
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
	{
		dprintf(2, "L%d: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
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
		dprintf(2, PINT_F, line_number), exit(EXIT_FAILURE);
	else
		dprintf(1, "%d\n", (*stack)->n);
}
