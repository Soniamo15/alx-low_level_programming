#include "lists.h"

/**
 *get_nodeint_at_index - returns the node at a certain index in a linked list
 *@head: pointer to the first node in the linked list
 *@index: index of the node to return
 *Return: pointer to the node at the given index, or NULL if it does not exist
 */

listint_t *get_nodeint_at_index(listint_t *head, unsigned int index)
{
	unsigned int i = 0;

	listint_t *current_node = head;

	while (current_node && i < index)
	{
		current_node = current_node->next;
		i++;
	}

	return (current_node ? current_node : NULL);
}
