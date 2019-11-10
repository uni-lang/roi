#ifndef ROI_MEMORYHANDLER_H
#define ROI_MEMORYHANDLER_H

/*******************************************************************************
    external dependencies:
*******************************************************************************/
#include <stdlib.h>

    #ifndef NULL
        #define NULL (void*)0x00
    #endif
/** Allocate a memory with __size bytes
    and then return its pointer*/
void *allocMem(size_t __size);

/** Free a allocated memory.
    Returns nothing.*/
void freeMem(void *ptr);

#endif
