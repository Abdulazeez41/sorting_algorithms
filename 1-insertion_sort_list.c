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

	if (list == NULL || *list == NULL)
		return;

	current = (*list)->next;

	while (current)
	{
		next = current->next;

		if (current->prev)
			current->prev->next = current->next;
		if (current->next)
			current->next->prev = current->prev;

		insert_sorted(list, current);
		print_list(*list);

		current = next;
	}
}

/**
 * insert_sorted - insert a node into a sorted doubly linked list
 * @sorted_list: Double pointer to the element of the sorted list
 * @node: Pointer to the node
 *
 * Return: void
 */
void insert_sorted(listint_t **sorted_list, listint_t *node)
{
	listint_t *current;

	if (*sorted_list == NULL || (*sorted_list)->n >= node->n)
	{

		node->next = *sorted_list;
		node->prev = NULL;
		if (*sorted_list)
			(*sorted_list)->prev = node;

		*sorted_list = node;
	}
	else
	{

		current = *sorted_list;
		while (current->next && current->next->n < node->n)
			current = current->next;

		node->next = current->next;
		if (current->next)
			current->next->prev = node;
		current->next = node;
		node->prev = current;
	}
}
