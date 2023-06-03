#ifndef SKIP_LIST
#define SKIP_LIST

#define CACHE_LINE_LENGTH 64
#define MAX_HEIGHT 12

struct Node;
struct SkipList;

typedef struct SkipList {
    struct Node *head;
    unsigned int size;
} SkipList;

typedef struct Node {
    unsigned int key;
    void *value;
    unsigned int height;
    struct Node **lanes;
} Node;

void insert(SkipList *self, Node *node);
void remove(SkipList *self, unsigned int key);
void find(SkipList *self, unsigned int key);
void display(SkipList *self);
void destroy(SkipList *self);

Node *new_node(void *data);
Node *new_node_from_str(char *s);

#endif
