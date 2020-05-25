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
 * @error: pulls in the character
 * to determine whether EXIT_FAILURE,
 * if error pulls in 'f' then exit_f
 * else, success
 */
void rip(char error)
{
	if (univ.buf != NULL)
		free(univ.buf);
	if (univ.fp != NULL)
		fclose(univ.fp);
	if (univ.stack != NULL)
		free_stack(univ.stack);
	if (error == 'f')
		exit(EXIT_FAILURE);
}
