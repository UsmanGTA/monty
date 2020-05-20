#include "monty.h"
#define PCHAR_F "L%d: can't pchar, stack empty\n"
#define PCHAR_ASCII_F "L%d: can't pchar, value out of range\n"
#define ASCIIMAX 127
#define ASCIIMIN 0

/**
 * pchar_s - prints the value of the head node
 * @stack: doubly linked list
 * @line_number: line number
 * Return: Always void
 */
void pchar_s(stack_t **stack, unsigned int line_number)
{
	/* Check if stack's null */
	if (*stack == NULL)
		dprintf(2, PCHAR_F, line_number), free_stack(*stack), rip();

	/* Extract the value from the stack & print if its an ASCII */
	if ((*stack)->n >= ASCIIMIN && (*stack)->n <= ASCIIMAX)
		dprintf(1, "%c\n", (*stack)->n);

	/* If not an ASCII, fail */
	else
		dprintf(2, PCHAR_ASCII_F, line_number);
}

/**
 * pstr_s - prints string
 * @stack: double pointer to stack
 * @line_number: line count unused
 * Return: Always void
 */
void pstr_s(stack_t **stack, __attribute((unused))unsigned int line_number)
{
	stack_t *temp;

	/* If stack == NULL, print new line */
	if (*stack == NULL)
	{
		dprintf(1, "\n"), free_stack(*stack), fclose(univ.fp);
		free(univ.buf), exit(EXIT_FAILURE);
	}

	/* If the stack isn't empty and has valid ASCII values, then print */
	for (temp = *stack; temp != NULL || temp->n != 0; temp = temp->next)
	{
		if ((*stack)->n >= ASCIIMIN && (*stack)->n <= ASCIIMAX)
			dprintf(1, "%c", temp->n);
		else					/* Bad ASCII value should break it */
			break;
	}
	dprintf(1, "\n");
}
