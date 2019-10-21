#ifndef ROI_NODE_H
#define ROI_NODE_H

#include "memoryhandler.h"
#include "deftypes.h"

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


/*******************************************************************************
                                TO BE REVISED
*******************************************************************************/

/*  Link the node __tolink to the up pointer of the __base node.
    If succeded it returns 1, else returns 0.*/
byte    nodeLinkUp(node_t *__base, node_t *__tolink);

/*  Link the node __tolink to the bottom pointer of the __base node.
    If succeeded it returns 1, else return 0.*/
byte    nodeLinkBottom(node_t *__base, node_t *__tolink);

/*  Link the node __tolink to the right pointer of the __base node.
    If succeeded it returns 1, else return 0.*/
byte    nodeLinkRight(node_t *__base, node_t *__tolink);

/*  Link the node __tolink to the left pointer of the __base node.
    If succeeded it returns 1, else return 0.*/
byte    nodeLinkLeft(node_t *__base, node_t *__tolink);


/******************************************************************************/






#endif
