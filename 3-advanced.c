#include "monty.h"

#define SUB_F "L%d: can't sub, stack too short\n"
#define DIV_F "L%d: can't div, stack too short\n"
#define DIV_ZERO "L%d: division by zero\n"
#define MUL_F "L%d: can't mul, stack too short\n"
#define MOD_F "L%d: can't mod, stack too short\n"
#define MOD_ZERO "L%d: division by zero\n"

/**
 * sub_s - subtracts the very last two elements
 * on the stack, and then returns
 * @line_number: line_number
 * @stack: doubly linked list
 * Return: Always void
 */
void sub_s(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;
	int secondlast, last;
	int total;
	int nodecount;

	for (temp = *stack, nodecount = 0; temp != NULL;
	     temp = temp->next, nodecount++)
		;

	/* Check if we have two nodes to add */
	if (stack == NULL || *stack == NULL || nodecount < 2)
	{
		dprintf(2, SUB_F, line_number);
		free(stack);
		exit(EXIT_FAILURE);
	}
	/* Pull the values from the last two nodes, then add */
	secondlast = (*stack)->next->n, last = (*stack)->n;

	/* Complete the subtraction operation */
	total = secondlast - last;

	/* Free the node */
	temp = (*stack)->next;
	      pop_s(stack, line_number);
	      (*stack)->n = total;
}

/**
 * div_s -  divides all the very last two elements added
 * to the stack
 * @line_number: line_number for errors
 * @stack: doubly linked list
 */
void div_s(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;
	int secondlast, last;
	int total;
	int nodecount;

	for (temp = *stack, nodecount = 0; temp != NULL;
	     temp = temp->next, nodecount++)
		;

	/* Check if we have two nodes to add */
	if (stack == NULL || *stack == NULL || nodecount < 2)
	{
		dprintf(2, DIV_F, line_number);
		free_stack(*stack), fclose(bag.fp);
		free(bag.buf), exit(EXIT_FAILURE);
	}
	/* Pull the values from the last two nodes, then add */
	secondlast = (*stack)->next->n, last = (*stack)->n;

	/* Check if the top stack has 0 */
	if (last == 0)
		dprintf(2, DIV_ZERO, line_number), exit(EXIT_FAILURE);

	/* Complete the division operation */
	total = secondlast / last;

	/* Free the node */
	temp = (*stack)->next;
	      pop_s(stack, line_number);
	      (*stack)->n = total;
}

/**
 * mul_s - multiplies the very last two nodes
 * @line_number: line number
 * @stack: doubly linked list
 * Return: Always void
 */
void mul_s(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;
	int secondlast, last;
	int total;
	int nodecount;

	for (temp = *stack, nodecount = 0; temp != NULL;
	     temp = temp->next, nodecount++)
		;

	/* Check if we have two nodes to add */
	if (stack == NULL || *stack == NULL || nodecount < 2)
	{
		dprintf(2, MUL_F, line_number);
		free_stack(*stack), fclose(bag.fp);
		free(bag.buf), exit(EXIT_FAILURE);
	}
	/* Pull the values from the last two nodes, then add */
	secondlast = (*stack)->next->n, last = (*stack)->n;

	/* Complete the multiplication operation */
	total = secondlast * last;

	/* Free the node */
	temp = (*stack)->next;
	      pop_s(stack, line_number);
	      (*stack)->n = total;
}

/**
 * mod_s -  divides all the very last two elements added
 * to the stack
 * @line_number: line_number for errors
 * @stack: doubly linked list
 */
void mod_s(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;
	int secondlast, last;
	int total;
	int nodecount;

	for (temp = *stack, nodecount = 0; temp != NULL;
	     temp = temp->next, nodecount++)
		;

	/* Check if we have two nodes to add */
	if (stack == NULL || *stack == NULL || nodecount < 2)
	{
		dprintf(2, MOD_F, line_number);
		free_stack(*stack), fclose(bag.fp);
		free(bag.buf), exit(EXIT_FAILURE);
	}
	/* Pull the values from the last two nodes, then add */
	secondlast = (*stack)->next->n, last = (*stack)->n;

	/* Check if the top stack has 0 */
	if (last == 0)
		dprintf(2, MOD_ZERO, line_number), exit(EXIT_FAILURE);

	/* Complete the division operation */
	total = secondlast % last;

	/* Free the node */
	temp = (*stack)->next;
	      pop_s(stack, line_number);
	      (*stack)->n = total;
}
