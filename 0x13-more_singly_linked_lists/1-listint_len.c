#include "lists.h"

/**
 * listint_len - returns the number of elements in a linked list
 * @head: linked list of type listint_t to traverse
 *
 * Return: The number of nodes in the linked list
 */

size_t listint_len(const listint_t *head)
{
	size_t count = 0;

	while (head)
	{
		count++;
		head = head->next;
	}

	return (count);
}
