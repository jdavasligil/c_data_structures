#include "min_heap.h"

Heap *new_heap(unsigned int capacity) {
    int *heap_data = (int *)malloc(capacity * sizeof(int));
    Heap *heap = (Heap *)malloc(sizeof(Heap));

    heap->data = heap_data;
    heap->size = 0;
    heap->capacity = capacity;

    return heap;
}
