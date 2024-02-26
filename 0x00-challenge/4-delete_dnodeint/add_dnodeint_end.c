#include <string.h>
#include <stdlib.h>
#include "lists.h"

/**
 * add_dnodeint_end - Add a node at the end of a list
 *
 * @head: The address of the pointer to the first element of the list
 * @n: The number to store in the new element
 *
 * Return: A pointer to the new element
 */
dlistint_t *add_dnodeint_end(dlistint_t **head, const int n)
{
    dlistint_t *newNode;
    dlistint_t *last;

    newNode = malloc(sizeof(dlistint_t));
    if (newNode == NULL)
    {
        return (NULL);
    }
    newNode->n = n;
    newNode->next = NULL;
    if (*head == NULL)
    {
        *head = newNode;
        newNode->prev = NULL;
        return (newNode);
    }
    last = *head;
    while (last->next != NULL)
    {
        last = last->next;
    }
    last->next = newNode;
    newNode->prev = last;
    return (newNode);
}
