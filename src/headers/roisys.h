#ifndef ROI_ROISYS_H
#define ROI_ROISYS_H

/*  Kill all threads and stop the interpreter immediatelly.
    Can be called when a fatal error occurs without a exception handler
    Stop using this function right after a exception handler for the error is
    implemented*/
void systemHalt(char *__message);

#endif
