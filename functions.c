#include "monty.h"

/**
 * add_dintnode_end - Adds a node at the end of the doubly linked list.
 *
 * @head: The first position of the linked list.
 * @n: Data to store in the node.
 * Return: A doubly linked list.
 */
stack_t *add_dintnode_end(stack_t **head, const int n)
{
	stack_t *temp, *aux;

	if (head == NULL)
		return (NULL);
	temp = malloc(sizeof(stack_t));
	if (!temp)
	{
		dprintf(2, "Error: malloc failed\n");
		free_myglo();
		exit(EXIT_FAILURE);
	}
	temp->n = n;
	/* Handle the first time */
	if (*head == NULL)
	{
		temp->next = *head;
		temp->prev = NULL;
		*head = temp;
		return (*head);
	}
	aux = *head;
	while (aux->next)
		aux = aux->next;
	temp->next = aux->next;
	temp->prev = aux;
	aux->next = temp;
	return (aux->next);
}

/**
 * add_dintnode - Adds a node at the beginning of the dll
 *
 * @head: The first position of the linked list.
 * @n: Data to store in the node.
 * Return: A doubly linked list.
 */
stack_t *add_dintnode(stack_t **head, const int n)
{
	stack_t *temp;

	if (head == NULL)
		return (NULL);
	temp = malloc(sizeof(stack_t));
	if (!temp)
	{
		dprintf(2, "Error: malloc failed\n");
		free_myglo();
		exit(EXIT_FAILURE);
	}
	temp->n = n;
	/* Handle the first time */
	if (*head == NULL)
	{
		temp->next = *head;
		temp->prev = NULL;
		*head = temp;
		return (*head);
	}
	(*head)->prev = temp;
	temp->next = (*head);
	temp->prev = NULL;
	*head = temp;
	return (*head);
}

/**
 * free_dlistint - Frees the dll.
 *
 * @head: Head of the list.
 * Return: No return.
 */
void free_dlistint(stack_t *head)
{
	stack_t *tmp;

	while ((tmp = head) != NULL)
	{
		head = head->next;
		free(tmp);
	}
}

