#include "lists.h"

/**
 * delete_nodeint_at_the_index - deletes a node in a linkedlist at a certain index
 * @head: pointer to the first element at athe list
 * @index: index of the node to deleted
 *
 * Return: 1 Success, or -1 Fail
 */
int delete_nodeint_at_index(listint_t **head, unsigned int index)
{
	listint_t *t = *head;
	listint_t *current = NULL;
	unsigned int x = 0;

	if (*head == NULL)
		return (-1);

	if (index == 0)
	{
		*head = (*head)->next;
		free(t);
		return (1);
	}

	while (x < index - 1)
	{
		if (!t || !(t->next))
			return (-1);
		t = t->next;
		x++;
	}


	current = t->next;
	t->next = current->next;
	free(current);

return (1);
}
