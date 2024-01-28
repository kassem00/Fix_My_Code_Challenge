#include "lists.h"
#include <stdlib.h>

/**
 * delete_dnodeint_at_index - Delete a node at a specific index from a list
 *
 * @head: A pointer to the first element of a list
 * @index: The index of the node to delete
 *
 * Return: 1 on success, -1 on failure
 */
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index) {
    dlistint_t *current;
    dlistint_t *next_node;
    unsigned int i;

    if (*head == NULL)
        return (-1);

    current = *head;

    /* Handle deletion at the beginning (index == 0) */
    if (index == 0) {
        *head = (*head)->next;
        if (*head != NULL)
            (*head)->prev = NULL;
        free(current);
        return (1);
    }

    /* Traverse to the node at the specified index */
    for (i = 0; current != NULL && i < index - 1; i++)
        current = current->next;

    /* Check if index is out of bounds */
    if (current == NULL || current->next == NULL)
        return (-1);

    /* Adjust pointers to skip the node to be deleted */
    next_node = current->next->next;
    free(current->next);
    current->next = next_node;
    if (next_node != NULL)
        next_node->prev = current;

    return (1);
}

