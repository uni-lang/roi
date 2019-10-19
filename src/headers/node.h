#ifndef ROI_NODE_H
#define ROI_NODE_H

#include "memoryhandler.h"

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
