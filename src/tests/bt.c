#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../headers/tree.h"
#include "../headers/node.h"

void printdata(void *__data){
    if(__data != NULL){
        printf("%d: \t%p\n",*(int*)__data,__data);
    }
}

node_t *btreeAdd(node_t *__root, int n)
{
    if(__root != NULL){
        if( *(int*)(__root->data) > n){
            __root->left = btreeAdd(__root->left, n);
        }else{
            __root->right = btreeAdd(__root->right, n);
        }

    }else{
        __root = nodeAlloc();
        __root->data = (void*)malloc(sizeof(int));
        *(int*)(__root->data) = n;

        return __root;
    }
}

int main(){
    node_t *root, *curl, *curr;
/*
    root = nodeAlloc();
    curl = root;
    curr = root;
*/

    srand(time(NULL)); 
    for(int i = 0; i < 500; i++){
        root = btreeAdd(root, rand());
    }

    treeInOrderRec(root, printdata);
}
