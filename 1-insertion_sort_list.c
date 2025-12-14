#include <stdio.h>
#include "sort.h"

/**
 * insertion_sort_list - sorts a doubly linked list of ints in ascending order
 * using insertion sort algorithm
 * @list: pointer to the head of a list
 * Return: nothing/ void
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *head = *list;
	listint_t *current = *list;
	listint_t *next, *position;

	if (list == NULL)
		return;

	/*while not at the end of the list*/
	while (current->next != NULL)
	{
		/*set variables so we can trav*/
		next = current->next;
		position = current;

		/*while not at the beginning and needing to swap nodes*/
		while (position != NULL && next->n < position->n)
		{
			position->next = next->next;
			if (position->next != NULL)
				position->next->prev = position;

			next->prev = position->prev;

			if (next->prev != NULL)
				next->prev->next = next;

			else
				head = next;

			next->next = position;
			position->prev = next;
			position = next->prev;
			print_list(head);
			*list = head;
		}
		/*iterate to next position in list*/
		current = next;
	}
}
