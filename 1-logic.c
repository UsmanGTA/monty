#include "monty.h"

#define CANTADD "L%d: can't add, stack too short\n"
#define MALLOC_F "Error: malloc failed\n"
#define PUSH_F "L%d: usage: push integer\n"
#define FREESTACK (free_stack(stack_t *stack))

/**
 * push_s - pushes an integer to the stack
 * with the help of malloc and a doubly
 * linked list
 * @stack: doubly linked list
 * @line_number: linenumber
 * Return: Always void
 */
void push_s(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack; /* Stores the address of head */
	stack_t *new = malloc(sizeof(stack_t)); /* Our new node */
	int n, i;

	if (new == NULL)
		dprintf(2, MALLOC_F), exit(EXIT_FAILURE);

	/* Set the value of n based off the following situations */
	if (univ.data == NULL)
		dprintf(2, PUSH_F, line_number), free(new), free_stack(*stack), rip();
	else if (strcmp(univ.data, "0") == 0)
		n = 0;
	else
	{
		dprintf(2, "L%d: can't pop an empty stack\n", line_number);
		free(bag.buf), fclose(bag.fp), exit(EXIT_FAILURE);
	}

	/* Populating data into the new node */
	new->n = n;
	new->prev = NULL;

	if (*stack == NULL)
		new->next = NULL, *stack = new;

	else
	{
		new->next = temp; /* Else our new node should point to head */
		temp->prev = new; /*Point the next node->prev to the new head node */
		*stack = new; /* Our new node is now the head */
	}
}

/**
 * pall_s - prints everything loaded onto the stack
 * @stack: doubly linked list
 * @line_number: for reference
 * Return: Always void
 */
void pall_s(stack_t **stack, unsigned int line_number)
{
	stack_t *temp; /** Temp pointer to move forward */

	(void)line_number; /* Voiding since var not in use */

	if (stack != NULL || *stack != NULL)
		for (temp = *stack; temp != NULL; temp = temp->next)
			dprintf(1, "%d\n", temp->n);
}

/**
 * nop_s - opcode that doesn't do anythin
 * @stack: stack to be evaluated
 * @line_number: line count
 * Return: always void
 */
void nop_s(stack_t **stack, unsigned int line_number)
{
	(void) stack;
	(void) line_number;
}
