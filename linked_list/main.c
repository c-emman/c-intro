#include <stdio.h>
#include "list.h"
#include <strings.h>

static void check(ListStatus st, const char* msg) {
    if (st != LIST_OK) {
        printf("FAIL: %s (status=%d)\n", msg, st);
    } else {
        printf("OK:   %s\n", msg);
    }
}

// int main(void) {
//     // Important: initialise head/tail to NULL
//     List list = {0};

//     // Push some values
//     check(push_back(&list, 10), "push_back 10");
//     check(push_back(&list, 20), "push_back 20");
//     check(push_front(&list, 5), "push_front 5");

//     // Find
//     int idx = -1;
//     ListStatus st = find(&list, 20, &idx);
//     if (st == LIST_OK) {
//         printf("Found 20 at index %d\n", idx);
//     } else {
//         printf("20 not found\n");
//     }

//     // Remove first match
//     int removed = 0;
//     st = remove_first(&list, 10, &removed);
//     if (st == LIST_OK) {
//         printf("Removed %d\n", removed);
//     } else {
//         printf("10 not found to remove\n");
//     }

//     // Pop everything
//     int val = 0;
//     while (pop_front(&list, &val) == LIST_OK) {
//         printf("Popped %d\n", val);
//     }

//     // Free list (should be safe even if already empty)
//     check(free_list(&list), "free_list");

//     return 0;
// }

int main(void) {
    // Important: initialise head/tail to NULL
    List list = {0};
    char inputCmd[256];
    

    while (strcasecmp(inputCmd, "quit") != 0) {
        

    }


}