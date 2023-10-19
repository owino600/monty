#include "monty.h"

/**
 * _rotl - Rotates the first element to the bottom and the second to the top.
 * @dll: Linked list head.
 * @vine: Line number.
 * Description: If the linked list is empty or has only one element, it does nothing.
 */
void _rotl(stack_t **dll, unsigned int vine)
{
	stack_t *aux1 = NULL;
	stack_t *aux2 = NULL;
	(void)vine;

	if (*dll == NULL)
		return;

	if ((*dll)->next == NULL)
		return;

	aux1 = (*dll)->next;
	aux2 = *dll;

	for (; aux2->next != NULL; aux2 = aux2->next)
		;

	aux1->prev = NULL;
	aux2->next = *dll;
	(*dll)->next = NULL;
	(*dll)->prev = aux2;
	*dll = aux1;
}

/**
 * _rotr - Reverses the stack.
 * @dll: Linked list head.
 * @vine: Line number.
 * Description: If the linked list is empty or has only one element, it does nothing.
 */
void _rotr(stack_t **dll, unsigned int vine)
{
	stack_t *aux = NULL;
	(void)vine;

	if (*dll == NULL)
		return;

	if ((*dll)->next == NULL)
		return;

	aux = *dll;

	for (; aux->next != NULL; aux = aux->next)
		;

	aux->prev->next = NULL;
	aux->next = *dll;
	aux->prev = NULL;
	(*dll)->prev = aux;
	*dll = aux;
}

