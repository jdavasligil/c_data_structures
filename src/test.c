#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "structures/linked_list.h"

void test_linked_list(void) {
    printf("Testing...\n");

    LinkedList lst; 

    push(&lst, new_node_from_str("A"));
    assert(*(char *)peek(&lst) == 'A');

    push(&lst, new_node_from_str("B"));
    assert(*(char *)peek(&lst) == 'B');

    display(&lst);

    void *pop_val = pop(&lst);

    printf("Pop: %s\n", (char *)pop_val);
    assert(*(char *)pop_val == 'B');

    free(pop_val);

    display(&lst);

    printf("Test Successful\n");
}
