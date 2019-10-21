#ifndef ROI_NODE_H
#define ROI_NODE_H

#include "memoryhandler.h"

/* ROI Implementation of dynamic node 
   Subvars: node_t * up, bottom, right, left. void * data.
   
   Intended to be used for all dynamic structures: trees, AST, queues, stacks.*/
typedef struct node_t {
    struct node_t   *up,
                    *bottom,
                    *right,
                    *left;
    void *data;
} node_t;

node_t  *allocNode();
void    freeNode();

#endif