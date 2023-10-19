#include "monty.h"

/**
 * _add - Adds the top two values of a stack_t linked list.
 * @doubly: Head of the linked list.
 * @cline: Line number.
 * Description: The result is stored in the second value node
 * from the top, and the top value is removed.
 */
void _add(stack_t **dll, unsigned int vine)
{
	int k = 0;
	stack_t *aux = NULL;

	aux = *dll;

	for (; aux != NULL; aux = aux->next, k++)
		;

	if (k < 2)
	{
		dprintf(2, "L%u: can't add, stack too short\n", vine);
		free_myglo();
		exit(EXIT_FAILURE);
	}

	aux = (*dll)->next;
	aux->n += (*dll)->n;
	_pop(dll, vine);
}

/**
 * _nop - Does nothing.
 * @doubly: Linked list head.
 * @vine: Line number.
 */
void _nop(stack_t **dll, unsigned int vine)
{
	(void)dll;
	(void)vine;
}

/**
 * _sub - Subtracts the second value from the top of stack_t linked list by the top value.
 * @head: The head node.
 * @vine: The line number.
 * Description: The result is stored in the second value node
 * from the top, and the top value is removed.
 */
void _sub(stack_t **head, unsigned int vine)
{
	int k = 0;
	stack_t *current;

	current = *head;

	for (; current != NULL; current = current->next, k++)
		;

	if (k < 2)
	{
		dprintf(2, "L%u: can't sub, stack too short\n", vine);
		free_myglo();
		exit(EXIT_FAILURE);
	}

	current = (*head)->next;
	current->n -= (*head)->n;
	_pop(head, vine);
}

/**
 * _div - Divides the second value from the top of the stack_t linked list by the top value.
 * @dll: Head of the linked list.
 * @vine: Line number.
 * Return: No return.
 */
void _div(stack_t **dll, unsigned int vine)
{
	int k = 0;
	stack_t *aux = NULL;

	aux = *dll;

	for (; aux != NULL; aux = aux->next, k++)
		;

	if (k < 2)
	{
		dprintf(2, "L%u: can't div, stack too short\n", vine);
		free_myglo();
		exit(EXIT_FAILURE);
	}

	if ((*dll)->n == 0)
	{
		dprintf(2, "L%u: division by zero\n", vine);
		free_myglo();
		exit(EXIT_FAILURE);
	}

	aux = (*dll)->next;
	aux->n /= (*dll)->n;
	_pop(dll, vine);
}

/**
 * _mul - Multiplies the second value from the top of the stack_t linked list by the top value.
 * @head: The head node.
 * @vine: The line number.
 * Description: The result is stored in the second value node
 * from the top, and the top value is removed.
 */
void _mul(stack_t **head, unsigned int vine)
{
	int k = 0;
	stack_t *current;

	current = *head;

	for (; current != NULL; current = current->next, k++)
		;

	if (k < 2)
	{
		dprintf(2, "L%u: can't mul, stack too short\n", vine);
		free_myglo();
		exit(EXIT_FAILURE);
	}

	current = (*head)->next;
	current->n *= (*head)->n;
	_pop(head, vine);
}
