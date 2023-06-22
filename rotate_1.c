#include "monty.h"

/**
* f_rot1 - function that rotates the stack to the top
* @head: head of the stack
* @counter: line count
*
* Return: nothing
*/
void f_rot1(stack_t **head,  __attribute__((unused)) unsigned int counter)
{
	stack_t *tmp = *head, *tux;

	if (*head == NULL || (*head)->next == NULL)
	{
		return;
	}
	tux = (*head)->next;
	tux->prev = NULL;
	while (tmp->next != NULL)
	{
		tmp = tmp->next;
	}
	tmp->next = *head;
	(*head)->next = NULL;
	(*head)->prev = tmp;
	(*head) = tux;
}
