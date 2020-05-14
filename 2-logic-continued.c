#include "monty.h"

#define CANTADD "L%d: can't add, stack too short\n"
#define EMPTYSTACK "L%d: usage: push integer\n"
#define MALLOC_F "Error: malloc failed\n"
#define MISSINGDATA "L%d: usage: push integer\n"

/**
 * push_s - pushes an integer to the stack
 * with the help of malloc and a doubly
 * linked list
 * @stack: doubly linked list
 * @line_number: linenumber
 * @data: integer to add into the linked list
 * Return: Always void
 */

stack_t *push_s(stack_t **stack, unsigned int line_number, char *data)
{
	stack_t *temp = *stack; /* Stores the address of head */
	stack_t *da_new_king = malloc(sizeof(stack_t)); /* Our new node */

	/* Check if malloc failed | atoi failed  */
	if (da_new_king == NULL)
	{
		dprintf(2, MALLOC_F);
		free(da_new_king), exit(EXIT_FAILURE);
	}
	if (data == NULL)
		dprintf(2, MISSINGDATA, line_number), exit(EXIT_FAILURE);

	/* Populating data into the new node */
	da_new_king->n = atoi(data);
	da_new_king->prev = NULL;

	/* If *head's empty, then set our newnode */
	/* to be the head with prev and next == NULL */
	if (*stack == NULL)
	{
		da_new_king->next = NULL; /* Terminate the linked list */
		*stack = da_new_king;/* Copy new node to *head */
		return (*stack);
	}

	/* Since our new node's supposed to become the head */
	/* the next node is the only variable to play with */
	/* If head wasn't null, now's the time to connect it */
	else
	{
		da_new_king->next = temp; /* Else our new node should point to head */
		temp->prev = da_new_king; /*Point the next node->prev to the new head node */
		*stack = da_new_king; /* Our new node is now the head */
		return (*stack);
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

	if (stack == NULL || *stack == NULL)
	{
		dprintf(2, EMPTYSTACK, line_number);
	}
	for (temp = *stack; temp != NULL; temp = temp->next)
		printf("%d\n", temp->n);
}

/**
 * nop - opcode that doesn't do anythin
 * @stack: stack to be evaluated
 * @line_number: line count
 * Return: always void
 */

void nop(__attribute((unused))stack_t **stack,
	 __attribute((unused))int line_number)
{
	;
}

