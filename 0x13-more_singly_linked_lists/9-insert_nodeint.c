#include "lists.h"

/**
 * insert_nodeint_at_index - inserts a new node at a given positio
 * @head: pointer to the first node in the list
 * @idx: index where the new node should be inserted
 * @n: data to insert in the new node
 *
 * Return: pointer to the new node, or NULL if it fails
 */

listint_t *insert_nodeint_at_index(listint_t **head, unsigned int idx, int n)
{
	unsigned int i;
	listint_t *new_node, *temp;

	/* Allocate memory for the new node */
	new_node = malloc(sizeof(listint_t));
	if (new_node == NULL)
		return (NULL);

	/* Set the data for the new node */
	new_node->n = data;
	new_node->next = NULL;

	/* Handle insertion at the head of the list */
	if (index == 0)
	{
		new_node->next = *head;
		*head = new_node;
		return (new_node);
	}

	/* Traverse the list to find the position for the new node */
	temp = *head;
	for (i = 0; temp != NULL && i < index - 1; i++)
		temp = temp->next;

	/* If the index is out of bounds, return NULL */
	if (i != index - 1)
	{
		free(new_node);
		return (NULL);
	}

	/* Insert the new node at the desired position */
	new_node->next = temp->next;
	temp->next = new_node;

	return (new_node);
}
