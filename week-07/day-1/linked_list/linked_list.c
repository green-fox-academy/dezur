//
// Created by Zoli on 2019. 05. 20..
//

#include "linked_list.h"

void append(linked_list_t *head, int data)
{
    linked_list_t *new_node = (linked_list_t *)malloc(sizeof(linked_list_t));
    new_node->data = data;
    new_node->next = NULL;

    linked_list_t *it = head;
    while (it->next != NULL) {
        it = it->next;
    }
    it->next = new_node;
}

void prepend1(linked_list_t *head, int data)
{
    linked_list_t *new_node = (linked_list_t *)malloc(sizeof(linked_list_t));
    new_node->data = data;

    new_node->next = head->next;
    head->next = new_node;
}

linked_list_t* prepend2(linked_list_t *head, int data)
{
    linked_list_t *new_node = (linked_list_t *)malloc(sizeof(linked_list_t));
    new_node->data = 0;

    new_node->next = head;
    head->data = data;
    return new_node;
}

void prepend3(linked_list_t **head, int data)
{
    linked_list_t *new_node = (linked_list_t *)malloc(sizeof(linked_list_t));
    new_node->data = 0;

    new_node->next = *head;
    (*head)->data = data;
    *head = new_node;
}

void printList(linked_list_t *head)
{
    while (head->next != NULL)
    {
        printf("%d\n", head->next->data);
        head = head->next;
    }
}

int size(linked_list_t *head)
{
    int counter = 0;
    while (head->next != NULL)
    {
        counter++;
        head = head->next;
    }
    return counter;
}

linked_list_t* create_node(int data)
{
    linked_list_t *head = (linked_list_t *)malloc(sizeof(linked_list_t));
    head->data = 0;
    head->next = NULL;

    return head;
}

int is_empty(linked_list_t *head)
{
    if ((head->next) == NULL)
        return 1;
    return 0;
}

void delete_first(linked_list_t *head)
{
    linked_list_t *second_loc = head->next->next;
    free(head->next);
    head->next = second_loc;
}