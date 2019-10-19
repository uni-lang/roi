/*******************************************************************************
    SOURCE FILE RELATED TO THE NODE USED IN AST, LISTS, QUEUES, STACKS...
*******************************************************************************/

#include "headers/node.h"
#include "headers/memoryhandler.h"

node_t *allocNode(){
    node_t *__aux;

    __aux = (node_t*)allocMem(sizeof(node_t));

    if(__aux == NULL){
        //throw exception
        return NULL;
    }

    __aux->up       = NULL;
    __aux->bottom   = NULL;
    __aux->right    = NULL;
    __aux->left     = NULL;
    __aux->data     = NULL;

    return __aux;
}
