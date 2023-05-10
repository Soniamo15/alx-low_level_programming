#include "lists.h"

/**
 *sum_listint - calculates the sum of all the data in a listint_t list
*@head: pointer to the first element in the linked list
*Return: resulting sum
*/
int sum_listint(listint_t *head)
{
	int sum = 0;

	listint_t *current = head;

	while (current)
	{
		sum += current->n;

		current = current->next;
	}

	return (sum);
}