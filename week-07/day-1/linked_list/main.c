#include <stdio.h>
#include "linked_list.h"

int main()
{
    linked_list_t *head = create_node(0);
    linked_list_t *test = create_node(0);

    append(head, 12);
    append(head, 24);

    delete_first(head);

    //prepend1(head, -1);

    //head = prepend2(head, -2);

    //prepend3(&head , -3);

    printList(head);
    printList(test);

    printf("List contains %d item(s)\n", size(head));
    printf("%d\n", is_empty(head));
    printf("List contains %d item(s)\n", size(test));
    printf("%d\n", is_empty(test));

    return 0;
}