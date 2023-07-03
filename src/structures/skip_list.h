#ifndef SKIP_LIST
#define SKIP_LIST

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "constants.h"

struct SLNode;
struct SkipList;

typedef struct SkipList {
    struct SLNode *head;
    unsigned int size;
} SkipList;

typedef struct SLNode {
    unsigned int key;
    void *value;
    unsigned int height;
    struct SLNode **lanes;
} SLNode;

void sl_insert(SkipList *self, SLNode *node);
void sl_remove(SkipList *self, unsigned int key);
void sl_find(SkipList *self, unsigned int key);
void sl_display(SkipList *self);
void sl_destroy(SkipList *self);

SLNode *new_sl_node(unsigned int key, void *data);
SLNode *new_sl_node_from_str(unsigned int key, char *s);

void sl_destroy(SkipList *self);

#endif
