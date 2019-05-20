#include <stdio.h>
#include "linked_list.h"

int main()
{
    linked_list_t *head = (linked_list_t *)malloc(sizeof(linked_list_t));
    head->data = 0;
    head->next = NULL;

    append(head, 1);
    append(head, 2);

    prepend1(head, -1);

    head = prepend2(head, -2);
    
    prepend3(&head , -3);

    printList(head);
    return 0;
}