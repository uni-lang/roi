#ifndef ROI_xnode_H
#define ROI_xnode_H

#include "memoryhandler.h"
#include "deftypes.h"

/**ROI Implementation of dynamic xnode
   Subvars: xnode_t * up, bottom, right, left. void * data.

   Intended to be used for all dynamic structures: trees, AST, queues, stacks.*/
typedef struct xnode_t {
                    *bottom,
                    *right,
                    *left;
    void *data;
} xnode_t;

/** Alloc a xnode memory */
xnode_t  *xnodeAlloc();

/** Free a xnode allocated memory, not recursivelly*/
void    xnodeFree(xnode_t *__xnode);

/** Free a xnode allocated memory recursivelly.
    Caution: This function is quite dangerous, use it properly.*/
void    xnodeRecFree(xnode_t *__xnode);

/*******************************************************************************
                                TO BE REVISED
*******************************************************************************/

/** Link the xnode __tolink to the top pointer of the __base xnode.
    If succeded it returns 1, else returns 0.*/
byte    xnodeLinkTop(xnode_t *__base, xnode_t *__tolink);

/** Link the xnode __tolink to the bottom pointer of the __base xnode.
    If succeeded it returns 1, else return 0.*/
byte    xnodeLinkBottom(xnode_t *__base, xnode_t *__tolink);

/** Link the xnode __tolink to the right pointer of the __base xnode.
    If succeeded it returns 1, else return 0.*/
byte    xnodeLinkRight(xnode_t *__base, xnode_t *__tolink);

/** Link the xnode __tolink to the left pointer of the __base xnode.
    If succeeded it returns 1, else return 0.*/
byte    xnodeLinkLeft(xnode_t *__base, xnode_t *__tolink);


/******************************************************************************/

/** Add the data __data to the top pointer of the __base xnode.
    If succeded it returns 1, else returns 0.*/
byte    xnodeAddTop(xnode *__base, void *__data);







#endif
