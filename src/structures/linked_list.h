#ifndef LINKED_LIST
#define LINKED_LIST

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct LLNode;
struct LinkedList;

typedef struct LinkedList {
    struct LLNode *head;
} LinkedList;

typedef struct LLNode {
    void *data;
    struct LLNode *next;
} LLNode;

void ll_push(LinkedList *self, LLNode *node);
void *ll_pop(LinkedList *self);
void *ll_peek(LinkedList *self);
void ll_display(LinkedList *self);

LLNode *new_ll_node(void *data);
LLNode *new_ll_node_from_str(char *s);

void ll_destroy(LinkedList *self);

#endif
