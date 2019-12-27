/*******************************************************************************

    This file is part of ROI Interpreter (https://github.com/uni-lang/roi)
    Copyright (C) 2019  Gustavo M. A. Primo

    ROI Interpreter is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    ROI Interpreter is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with ROI Interpreter.  If not, see <http://www.gnu.org/licenses/>.

*******************************************************************************/

/*******************************************************************************
        SOURCE FILE RELATED TO THE ROISYS (ROI System calls)
*******************************************************************************/

#include <execinfo.h>
#include <stdlib.h>
#include <unistd.h>

#include "headers/iohandler.h"
#include "headers/roisys.h"

/** ROI C Stack Backtrace buffer size*/
#define ROI_BT_BUF_SIZE 100

void system_halt(char *__message)
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
