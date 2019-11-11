#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../headers/tree.h"
#include "../headers/node.h"

struct token_t{
    char operator;
    int weight;
};

typedef struct token_t token_t;

void freeCallback(void *__data){
    free(__data);
}

token_t *charToToken(char c){
    token_t *__aux;
    __aux = (token_t*)malloc(sizeof(token_t));

    __aux->operator = c;
    if(c == '+' || c == '-'){
        __aux->weight = 0;
    }
    if(c == '*' || c == '/'){
        __aux->weight = 1;
    }
    if(c == '^'){
        __aux->weight = 2;
    }

    if(c >= '0' && c<= '9'){
        __aux->weight = 3;
    }

    return __aux;
}

void printdata(void *__data){
    if(__data != NULL){
        printf("%d: \t%p\n",*(int*)__data,__data);
    }
}

void freeCallback(void *__data){
    free(__data);
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
    nodeRecFree(root,freeCallback);

}
