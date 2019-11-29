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
    SOURCE FILE RELATED TO THE NODE USED IN AST, LISTS, QUEUES, STACKS...
*******************************************************************************/

#include "headers/deftypes.h"
#include "headers/memoryhandler.h"
#include "headers/node.h"

#include "headers/roisys.h"

node_t  *nodeAlloc()
{
    node_t *__aux;

    __aux = (node_t*)allocMem(sizeof(node_t));

    if(__aux == NULL){
        systemHalt("Node alloc returned NULL pointer");
        //throw exception
        return NULL;
    }

    __aux->right    = NULL;
    __aux->left     = NULL;
    __aux->data     = NULL;

    return __aux;
}

void nodeFree(node_t *__node)
{
    freeMem(__node);
}

void nodeRecFree(node_t *__node, void (*__callback)(void *__data))
{
    if(__node != NULL){
        if(__node->right != NULL){
            nodeRecFree(__node->right,__callback);
        }
        if(__node->left != NULL){
            nodeRecFree(__node->left,__callback);
        }

        __callback(__node->data);
        freeMem(__node);
    }else{
        //throw exception
    }
}

byte nodeLink(node_t *__base, node_t *__tolink, int __linkdir)
{
    if(__base != NULL && __tolink != NULL){
        if(__linkdir == NODE_LINK_LEFT){
            __base->left = __tolink;
        }else{
            __base->right = __tolink;
        }
        return TRUE;
    }
    return FALSE;
}

node_t  *nodeNew(void *__data)
{
        node_t *__aux;
        __aux = nodeAlloc();
        __aux->data = __data;
        return __aux;
}

node_t  *nodeAddChild(node_t *__base, void *__data, int __linkdir)
{
    if(__base != NULL){
        node_t *__child;
        __child = nodeAlloc();
        __child->data = __data;

        if(__linkdir == NODE_LINK_LEFT){
            __base->left = __child;
        }else{
            __base->right = __child;
        }

        return __child;
    }else{
        systemHalt("Node __base not allocated");
    }

    return NULL;
}

node_t  *nodeAddParent(node_t *__base, void *__data, int __linkdir)
{
    if(__base != NULL){
        node_t *__parent;
        __parent = nodeAlloc();
        __parent->data = __data;

        if(__linkdir == NODE_LINK_LEFT){
            __parent->left = __base;
        }else{
            __parent->right = __base;
        }

        return __parent;
    }else{
        systemHalt("Node __base not allocated");
    }

    return NULL;
}
