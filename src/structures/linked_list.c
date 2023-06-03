#include "linked_list.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


void push(LinkedList *self, Node *node) {
    Node *tmp = self->head;
    self->head = node;
    node->next = tmp;
}

void* pop(LinkedList *self) {
    void *data = NULL;
    Node *del_node = self->head;

    if (del_node) {
        data = del_node->data;
        del_node->data = NULL;
        self->head = self->head->next;
        free(del_node);
    }

    return data;
}

void *peek(LinkedList *self) {
    return self->head->data;
}

void display(LinkedList *self) {
    Node *ptr = self->head;

    while (ptr) {
        printf("%s\n", (char *)(ptr->data));
        ptr = ptr->next;
    }
}

Node *new_node(void *data) {
    Node *node = (Node *)malloc(sizeof(Node));

    node->data = data;
    node->next = NULL;

    return node;
}

Node *new_node_from_str(char *s) {
    void *data = malloc(CACHE_LINE_LENGTH - sizeof(Node));

    strcpy((char *)data, s);

    return new_node(data); 
}
