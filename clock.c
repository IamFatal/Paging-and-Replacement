#include <stdio.h>
#include <assert.h>
#include <unistd.h>
#include <getopt.h>
#include <stdlib.h>
#include "pagetable.h"
#include <stdbool.h>
#include <string.h>

extern int memsize;

extern int debug;

extern struct frame *coremap;

// tracks position of clock hand
int clk_hand;

// bitmap for all ref bits
bool* refbits;

/* Page to evict is chosen using the clock algorithm.
 * Returns the page frame number (which is also the index in the coremap)
 * for the page that is to be evicted.
 */
int clock_evict() {
	// find first ref bit that is off
    // i.e. hasn't been used recently
    int i; // start at saved clock hand position
    for (i = clk_hand; i < memsize; i = (i + 1) % memsize) {
        if (refbits[i]) { // ref bit is on
            // turn it off, go to next page
            refbits[i] = 0; 
        } else { // ref bit is off, found it
            // set to 1 so it doesn't get stuck
            refbits[i] = 1;
            
            // update clock hand position
            clk_hand = i;
            return i;
        }
    }
    
    // shouldn't get here
    return 0;
}

/* This function is called on each access to a page to update any information
 * needed by the clock algorithm.
 * Input: The page table entry for the page that is being accessed.
 */
void clock_ref(pgtbl_entry_t *p) {
    // get frame number of accessed page
    int frame = p->frame >> PAGE_SHIFT;
    
    // set ref bit of page to 1
    refbits[frame] = 1;
}

/* Initialize any data structures needed for this replacement
 * algorithm. 
 */
void clock_init() {
    clk_hand = 0;
    refbits = malloc(sizeof(bool) * memsize);   // allocate memory for bitmap
    memset(refbits, 0, sizeof(bool) * memsize); // set all bits to 0
}
