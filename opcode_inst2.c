#include "monty.h"

/**
 * add - adds the top two elements of the stack.
 *
 * @head: head of the linked list
 * @nline: line number
 * Return: nothing
 */
void add(stack_t **head, unsigned int nline)
{
	int i = 0;
	stack_t *ptr = NULL;

	ptr = *head;

	for (; ptr != NULL; ptr = ptr->next, i++)
		;

	if (i < 2)
	{
		dprintf(2, "L%u: can't add, stack too short\n", nline);
		free_glob_v();
		exit(EXIT_FAILURE);
	}

	ptr = (*head)->next;
	ptr->n += (*head)->n;
	pop(head, nline);
}


/**
 * nop - doesn't do anything
 *
 * @head: head of the linked list.
 * @nline: line number
 * Return: nothing.
 */
void nop(stack_t **head, unsigned int nline)
{
	(void)head;
	(void)nline;
}
