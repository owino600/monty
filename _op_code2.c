#include "monty.h"

/**
 * _mod - Computes the remainder of the division of the second element
 * by the top element of the stack.
 * @dll: Head of the linked list.
 * @vine: Line number.
 * Return: No return.
 * Description: The result is stored in the second value node from the top,
 * and the top value is removed.
 */
void _mod(stack_t **dll, unsigned int vine)
{
	int k = 0;
	stack_t *aux = NULL;

	aux = *dll;

	for (; aux != NULL; aux = aux->next, k++)
		;

	if (k < 2)
	{
		dprintf(2, "L%u: can't mod, stack too short\n", vine);
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
	aux->n %= (*dll)->n;
	_pop(dll, vine);
}

/**
 * _put_string - Prints the string of the stack.
 * @dll: Head of the linked list.
 * @vine: Line number.
 * Return: No return.
 */
void _put_string(stack_t **dll, unsigned int vine)
{
	stack_t *aux;
	(void)vine;

	aux = *dll;

	while (aux && aux->n > 0 && aux->n < 128)
	{
		printf("%c", aux->n);
		aux = aux->next;
	}

	printf("\n");
}

/**
 * _putchar - Prints the character value of the first element.
 * @dll: Head of the linked list.
 * @vine: Line number.
 * Return: No return.
 */
void _putchar(stack_t **dll, unsigned int vine)
{
	if (dll == NULL || *dll == NULL)
	{
		dprintf(2, "L%u: can't putchar, stack empty\n", vine);
		free_myglo();
		exit(EXIT_FAILURE);
	}
	if ((*dll)->n < 0 || (*dll)->n >= 128)
	{
		dprintf(2, "L%u: can't putchar, value out of range\n", vine);
		free_myglo();
		exit(EXIT_FAILURE);
	}
	printf("%c\n", (*dll)->n);
}
