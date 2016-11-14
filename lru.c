#include <stdio.h>
#include <assert.h>
#include <unistd.h>
#include <getopt.h>
#include <stdlib.h>
#include "pagetable.h"


extern int memsize;

extern int debug;

extern struct frame *coremap;

// make queue using linked list
typedef struct node_t {
    int frame;          // page frame number
    struct node_t *next;  // pointer to next node
} node;

node *head; // head of lru queue, evict page
node *tail; // tail of lru queue, insert page

/* Page to evict is chosen using the accurate LRU algorithm.
 * Returns the page frame number (which is also the index in the coremap)
 * for the page that is to be evicted.
 */

int lru_evict() {
	// get frame number of head
	int frame = head->frame;
    
    // if list has one element
    if (head == tail)
        tail = NULL;

    // remove head, update list
    node *new_head = head->next;
    free(head);
    head = new_head;
    
    return frame;   // return page frame number
}

/* This function is called on each access to a page to update any information
 * needed by the lru algorithm.
 * Input: The page table entry for the page that is being accessed.
 */
void lru_ref(pgtbl_entry_t *p) {
    // get frame number of accessed page
	int frame = p->frame >> PAGE_SHIFT;
    
    // create a new node
    node *new_node = malloc(sizeof(node));
    new_node->frame = frame;
    new_node->next = NULL;
    
    // if list is empty, create list with new_node
    if (!tail) {
        tail = new_node;
        head = tail;
        return;
    }
    
    // remove last reference of frame from list, if it exists
    node *curr = head;  // track current node
    node *prev = NULL;  // track previous node
    while (curr) {
        if (curr->frame == frame) { // frame already in list
            if (!prev) { // deleting head of list
                head = curr->next;
                free(curr);
                if (!head) // if list is empty
                    tail = NULL;
            } else { // delete node
                prev->next = curr->next;
                free(curr);
            }
            break;
        }
        prev = curr;
        curr = curr->next;
    }
    
    // add new node to list
    if (!tail) { // list is empty again
        tail = new_node;
        head = tail;
    } else { // list not empty, add to tail
        tail->next = new_node;
        tail = new_node;
    }
}


/* Initialize any data structures needed for this 
 * replacement algorithm 
 */
void lru_init() {
    head = NULL;
    tail = NULL;
}
