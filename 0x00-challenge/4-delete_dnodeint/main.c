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

    printf("Original list:\n");
    print_dlistint(head);
    printf("-----------------\n");

    int indices[] = {5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    size_t size = sizeof(indices) / sizeof(indices[0]);

    for (size_t i = 0; i < size; i++)
    {
        delete_dnodeint_at_index(&head, indices[i]);
        printf("List after deleting at index %d:\n", indices[i]);
        print_dlistint(head);
        printf("-----------------\n");
    }

    free_dlistint(head);

    return (0);
}
