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