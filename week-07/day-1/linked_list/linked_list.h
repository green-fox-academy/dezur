//
// Created by Zoli on 2019. 05. 20..
//

#ifndef LINKED_LIST_LINKED_LIST_H
#define LINKED_LIST_LINKED_LIST_H

#endif //LINKED_LIST_LINKED_LIST_H

#include <stdio.h>
#include <stdlib.h>


typedef struct linked_list_t
{
    int data;
    struct linked_list_t *next;
} linked_list_t;

void append(linked_list_t *head, int data);

void prepend1(linked_list_t *head, int data);

linked_list_t *prepend2(linked_list_t *head, int data);

void prepend3(linked_list_t **head, int data);

void printList(linked_list_t *head);

int size(linked_list_t *head);

linked_list_t* create_node(int data);

int is_empty(linked_list_t *head);