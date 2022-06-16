#include "monty.h"

/**
 * add_dnodeint - add a node at the begginning of the doubly linked list.
 * @head: first position of linked list.
 * @n: data to store
 *
 * Return: a doubly linked list.
 */
stack_t *add_dnodeint(stack_t **head, const int n)
{
	stack_t *tmp;

	if (head == NULL)
		return (NULL);
	tmp = malloc(sizeof(stack_t));

	if (!tmp)
	{
		dprintf(2, "Error: malloc failed\n");
		free_glob_v();
		exit(EXIT_FAILURE);
	}
	tmp->n = n;

	if (*head == NULL)
	{
		tmp->next = *head;
		tmp->prev = NULL;
		*head = tmp;
		return (*head);
	}
	(*head)->prev = tmp;
	tmp->next = (*head);
	tmp->prev = NULL;
	*head = tmp;
	return (*head);
}

/**
 * free_dlistint - frees the doubly linked list.
 *
 * @head: head of the list
 * Return: no return.
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
