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

#ifndef ROI_TREE_H
#define ROI_TREE_H

#include "node.h"
#include "deftypes.h"

/*
//Reduntant definition, primitive
typedef struct tree_t {
    node_t * root;
} Tree;
*/


/** Tree traversal recursivelly inorder
    Calls the __callback function passing the data pointer to it. */
void treeInOrderRec(node_t *__root, void (*__callback)(void *__data));

/** Tree traversal recursivelly preorder
    Calls the __callback function passing the data pointer to it. */
void treePreOrderRec(node_t *__root, void (*__callback)(void *__data));

/** Tree traversal recursivelly postorder
    Calls the __callback function passing the data pointer to it. */
void treePostOrderRec(node_t *__root, void (*__callback)(void *__data));


#endif
