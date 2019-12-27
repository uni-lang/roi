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
    SOURCE FILE RELATED TO THE TREE
*******************************************************************************/


#include "headers/node.h"
#include "headers/roisys.h"
#include "headers/tree.h"


void tree_inorder_rec(node_t *__root, void (*__callback)(void *__data))
{
    if(__root != NULL){
        tree_inorder_rec(__root->left, (*__callback));
        __callback(__root->data);
        tree_inorder_rec(__root->right, (*__callback));
    }
}

void tree_preorder_rec(node_t *__root, void (*__callback)(void *__data))
{
    if(__root != NULL){
        __callback(__root->data);
        tree_preorder_rec(__root->left, (*__callback));
        tree_preorder_rec(__root->right, (*__callback));
    }
}

void tree_postorder_rec(node_t *__root, void (*__callback)(void *__data))
{
    if(__root != NULL){
        tree_postorder_rec(__root->left, (*__callback));
        tree_postorder_rec(__root->right, (*__callback));
        __callback(__root->data);
    }
}
