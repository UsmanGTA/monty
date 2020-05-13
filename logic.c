#include <stdio.h>
#include "monty.h"

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
		return NULL

	for(temp = *stack; temp != NULL; temp = temp->next)
		printf("%d\n", temp->n);
}

/**
 * push_s - pushes an integer to the stack
 * with the help of malloc and a doubly
 * linked list
 * @stack: doubly linked list
 * Return: Always void
 */
void push_s(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack; /* Stores the address of head */
	stack_t *da_new_king = malloc(sizeof(dlistint_t)); /* Our new node */

	/* Check if malloc failed */
	if (da_new_king == NULL)
	{
		free(da_new_king);
		return (NULL);
	}

	/* Populating data into the new node */
	da_new_king->n = n;
	da_new_king->prev = NULL;

	/* If *head's empty, then set our newnode */
	/* to be the head with prev and next == NULL */
	if (*head == NULL)
	{
		da_new_king->next = NULL; /* Terminate the linked list */
		*head = da_new_king; /* Copy new node to *head */
		return (*stack);
	}

	/* Since our new node's supposed to become the head */
	/* the next node is the only variable to play with */
	/* If head wasn't null, now's the time to connect it */
	else
	{
		da_new_king->next = temp; /* Else our new node should point to head */
		temp->prev = da_new_king; /*Point the next node->prev to the new head node */
		*head = da_new_king; /* Our new node is now the head */
		return (*stack);
	}
}
