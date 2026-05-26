#include <stdlib.h>
#include <stdio.h>
#include "list.h"

struct Node {
    struct Node* next;
    int value;
};

// function to remove the last item from the list
// no inputs needed apart from the inputList
// returns the removed value in the front
ListStatus pop_front(struct List* inputList, int* outVal) {
    // remove term from the front
    // set the old head to ptr
    struct Node* ptr = inputList->head;

    if (ptr == NULL) {
        return LIST_ERR_EMPTY;
    }
    //reset the head to the next memory address
    inputList->head = ptr->next;

    if (inputList->head == NULL) {
        inputList->tail = NULL;
    }
    //free the address of the old beginning node
    if (outVal != NULL) {
        *outVal = ptr->value;
    }
    
    free(ptr);
    return LIST_OK;
}

// function to add a node to the front of the list
ListStatus push_front(struct List* inputList, int num) {
    // allocate memory for new node
    struct Node* nptr = malloc(sizeof(struct Node));

    if (nptr == NULL) {
        return LIST_ERR_NOMEM;
    }

    // now i have a pointer to a node I can set it 
    
    nptr->next = inputList->head;
    nptr->value = num;

    // reset the head and tail to the new node
    if (inputList->head == NULL) {
        inputList->tail = nptr;
    }
    inputList->head = nptr;
    return LIST_OK;
}

// function to add an item to the list
// inputs:
// inputList -> list given to add to
// num -> the number we are pushing to the list
ListStatus push_back(struct List* inputList, int num) {
    // allocate memory for new node
    struct Node* nptr = malloc(sizeof(struct Node));

    if (nptr == NULL) {
        return LIST_ERR_NOMEM;
    }

    // now i have a pointer to a node I can set it 
    nptr->next = NULL;
    nptr->value = num;
    if (inputList->tail != NULL) {
        inputList->tail->next = nptr;
    }
    
    inputList->tail = nptr;
    // check if the list is empty first
    if (inputList->head == NULL) {
        // and set the list head to it
        inputList->head = nptr;
    }  
    return LIST_OK;
}

// Removes the first item in the list matching a value num
ListStatus remove_first(struct List* inputList, int num, int* outVal) {

    struct Node* ptr;
    struct Node* ptrPrev;

    ptr = inputList->head;
    ptrPrev = NULL;

    while (ptr != NULL) {

        if (ptr->value == num) {
            // if the value is the first item in the list basically doing pop_front()
            if (ptr == inputList->head) {
                return pop_front(inputList, outVal);
            }
            
            ptrPrev->next = ptr->next;
            
            if (ptr == inputList->tail) {
                inputList->tail = ptrPrev;
            }
            if (outVal != NULL) {
                *outVal = ptr->value;
            }
            
            free(ptr);
            return LIST_OK;
        }
        ptrPrev = ptr;
        ptr = ptr->next; 
    }

    return LIST_ERR_NOT_FOUND;
}

// function to find the location/index of a number in the list 
// returns the position of the number or -1 if not found
ListStatus find(struct List* inputList, int num, int* outIndex) {

    int count = -1;
    struct Node* ptr;

    ptr = inputList->head;

    while (ptr != NULL) {
        count++;
        if (ptr->value == num) {

            if (outIndex != NULL) {
                *outIndex = count;
            }
            return LIST_OK;
        }
        ptr = ptr->next; 
    }
    return LIST_ERR_NOT_FOUND;
}

//function to empty existing list and free memory
ListStatus free_list(struct List* inputList) {
    struct Node* ptr1;
    struct Node* ptr2;

    ptr1 = inputList->head;
    while (ptr1 != NULL) {
        ptr2 = ptr1->next;
        free(ptr1);
        ptr1 = ptr2;
    }

    inputList->head = NULL;
    inputList->tail = NULL;
    return LIST_OK;
}

ListStatus print_list(struct List* inputList) {

    struct Node* ptr = inputList->head;

    if (ptr != NULL) {
        printf("List: [ ");
    }
    else {
        return LIST_ERR_EMPTY;
    }

    while (ptr != NULL) {
        printf("%d , ", ptr->value);
    }

    printf("] \n" );
    return LIST_OK;
}


