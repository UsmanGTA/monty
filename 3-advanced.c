#include "monty.h"

#define PCHAR_F 		"L%d: can't pchar, stack empty\n"
#define PCHAR_ASCII_F 	"L%d: can't pchar, value out of range\n"
#define ASCIIMAX 		127
#define ASCIIMIN 		0

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
		dprintf(2, PCHAR_F, line_number), rip('f');

	if ((*stack)->n >= ASCIIMIN && (*stack)->n <= ASCIIMAX)
		dprintf(1, "%c\n", (*stack)->n);
	else
		dprintf(2, PCHAR_ASCII_F, line_number), rip('f');
}

/**
 * pstr_s - prints string
 * @stack: double pointer to stack
 * @line_number: line count unused
 * Return: Always void
 */
void pstr_s(stack_t **stack, __attribute__((unused))unsigned int line_number)
{
	stack_t *temp;

	if (*stack == NULL)
		dprintf(1, "\n"), rip('f');

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
