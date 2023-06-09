#include "linked_list.h"
#include "constants.h"

void ll_push(LinkedList *self, LLNode *node) {
    LLNode *tmp = self->head;
    self->head = node;
    node->next = tmp;
}

void* ll_pop(LinkedList *self) {
    void *data = NULL;
    LLNode *del_node = self->head;

    if (del_node) {
        data = del_node->data;
        del_node->data = NULL;
        self->head = self->head->next;
        free(del_node);
    }

    return data;
}

void *ll_peek(LinkedList *self) {
    return self->head->data;
}

void ll_display(LinkedList *self) {
    LLNode *ptr = self->head;

    while (ptr) {
        printf("%s\n", (char *)(ptr->data));
        ptr = ptr->next;
    }
}

LLNode *new_ll_node(void *data) {
    LLNode *node = (LLNode *)malloc(sizeof(LLNode));

    node->data = data;
    node->next = NULL;

    return node;
}

LLNode *new_ll_node_from_str(char *s) {
    void *data = malloc(CACHE_LINE_LENGTH - sizeof(LLNode));

    strcpy((char *)data, s);

    return new_ll_node(data); 
}

void ll_destroy(LinkedList *self) {
    while (self->head) {
        free(ll_pop(self));
    }
}
