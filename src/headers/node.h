#ifndef ROI_NODE_H
#define ROI_NODE_H

#include "memoryhandler.h"
#include "deftypes.h"


#define NODE_LINK_LEFT  0
#define NODE_LINK_RIGHT 1

/**ROI Implementation of dynamic node
   Subvars: node_t * up, bottom, right, left. void * data.

   Intended to be used for all dynamic structures: trees, AST, queues, stacks.*/
typedef struct node_t {
    struct node_t   *right,
                    *left;
    void *data;
} node_t;

/**  Alloc a node memory */
node_t  *nodeAlloc();

/**  Free a node allocated memory, not recursivelly*/
void    nodeFree(node_t *__node);

/** Free a node allocated memory recursivelly.
    Caution: This function is quite dangerous, use it properly.*/
//void    nodeRecFree(node_t *__node);

/** Free a node allocated memory recursivelly.
    The functions then call the __callback function to free the data pointer
    Caution: This function is quite dangerous, use it properly.*/
void    nodeRecFree(node_t *__node, void (*__callback)(void *__data));

/*******************************************************************************
                                TO BE REVISED
*******************************************************************************/

/** Link the node __tolink to the right pointer of the __base node.
    __linkdir: NODE_LINK_LEFT or NODE_LINK_RIGHT
    If succeeded it returns 1, else return 0.*/
byte    nodeLink(node_t *__base, node_t *__tolink, int __linkdir);

/** Create a parent node with __data, link __base to its LEFT or RIGHT node
    and returns the parent node.
    __linkdir: NODE_LINK_LEFT or NODE_LINK_RIGHT
    If succeded it returns the child's node, else returns NULL.*/
node_t  *nodeAddChild(node_t *__base, void *__data, int __linkdir);

/** Create a parent node with __data, link __base to its LEFT or RIGHT node
    and returns the parent node.
    __linkdir: NODE_LINK_LEFT or NODE_LINK_RIGHT
    If succeded it returns parent's node, else returns NULL.*/
node_t  *nodeAddParent(node_t *__base, void *__data, int __linkdir);


/******************************************************************************/






#endif
