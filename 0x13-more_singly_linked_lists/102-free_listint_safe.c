#include "lists.h"
/**
 * free_listint_safe - frees a linkedlist
 * @h: pointer to the first node in the linkedlist
 *
 * Return: number of elements in the freed list
 */
size_t free_listint_safe(listint_t **h)
{
	size_t l = 0;
	int diff;
	listint_t *t;

	if (!h || !*h)
		return (0);

	while (*h)
	{
		diff = *h - (*h)->next;
		if (diff > 0)
		{
			t = (*h)->next;
			free(*h);
			*h = t;
			l++;
		}
		else
		{
			free(*h);
			*h = NULL;
			l++;
			break;
		}
	}

	*h = NULL;

	return (l);
}
