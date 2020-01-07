#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../include/tree.h"
#include "../include/node.h"

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

node_t *parserPrimitive(char *__str, node_t *__cur)
{


}

int main(){
    char str[128];

    printf("Expression to parse: ");
    scanf(" %[^\n]",str);
    node_t *root = parserPrimitive(str, NULL);

}
