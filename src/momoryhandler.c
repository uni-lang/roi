/*******************************************************************************
 * source code related to the memory allocation a freed
*******************************************************************************/

#include "headers/memoryhandler.h"

/*******************************************************************************
    external dependencies:
*******************************************************************************/
#include <stdlib.h>


void *allocMem(size_t __size){
    return malloc(__size);
}

void freeMem(void *__ptr){
    free(__ptr);
}
