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

#include "include/deftypes.h"
#include "include/memhandler.h"
#include "include/snode.h"

#include "include/roisys.h"

node_t  *snode_alloc()
{
    snode_t *__aux;

    __aux = (snode_t*)alloc_mem(sizeof(snode_t));

    if(__aux == NULL){
        system_halt("Node alloc returned NULL pointer");
        //throw exception
        return NULL;
    }

    __aux->right    = NULL;
    __aux->data     = NULL;

    return __aux;
}

void snode_free(snode_t *__node)
{
    free_mem(__node);
}

void snode_free_rec(snode_t *__node, void (*__callback)(void *__data))
{
    if(__node != NULL){
        if(__node->right != NULL){
            snode_free_rec(__node->right,__callback);
        }

        __callback(__node->data);
        free_mem(__node);
    }else{
        //throw exception
    }
}

byte snode_link(snode_t *__base, snode_t *__tolink)
{
    if(__base != NULL && __tolink != NULL){
        __base->right = __tolink;
        return TRUE;
    }
    return FALSE;
}

snode_t  *snode_new(void *__data)
{
        snode_t *__aux;
        __aux = snode_alloc();
        __aux->data = __data;
        return __aux;
}

snode_t  *snode_add_right(snode_t *__base, void *__data)
{
    if(__base != NULL){
        snode_t *__child;
        __child = snode_alloc();
        __child->data = __data;

        __base->right = __child;

        return __child;
    }else{
        system_halt("Node __base not allocated");
    }

    return NULL;
}
