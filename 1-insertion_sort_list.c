#include "sort.h"

/*
 *insertion_sort_list - sorts a doubly linked list of integers
 *in ascending order using the Insertion sort algorithm
 *
 * @list: Pointer to the doubly linked list
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *prev, *temp;

	 if (list == NULL || *list == NULL || (*list)->next == NULL)
		 return;

	 current = (*list)->next;

	 while (current != NULL)
	{
		temp = current;
		prev = current->prev;

		while (prev !=NULL && temp->n < prev->n)
		{
			if (temp->next != NULL)
				temp->next->prev = prev;

			temp->prev = prev->prev;
			prev->next = temp->next;

			temp->next = prev;
			prev->prev = temp;

			if (temp->prev != NULL)
				temp->prev->next = temp;
			else
				*list = temp;

			print_list(*list);

			prev = temp->prev;
		}

		current = temp->next;
	}
}
