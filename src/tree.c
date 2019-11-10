/*******************************************************************************
    SOURCE FILE RELATED TO THE TREE
*******************************************************************************/


#include "headers/node.h"
#include "headers/roisys.h"
#include "headers/tree.h"


void treeInOrderRec(node_t *__root, void (*__callback)(void *__data))
{
    if(__root != NULL){
        treeInOrderRec(__root->left, (*__callback));
        __callback(__root->data);
        treeInOrderRec(__root->right, (*__callback));
    }
}

void treePreOrderRec(node_t *__root, void (*__callback)(void *__data))
{
    if(__root != NULL){
        __callback(__root->data);
        treePreOrderRec(__root->left, (*__callback));
        treePreOrderRec(__root->right, (*__callback));
    }
}


void treePostOrderRec(node_t *__root, void (*__callback)(void *__data))
{
    if(__root != NULL){
        treePostOrderRec(__root->left, (*__callback));
        treePostOrderRec(__root->right, (*__callback));
        __callback(__root->data);
    }
}
