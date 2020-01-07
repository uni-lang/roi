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

#ifndef ROI_xnode_H
#define ROI_xnode_H

#include "memoryhandler.h"
#include "deftypes.h"

/**ROI Implementation of dynamic xnode
   Subvars: xnode_t * up, bottom, right, left. void * data.

   Intended to be used for all dynamic structures: trees, AST, queues, stacks.*/
typedef struct xnode_t {
    struct xnode_t *bottom;
    struct xnode_t *right;
    struct xnode_t *left;
    void *data;
} xnode_t;

/** Alloc a xnode memory */
xnode_t  *xnode_alloc();

/** Free a xnode allocated memory, not recursivelly*/
void    xnode_free(xnode_t *__xnode);

/** Free a xnode allocated memory recursivelly.
    Caution: This function is quite dangerous, use it properly.*/
void    xnode_free_rec(xnode_t *__xnode);

/*******************************************************************************
                                TO BE REVISED
*******************************************************************************/

/** Link the xnode __tolink to the top pointer of the __base xnode.
    If succeded it returns 1, else returns 0.*/
byte    xnode_link_top(xnode_t *__base, xnode_t *__tolink);

/** Link the xnode __tolink to the bottom pointer of the __base xnode.
    If succeeded it returns 1, else return 0.*/
byte    xnode_link_bottom(xnode_t *__base, xnode_t *__tolink);

/** Link the xnode __tolink to the right pointer of the __base xnode.
    If succeeded it returns 1, else return 0.*/
byte    xnode_link_right(xnode_t *__base, xnode_t *__tolink);

/** Link the xnode __tolink to the left pointer of the __base xnode.
    If succeeded it returns 1, else return 0.*/
byte    xnode_link_left(xnode_t *__base, xnode_t *__tolink);


/******************************************************************************/

/** Add the data __data to the top pointer of the __base xnode.
    If succeded it returns 1, else returns 0.*/
byte    xnode_add_top(xnode *__base, void *__data);







#endif
