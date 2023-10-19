#include "monty.h"

/**
 * monty_pint - Print the value at the top of the stack, followed by a new line.
 * @stack: Double pointer to the stack
 * @line_number: Line number in the script file
 */
void monty_pint(stack_t **stack, unsigned int line_number)
{
	if (!stack || !(*stack)) {
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
		set_op_tok_error(EXIT_FAILURE);
		return;
	}

	printf("%d\n", (*stack)->n);
}
