#include "sort.h"

/**
 * insertion_sort_list - sorts a doubly linked list of integers in ascending
 * order using the Insertion sort algorithm
 * @list: Double pointer to the head of the linked list
 *
 * Return: void
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *next;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	current = (*list)->next;

	while (current)
	{
		next = current->next;

		while (current->prev && current->n < current->prev->n)
		{
			insert_swap_nodes(list, current->prev, current);
		}

		current = next;
	}
}

/**
 * insert_swap_nodes - insert and swap a node into a sorted doubly linked list
 * @sort_list: Double pointer to the element of the sorted list
 * @nod1: Pointer to the node1
 * @nod2: Pointer to the node2
 *
 * Return: void
 */
void insert_swap_nodes(listint_t **sort_list, listint_t *nod1, listint_t *nod2)
{
	if (nod1->prev)
		nod1->prev->next = nod2;

	if (nod2->next)
		nod2->next->prev = nod1;

	nod1->next = nod2->next;
	nod2->prev = nod1->prev;

	nod1->prev = nod2;
	nod2->next = nod1;

	if (nod1 == *sort_list)
		*sort_list = nod2;

	print_list(*sort_list);
}
