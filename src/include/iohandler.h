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

#ifndef ROI_IOHANDLER_H
#define ROI_IOHANDLER_H

#include <stdio.h>

/** Write formatted output to stdout.

    This function is a possible cancellation point and therefore not
    marked with __THROW.  */
extern int printf (const char *__restrict __format, ...);

/** Read formatted input from stdin.

    This function is a possible cancellation point and therefore not
    marked with __THROW.  */
extern int scanf (const char *__restrict __format, ...) __wur;

#endif
