#include "monty.h"

/**
 * free_stack - frees the stack
 * @head: doubly linked list
 * Return: Always Void
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

/**
 * rip - cleans out everything in
 * the struct, with an effective
 * exit statement included following
 * successful operations.
 * @stack
 */
void rip(void)
{
	if (univ.buf || univ.fp)
	{
		if (univ.buf != NULL)
			free(univ.buf);
		if (univ.fp != NULL)
			fclose(univ.fp);
	}
	exit(EXIT_FAILURE);
}
