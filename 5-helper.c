#include "monty.h"

/**
 * free_stack - frees the stack
 * @head: head doubly
 * Return: Void
 */
void free_stack(stack_t *head)
{
	stack_t *temp;

	while (head != NULL)
	{
		temp = head;
		head = head->next;
		free(temp);
	}
}
