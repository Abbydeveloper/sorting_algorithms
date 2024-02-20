#include "sort.h"

/**
 * void insertion_sort_list - sort a doubly linked list of integers in
 * ascending order using insertion sort algorithm
 * @list: doubly linked list to sort through
 *
 * Return: void
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *tmp;
	listint_t *curr;

	if (!list)
		return;

	curr = *list;
	while (curr)
	{
		while ((curr->n > curr->next->n) && curr->next)
		{
			tmp = curr->next;
			curr->next = tmp->next;
			tmp->prev = curr->prev;
			if (curr->prev)
			{
				curr->prev->next = tmp;
			}
			if (tmp->next)
			{
				tmp->next->prev = curr;
			}
			curr->prev = tmp;
			tmp->next = curr;
			if (tmp->prev)
			{
				curr = tmp->prev;
			}
			else
			{
				*list = tmp;
			}
			print_list(*list);
		}
		curr = curr->next;
	}
}
