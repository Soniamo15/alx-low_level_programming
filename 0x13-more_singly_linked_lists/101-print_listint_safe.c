#include "lists.h"
#include <stdio.h>

size_t get_looped_list_len(const listint_t *head);
size_t print_listint_safe(const listint_t *head);

/**
 *get_looped_list_len - Counts the number of unique nodes
 *in a looped listint_t linked list.
 *@head: A pointer to the head of the listint_t to check.
 *Return: If the list is not looped - 0.
 *Otherwise - the number of unique nodes in the list.
*/
size_t get_looped_list_len(const listint_t *head)
{
	const listint_t *tortoise = head, *hare = head;
	size_t nodes = 0;

	while (hare && hare->next)
	{
		tortoise = tortoise->next;
		hare = hare->next->next;

		if (tortoise == hare)
		{
			do {
				nodes++;
				hare = hare->next;
			} while (tortoise != hare);

			tortoise = head;
			while (tortoise != hare)
			{
				nodes++;
				tortoise = tortoise->next;
				hare = hare->next;
			}
			return (nodes);
		}
	}
	return (nodes);
}

/**
 * print_listint_safe - Prints a listint_t list safely.
 * *@head: A pointer to the head of the listint_t list.
 * *Return: The number of nodes in the list.
 */
size_t print_listint_safe(const listint_t *head)
{
	size_t nodes = get_looped_list_len(head);
	size_t i;

	if (nodes == 0)
	{
		while (head)
		{
			printf("[%p] %d\n", (void *)head, head->n)
				nodes++;
			head = head->next;
		}
	}
	else
	{
		for (i = 0; i < nodes; i++)
		{
			printf("[%p] %d\n", (void *)head, head->n)
				head = head->next}
		printf("-> [%p] %d\n", (void *)head, head->n);
	}
	return (nodes);
}
