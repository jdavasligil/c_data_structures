#include "test.h"
#include "structures/linked_list.h"

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

void test_linked_list(void) {
    LinkedList lst = { .head = NULL }; 
    void *pop_val = NULL;

    printf("Testing...\n");

    push(&lst, new_node_from_str("A"));
    assert(*(char *)peek(&lst) == 'A');

    push(&lst, new_node_from_str("B"));
    assert(*(char *)peek(&lst) == 'B');

    display(&lst);

    pop_val = pop(&lst);

    printf("Pop: %s\n", (char *)pop_val);
    assert(*(char *)pop_val == 'B');

    if (pop_val) {
        free(pop_val);
    }

    display(&lst);

    printf("Test Successful\n");
}
