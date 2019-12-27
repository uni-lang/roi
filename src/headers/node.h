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

#ifndef ROI_NODE_H
#define ROI_NODE_H

#include "memhandler.h"
#include "deftypes.h"


#define NODE_LINK_LEFT  0
#define NODE_LINK_RIGHT 1

struct node_t {
    struct node_t   *right,
                    *left;
    void *data;
};

/** ROI Implementation of dynamic node
    Subvars: node_t * up, bottom, right, left. void * data.

    Intended to be used for all dynamic structures: trees, AST, queues, stacks.*/
typedef struct node_t node_t;


/**  Alloc a node memory */
node_t  *node_alloc();

/**  Free a node allocated memory, not recursivelly*/
void    node_free(node_t *__node);

/** Free a node allocated memory recursivelly.
    Caution: This function is quite dangerous, use it properly.*/
//void    nodeRecFree(node_t *__node);

/** Free a node allocated memory recursivelly.
    The functions then call the __callback function to free the data pointer
    Caution: This function is quite dangerous, use it properly.*/
void    node_free_rec(node_t *__node, void (*__callback)(void *__data));

/*******************************************************************************
                                TO BE REVISED
*******************************************************************************/

/** Link the node __tolink to the right pointer of the __base node.
    __linkdir: NODE_LINK_LEFT or NODE_LINK_RIGHT
    If succeeded it returns 1, else return 0.*/
byte    node_link(node_t *__base, node_t *__tolink, int __linkdir);

/** Create a node with __data and return its pointer
    If succeded it returns the node's pointer, else returns NULL.*/
node_t  *node_new(void *__data);

/** Create a parent node with __data, link __base to its LEFT or RIGHT node
    and returns the parent node.
    __linkdir: NODE_LINK_LEFT or NODE_LINK_RIGHT
    If succeded it returns the child's node, else returns NULL.*/
node_t  *node_add_child(node_t *__base, void *__data, int __linkdir);

/** Create a parent node with __data, link __base to its LEFT or RIGHT node
    and returns the parent node.
    __linkdir: NODE_LINK_LEFT or NODE_LINK_RIGHT
    If succeded it returns parent's node, else returns NULL.*/
node_t  *node_add_parent(node_t *__base, void *__data, int __linkdir);


/******************************************************************************/






#endif
