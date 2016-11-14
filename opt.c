#include <stdio.h>
#include <assert.h>
#include <unistd.h>
#include <getopt.h>
#include <stdlib.h>
#include "pagetable.h"

// for access to tracefile, memsize, and MAXLINE
#include "sim.h"

extern int debug;

extern struct frame *coremap;

// make trace list using linked list
typedef struct node_t {
    addr_t vaddr;           // virtual address
    struct node_t *next;    // pointer to next node
} node;

node *head; // head of trace list
node *curr; // current trace in trace list

// store distance so we can evict the longest one
int *distances;

/* Page to evict is chosen using the optimal (aka MIN) algorithm. 
 * Returns the page frame number (which is also the index in the coremap)
 * for the page that is to be evicted.
 */
int opt_evict() {
	int i;
    for (i = 0; i < memsize; i++) {
        // earliest future access of i
        int distance = 0;
        
        // get virtual address
        addr_t vaddr = coremap[i].vaddr;
        
        // look for next access in tracefile, record distance
        node *temp = curr->next;
        while (temp && vaddr != temp->vaddr) { // traverse until vaddrs match
            distance++;
            temp = temp->next;
        }

        if (temp) { // found next access point
            distances[i] = distance;
        } else { // frame is never accessed again, evict optimal frame
            return i;
        }
    }
    
    // find max distance in distances list
    int max_frame = -1;
    int max_distance = -1;
    for (i = 0; i < memsize; i++) {
        // if distance is greater than max distance
        if (distances[i] > max_distance) {
            // update max distance and max frame
            max_distance = distances[i];
            max_frame = i;
        }
    }
    
    // evict frame with longest distance
    return max_frame;
}


/* This function is called on each access to a page to update any information
 * needed by the opt algorithm.
 * Input: The page table entry for the page that is being accessed.
 */
void opt_ref(pgtbl_entry_t *p) {
    // circuluar list, move to next node
    curr = curr->next;
    if (!curr)
        curr = head;
}


/* Initializes any data structures needed for this
 * replacement algorithm.
 */
void opt_init() {
    // initialize head and current nodes
    head = NULL;
    curr = NULL;
    
    // allocate space for distance array
    distances = malloc(sizeof(int) * memsize);
    
    // need buffer for reading, vars to store type and vaddr in tracefile
    char buf[MAXLINE];
    char type;
    addr_t vaddr;
    
    // open tracefile for reading
    FILE *fp = fopen(tracefile, "r");
    while (fgets(buf, MAXLINE, fp) != NULL) {
        
        // check for comments in tracefile
        // needed since test files had comments
        // but given trace files didn't
        if (buf[0] == '=')
            continue;
        
        // read line
        sscanf(buf, "%c %lx", &type, &vaddr);
        
        // store vaddr in new node
        node *new_node = malloc(sizeof(node));
        new_node->vaddr = (vaddr >> PAGE_SHIFT) << PAGE_SHIFT;
        new_node->next = NULL;
        
        // add to trace list
        if (head) { // list not empty, add new node to tail
            curr->next = new_node;
        } else { // list empty, make new list using new node as head
            head = new_node;
        }
        
        // set current node to new node
        curr = new_node;
    }
    
    // trace list is complete, set current node as head of list
    curr = head;
}

