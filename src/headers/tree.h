#ifndef ROI_TREE_H
#define ROI_TREE_H

#include "node.h"
#include "deftypes.h"

/*
//Reduntant definition, primitive
typedef struct tree_t {
    node_t * root;
} Tree;
*/


/** Tree traversal recursivelly inorder
    Calls the __callback function passing the data pointer to it. */
void treeInOrderRec(node_t *__root, void (*__callback)(void *__data));

/** Tree traversal recursivelly preorder
    Calls the __callback function passing the data pointer to it. */
void treePreOrderRec(node_t *__root, void (*__callback)(void *__data));

/** Tree traversal recursivelly postorder
    Calls the __callback function passing the data pointer to it. */
void treePostOrderRec(node_t *__root, void (*__callback)(void *__data));


#endif
