/*******************************************************************************
        SOURCE FILE RELATED TO THE ROISYS (ROI System calls)
*******************************************************************************/

#include <execinfo.h>
#include <stdlib.h>
#include <unistd.h>

#include "headers/iohandler.h"
#include "headers/roisys.h"

#define ROI_BT_BUF_SIZE 100

void systemHalt(char *__message)
{
    int __nptrs;
    void *__backtraceBuffer[ROI_BT_BUF_SIZE];
    char **__backtraceStrings;


    printf("----SYSTEM HALTED----\n");
    printf("----[%s]----\n",__message );
    printf("----BACKTRACE INFORMATION----\n");

    __nptrs = backtrace(__backtraceBuffer, ROI_BT_BUF_SIZE);
    printf("----STACK SIZE: [%d]----\n", __nptrs);

    /* The call backtrace_symbols_fd(buffer, nptrs, STDOUT_FILENO)
       would produce similar output to the following: */
    __backtraceStrings = backtrace_symbols(__backtraceBuffer, __nptrs);
    if (__backtraceStrings == NULL) {
        perror("backtrace_symbols");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < __nptrs; i++)
        printf("%s\n", __backtraceStrings[i]);

    printf("----SYSTEM HALT INFORMATION ABOVE----\n");
    printf("----PLEASE REPORT THE ROI DEVELOPER ABOUT THIS OCURRENCE----\n");


    free(__backtraceStrings);
}
