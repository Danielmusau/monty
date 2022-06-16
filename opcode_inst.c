#include "monty.h"

/**
 * push - pushes an element to the stack
 *
 * @head: head of the linked list
 * @nline: line number
 * Return: no return.
 */
void push(stack_t **head, unsigned int nline)
{
	int n, j;

	if (!glob_v.arg)
	{
		dprintf(2, "L%u: ", nline);
		dprintf(2, "usage: push integer\n");
		free_glob_v();
		exit(EXIT_FAILURE);
	}

	for (j = 0; glob_v.arg[j] != '\0'; j++)
	{
		if (!isdigit(glob_v.arg[j]) && glob_v.arg[j] != '-')
		{
			dprintf(2, "L%u: ", nline);
			dprintf(2, "usage: push integer\n");
			free_glob_v();
			exit(EXIT_FAILURE);
		}
	}

	n = atoi(glob_v.arg);

	if (glob_v.lifo == 1)
		add_dnodeint(doubly, n);
	else
		add_dnodeint_end(doubly, n);
}

/**
 * pall - printsa all values on the stack
 *
 * @head: head of the linked list
 * @nline: line numbers
 * Return: no return
 */
void pall(stack_t **head, unsigned int nline)
{
	stack_t *aux;
	(void)nline;

	aux = *doubly;

	while (aux)
	{
		printf("%d\n", aux->n);
		aux = aux->next;
	}
}
