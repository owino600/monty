#include "monty.h"

/**
 * monty_push - Pushes an element onto the stack.
 * @stack: A pointer to the stack.
 * @line_number: The line number in the Monty file.
 */
void monty_push(stack_t **stack, unsigned int line_number)
{
	int value;
	stack_t *new_node;

	if (op_toks[1] == NULL || !is_valid_int(op_toks[1]))
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		set_op_tok_error(1);
		return;
	}

	value = atoi(op_toks[1]);
	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		malloc_error();
		return;
	}

	new_node->n = value;
	new_node->prev = NULL;
	new_node->next = *stack;

	if (*stack != NULL)
		(*stack)->prev = new_node;

	*stack = new_node;
}

/**
 * monty_pall - Prints all values on the stack.
 * @stack: A pointer to the stack.
 * @line_number: The line number in the Monty file.
 */
void monty_pall(stack_t **stack, unsigned int line_number __attribute__((unused)))
{
	stack_t *current = *stack;

	while (current != NULL)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}

