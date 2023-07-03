#ifndef MIN_HEAP
#define MIN_HEAP

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Heap {
    void *data;
    int size;
    int capacity;
} Heap;

Heap *new_heap(unsigned int capacity);
void destroy_heap(Heap *heap);
void heap_push(Heap *heap, void *x);


#endif // MIN_HEAP
