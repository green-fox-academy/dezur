#include <stdio.h>
#include "linked_list.h"

int main()
{
    linked_list_t *head = (linked_list_t *)malloc(sizeof(linked_list_t));
    head->data = 0;
    head->next = NULL;

    append(head, 1);
    printf("%d\n", head->next->data);
    append(head, 2);
    printf("%d\n", head->next->next->data);


    prepend1(head, -1);
    printf("%d\n", head->next->data);


    head = prepend2(head, -2);
    printf("%d\n", head->next->data);

    prepend3(&head , -3);
    printf("%d\n", head->next->data);

    while (head != NULL)
    {
        printf("%d ", head->data);
        head = head->next;
    }
    return 0;
}