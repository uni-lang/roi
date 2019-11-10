#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../headers/tree.h"
#include "../headers/node.h"

void freeCallback(void *__data){
    free(__data);
}


int main(){
    char str[128];

    printf("Expression to parse: ");
    scanf(" %[^\n]",str);


}
