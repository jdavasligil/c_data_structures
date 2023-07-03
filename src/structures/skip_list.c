#include "skip_list.h"

SLNode *new_node(unsigned int key, void *value) {
    SLNode *node = (SLNode *)malloc(sizeof(SLNode));

    node->key = key;
    node->value = value;
    node->height = 0;
    node->lanes = (SLNode **)malloc(MAX_SKIP_HEIGHT * sizeof(SLNode*));

    for (int i = 0; i < MAX_SKIP_HEIGHT; ++i) {
        node->lanes[i] = NULL;
    }

    return node;
}

SLNode *new_sl_node_from_str(unsigned int key, char *s) {
    void *data = malloc(2 * CACHE_LINE_LENGTH - sizeof(SLNode));

    strcpy((char *)data, s);

    return new_sl_node(key, data); 
}
