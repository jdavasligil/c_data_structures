#ifndef LINKED_LIST
#define LINKED_LIST

#define CACHE_LINE_LENGTH 64

struct Node;
struct LinkedList;

typedef struct LinkedList {
    struct Node *head;
} LinkedList;

typedef struct Node {
    void *data;
    struct Node *next;
} Node;

void push(LinkedList *self, Node *node);
void *pop(LinkedList *self);
void *peek(LinkedList *self);
void display(LinkedList *self);

Node *new_node(void *data);
Node *new_node_from_str(char *s);

#endif
