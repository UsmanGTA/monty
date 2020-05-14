#include "monty.h"
#define PCHAR_F "L%d: can't pchar, stack empty\n"
#define PCHAR_ASCII_F "L%d: can't pchar, value out of range\n"
/**
 * pint_s - prints the value of the head node
 * @stack: doubly linked list
 * @line_number: line number
 * Return: Always void
 */
void pchar_s(stack_t **stack, unsigned int line_number)
{
	/* Check if stack's null */
	if (*stack == NULL)
		dprintf(2, PCHAR_F, line_number), exit(EXIT_FAILURE);
		
	/* Extract the value from the stack & print if its an ASCII */
	if ((*stack)->n < 127 && (*stack)->n > 0)
		dprintf(1, "%c\n", (*stack)->n);

	/* If not an ASCII, fail */
	else
		dprintf(2, PCHAR_ASCII_F, line_number);
}
