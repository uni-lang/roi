#ifndef ROI_MEMORYHANDLER_H
#define ROI_MEMORYHANDLER_H

/*******************************************************************************
    external dependencies:
*******************************************************************************/
#include <stdlib.h>

    #ifndef NULL
        #define NULL (void*)0x00
    #endif

void *allocMem(size_t __size);
void freeMem(void *ptr);

#endif
