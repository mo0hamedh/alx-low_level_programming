#include "lists.h"

/**
 * free_listint - free a linked list
 * @head: listint_t list be afreed
 */
void free_listint(listint_t *head)
{
	listint_t *t;

	while (head)
	{
		t = head->next;
		free(head);
		head = t;
	}
}

