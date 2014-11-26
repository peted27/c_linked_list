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

#ifndef LINKED_LIST_H
#define LINKED_LIST_H

struct sl_list_node;

struct sl_list_node {
        struct sl_list_node *next;
        void                *data;
};

struct sl_list {
        int                 length;
        struct sl_list_node *head;
        struct sl_list_node *tail;
        void                (*free_data)(void *data);
};

/**
 * Create the list.
 *
 * @param[in] free_data - function pointer to free data container
 * @return a pointer to a new empty list
 * @see sl_list_delete()
 **/
struct sl_list *sl_list_new(void (*free_data)(void *data));


/**
 * Delete the list and all nodes (inclduing their data containers).
 *
 * @param[in] list - list to free
 * @see sl_list_new()
 **/
void sl_list_delete(struct sl_list *list);


/**
 * Insert data in to a list
 *
 * @param[in] list - list to insert in to
 * @param[in] data - data to be inserted
 * @return 0 for success, else error code on failure
 * @see sl_list_insert_at() sl_list_push()
 *
 **/
int sl_list_insert(struct sl_list *list, void *data);


int sl_list_insert_at(struct sl_list *list, void *data, int index);


int sl_list_push(struct sl_list *list, void *data);


int sl_list_push_tail(struct sl_list *list, void *data);


struct sl_list_node *sl_list_get_first_element(struct sl_list *list);


struct sl_list_node *sl_list_get_last_element(struct sl_list *list);


struct sl_list_node *sl_list_pop(struct sl_list *list);


struct sl_list_node *sl_list_pop_tail(struct sl_list *list);


struct sl_list_node *sl_list_get_next_element(struct sl_list_node *node);


void *sl_list_get_element_data(struct sl_list_node *node);

#endif
