#ifndef LINKED_LIST_H

#define LINKED_LIST_H

// Forward declaration: lets us use `struct Node*` without exposing Node layout

struct Node;

typedef struct List {
    struct Node* head;
    struct Node* tail;
} List;

typedef enum {
    LIST_OK = 0,
    LIST_ERR_EMPTY,
    LIST_ERR_NOT_FOUND,
    LIST_ERR_NOMEM
} ListStatus;

// API

ListStatus pop_front(List* list, int* outVal);

ListStatus push_front(List* list, int num);

ListStatus push_back(List* list, int num);

ListStatus remove_first(List* list, int num, int* outVal);

ListStatus find(List* list, int num, int* outIndex);

ListStatus free_list(List* list);

#endif