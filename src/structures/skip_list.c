#include "skip_list.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


Node *new_node(unsigned int key, void *value) {
    Node *node = (Node *)malloc(sizeof(Node));

    node->key = key;
    node->value = value;
    node->height = 0;
    node->lanes = (Node *)malloc(MAX_HEIGHT * sizeof(Node));

    for (int i = 0; i < MAX_HEIGHT; ++i) {
        node->lanes[i] = NULL;
    }

    return node;
}

Node *new_node_from_str(unsigned int key, char *s) {
    void *data = malloc(2 * CACHE_LINE_LENGTH - sizeof(Node));

    strcpy((char *)data, s);

    return new_node(key, data); 
}
