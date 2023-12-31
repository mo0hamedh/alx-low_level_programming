#include "lists.h"
#include <stdlib.h>

/**
* add_dnodeint_end - a function that adds a new node at
* the end of a dlistint_t list.
* @head: pointer to a pointer to the head of a doubly linked list
* @n: int of new node
*
* Return: the address of the new element, or NULL if it failed.
*/
dlistint_t *add_dnodeint_end(dlistint_t **head, const int n)
{
	dlistint_t *new_node, *h;

	h = *head;
	new_node = malloc(sizeof(dlistint_t));
	if (new_node == NULL)
		return (NULL);

	new_node->n = n;
	new_node->next = NULL;

	if (h == NULL)
	{
		new_node->prev = NULL;
		*head = new_node;
		return (new_node);
	}

	while (h->next != NULL)
		h = h->next;
	h->next = new_node;
	new_node->prev = h;

	return (new_node);
}
