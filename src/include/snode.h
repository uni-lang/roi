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

#ifndef ROI_SNODE_H
#define ROI_SNODE_H

#include "memhandler.h"
#include "deftypes.h"


struct snode_t {
    struct snode_t   *right;
    void *data;
};

/** ROI Implementation of dynamic snode (simple node, one link)
    Subvars: snode_t * right. void * data.

    Intended to be used for simple link dynamic structures: queues, stacks.*/
typedef struct snode_t snode_t;

/**  Alloc a snode memory */
snode_t  *snode_alloc();

/**  Free a snode allocated memory, not recursivelly*/
void    snode_free(snode_t *__node);

/** Free a snode allocated memory recursivelly.
    The functions then call the __callback function to free the data pointer
    Caution: This function is quite dangerous, use it properly.*/
void    snode_free_rec(snode_t *__node, void (*__callback)(void *__data));

/*******************************************************************************
                                TO BE REVISED
*******************************************************************************/

/** Link the node __tolink to the right pointer of the __base node.
    If succeeded it returns 1, else return 0.*/
byte    snode_link(snode_t *__base, snode_t *__tolink);


/** Create a node with __data and return its pointer
    If succeded it returns the node's pointer, else returns NULL.*/
snode_t  *snode_new(void *__data);

/** Create a right snode with __data
    If succeded it returns the child's node, else returns NULL.*/
snode_t  *snode_add_right(snode_t *__base, void *__data);

/******************************************************************************/

#endif
