#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "lists.h"

/**
 * main - check the code for Holberton School students.
 *
 * Return: Always EXIT_SUCCESS.
 */
int main(void)
{
    dlistint_t *head;

    head = NULL;
    add_dnodeint_end(&head, 0);
    add_dnodeint_end(&head, 1);
    add_dnodeint_end(&head, 2);
    add_dnodeint_end(&head, 3);
    add_dnodeint_end(&head, 4);
    add_dnodeint_end(&head, 98);
    add_dnodeint_end(&head, 402);
    add_dnodeint_end(&head, 1024);
    print_dlistint(head);
    printf("-----------------\n");

    /* Deleting at index 5 */
    delete_dnodeint_at_index(&head, 5);
    print_dlistint(head);
    printf("-----------------\n");

    /* Deleting at index 0 */
    delete_dnodeint_at_index(&head, 0);
    print_dlistint(head);
    printf("-----------------\n");

    /* Deleting at index 0 again */
    delete_dnodeint_at_index(&head, 0);
    print_dlistint(head);
    printf("-----------------\n");

    /* Deleting at index 0 yet again */
    delete_dnodeint_at_index(&head, 0);
    print_dlistint(head);
    printf("-----------------\n");

    /* Check if the list is empty before printing */
    if (head != NULL) {
        /* ... continue testing with additional delete_dnodeint_at_index calls */
    }

    /* Free the remaining nodes */
    free_dlistint(head);

    return (EXIT_SUCCESS);
}
