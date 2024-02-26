#ifndef _LISTS_H_
#define _LISTS_H_

#include <stddef.h>

/**
 * struct dlistint_s - doubly linked list
 * @n: integer
 * @prev: points to the prev node
 * @next: points to the next node
 *
 * Description: doubly linked list node structure
 * for Holberton project
 */
typedef struct dlistint_s
{
    int n;
    struct dlistint_s *prev;
    struct dlistint_s *next;
} dlistint_t;

/**
 * Function to print a doubly linked list
 */
size_t print_dlistint(const dlistint_t *h);

/**
 * Function to add a node at the end of a doubly linked list
 */
dlistint_t *add_dnodeint_end(dlistint_t **head, const int n);

/**
 * Function to delete a node at a specific index from a doubly linked list
 */
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index);

/**
 * Function to free a doubly linked list
 */
void free_dlistint(dlistint_t *head);

#endif /* _LISTS_H_ */
