/*
 * Copyright (c) 2014, peted
 * All rights reserved. 
 * Redistribution and use in source and binary forms, with or without 
 * modification, are permitted provided that the following conditions are met: 
 *        
 * 1. Redistributions of source code must retain the above copyright notice, this 
 *    list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright notice, 
 *    this list of conditions and the following disclaimer in the documentation 
 *    and/or other materials provided with the distribution.
 *
 * 3. Neither the name of test nor the names of its
 *    contributors may be used to endorse or promote products derived from 
 *    this software without specific prior written permission. 
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" 
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE 
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE 
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE 
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL 
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR 
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER 
 * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, 
 * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE 
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE. 
 */

#include <stdlib.h>

#include "sl_list.h"


static struct sl_list_node *sl_list_node_create(void *data);

static void sl_list_node_delete(struct sl_list_node *node,
                                void (*free_data)(void *data));




struct sl_list *
sl_list_new(void (*free_data)(void *data))
{
        struct sl_list *list;

        if (free_data == NULL)
                return NULL;

        if ((list = malloc(sizeof (*list))) == NULL)
                return NULL;

        list->head = NULL;
        list->tail = NULL;
        list->length = 0;
        list->free_data = free_data;

        return list;
}


void
sl_list_delete(struct sl_list *list)
{
        struct sl_list_node *current_node = list->head;
        struct sl_list_node *next_node;

        while(current_node != NULL) {
                next_node = current_node->next;
                sl_list_node_delete(current_node, list->free_data);
                current_node = next_node;
        }

        free(list);
}


int
sl_list_insert(struct sl_list *list, void *data)
{
        struct sl_list_node *node;

        if (list == NULL)
                return 1;

        if (data == NULL)
                return 1;

        if ((node = sl_list_node_create(data)) == NULL)
                return 1;

        if (list->head == NULL)
                list->head = node;
        else
                sl_list_get_last_element(list)->next = node;

        list->length += 1;
        list->tail = node;

        return 0;
}


int
sl_list_insert_at(struct sl_list *list, void *data, int index)
{
        /* TODO */

        return 1;
}


int
sl_list_push(struct sl_list *list, void *data)
{
        /* TODO */

        return 1;
}


int
sl_list_push_tail(struct sl_list *list, void *data)
{
        /* TODO */

        return 1;
}


struct sl_list_node *
sl_list_get_first_element(struct sl_list *list)
{
        if (list == NULL)
                return NULL;

        return list->head;
}


struct sl_list_node *
sl_list_get_last_element(struct sl_list *list)
{
        if (list == NULL)
                return NULL;

        return list->tail;
}


struct sl_list_node *
sl_list_pop(struct sl_list *list)
{
        /* TODO */

        return NULL;
}


struct sl_list_node *
sl_list_pop_tail(struct sl_list *list)
{
        /* TODO */

        return NULL;
}


struct sl_list_node *
sl_list_get_next_element(struct sl_list_node *node)
{
        if (node == NULL)
                return NULL;

        return node->next;
}


void *
sl_list_get_element_data(struct sl_list_node *node)
{
        if (node == NULL)
                return NULL;

        return node->data;
}


static struct sl_list_node *
sl_list_node_create(void *data)
{
        struct sl_list_node *node;

        if (data == NULL)
                return NULL;

        if ((node = malloc(sizeof (node))) == NULL)
                return NULL;

        node->data = data;
        node->next = NULL;

        return node;
}


static void
sl_list_node_delete(struct sl_list_node *node,
                                void (*free_data)(void *data))
{
        if (node != NULL) {
                free_data(node->data);
                free(node);
        }
}
