#include "monty.h"

#define CANTADD "L%d: can't add, stack too short\n"
#define EMPTYSTACK "L%d: usage: push integer\n"
#define MALLOC_F "Error: malloc failed\n"
#define MISSINGDATA "L%d: usage: push integer\n"
#define FREEALL (free(bag.buf), fclose(bag.fp), exit(EXIT_FAILURE))
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
	stack_t *da_new_king = malloc(sizeof(stack_t)); /* Our new node */
	int n, i;

	if (da_new_king == NULL)
		dprintf(2, MALLOC_F), exit(EXIT_FAILURE);
	if (bag.data == NULL)
	{
		dprintf(2, MISSINGDATA, line_number);
		free(da_new_king), free_stack(*stack), FREEALL;
	}
	else if (strcmp(bag.data, "0") == 0)
		n = 0;
	for (i = 0; bag.data[i] != '\0'; i++)
		if ((bag.data[i] >= '0' && bag.data[i] <= '9') || bag.data[i] == '-')
			continue;
		else
		{
			dprintf(2, MISSINGDATA, line_number),
			free(da_new_king), free_stack(*stack), FREEALL;
		}
	n = atoi(bag.data);
	/* Populating data into the new node */
	da_new_king->n = n;
	da_new_king->prev = NULL;
	if (*stack == NULL)
	{
		da_new_king->next = NULL; /* Terminate the linked list */
		*stack = da_new_king; /* Copy new node to *head */
	}
	else
	{
		da_new_king->next = temp; /* Else our new node should point to head */
		temp->prev = da_new_king; /*Point the next node->prev to the new head node */
		*stack = da_new_king; /* Our new node is now the head */
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
