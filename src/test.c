#include "test.h"

void test_linked_list(void) {
    LinkedList lst = { .head = NULL }; 
    void *pop_val = NULL;

    printf("Testing...\n");

    ll_push(&lst, new_ll_node_from_str("A"));
    assert(*(char *)ll_peek(&lst) == 'A');

    ll_push(&lst, new_ll_node_from_str("B"));
    assert(*(char *)ll_peek(&lst) == 'B');

    ll_display(&lst);

    pop_val = ll_pop(&lst);

    printf("Pop: %s\n", (char *)pop_val);
    assert(*(char *)pop_val == 'B');

    if (pop_val) {
        free(pop_val);
    }

    ll_display(&lst);

    ll_destroy(&lst);
    assert(lst.head == NULL);

    printf("Test Successful\n");
}
