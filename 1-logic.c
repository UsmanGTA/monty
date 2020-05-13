#include <stdio.h>
#include "monty.h"

#define MALLOC_F "Error: malloc failed\n"
#define EMPTYSTACK "%d: usage: push integer\n"
#define MISSINGDATA "%d: usage: push integer\n"
#define CANTADD "%d: can't add, stack too short\n"
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
		dprintf(2, EMPTYSTACK, line_number);

	for(temp = *stack; temp != NULL; temp = temp->next)
		printf("%d\n", temp->n);
}

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
	int n = atoi(data);

	/* Check if malloc failed | atoi failed  */
	if (da_new_king == NULL)
		dprintf(2, MALLOC_F), free(da_new_king), exit(EXIT_FAILURE);
	if (n == 0)
		dprintf(2, MISSINGDATA, line_number), exit(EXIT_FAILURE);

	/* Populating data into the new node */
	da_new_king->n = n;
	da_new_king->prev = NULL;

	/* If *head's empty, then set our newnode */
	/* to be the head with prev and next == NULL */
	if (*stack == NULL)
	{
		da_new_king->next = NULL; /* Terminate the linked list */
		*stack = da_new_king; /* Copy new node to *head */
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
 * pop_s - deletes the very last node added on the stack
 * @stack: doubly linked list
 * @line_number: line_number
 * Return: Always 0
 */
void pop_s(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;
	stack_t *prevnode;
	if (stack == NULL || *stack == NULL)
		dprintf(1, "%d: can't pop an empty stack", line_number), exit(EXIT_FAILURE);

	for (temp = *stack; temp != NULL; temp = temp->next)
		;

	prevnode = temp->prev, prevnode->next = NULL; /* Disconnect from the last node */
	free(temp); /* Free the last node */
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
	stack_t *temp, *secondlastnode, *lastnode;
	int secondlast, last;
	int total;
	int nodecount;

	for (temp = *stack, nodecount = 0; temp != NULL; temp = temp->next, nodecount++)
		;
	
	/* Check if we have two nodes to add */
	if (nodecount < 1)
		dprintf(2, CANTADD, line_number), exit(EXIT_FAILURE);

	/* Pull the values from the last two nodes, then add */
	secondlast = temp->prev->n, last = temp->n;
	total = secondlast + last;

	dprintf(1, "%d\n", total);

	/* Free both of the added nodes */
	temp->prev->prev->next = NULL; /* Disconnect the nodes */
	secondlastnode = temp->prev;
	lastnode = temp;
	free(lastnode);
	free(secondlastnode);
}
