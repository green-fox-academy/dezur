#include <stdio.h>
#include "linked_list.h"

int main()
{
    linked_list_t *head = create_node(0);

    append(head, 1);
    append(head, 2);

    prepend1(head, -1);

    head = prepend2(head, -2);

    prepend3(&head , -3);

    printList(head);

    printf("\n-----------------------------------\n");

    printf("List contains %d item(s)\n", size(head));
    return 0;
}