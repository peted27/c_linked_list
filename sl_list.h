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
 * @param[in] free_data function pointer to free data container
 * @retval NULL something went wrong
 * @retval else pointer to new list
* @see sl_list_delete()
 **/
struct sl_list *sl_list_new(void (*free_data)(void *data));


/**
 * Delete the list and all nodes (inclduing their data containers).
 *
 * @param[in] list list to operate on
 * @see sl_list_new()
 **/
void sl_list_delete(struct sl_list *list);


/**
 * Insert data in to a list
 *
 * @param[in] list list to operate on
 * @param[in] data data to be inserted
 * @retval 0 successfull
 * @retval else something went wrong
 * @see sl_list_insert_at() sl_list_push()
 **/
int sl_list_insert(struct sl_list *list, void *data);


/**
 * Insert data into list at specified index
 *
 * @param[in] list  list to operate on
 * @param[in] data  data to be inserted
 * @param[in] index index to insert at, if out of bounds will
 *              return error code
 * @retval 0 successfull
 * @retval else something went wrong
 * @see sl_list_insert()
 **/
int sl_list_insert_at(struct sl_list *list, void *data, int index);


/**
 * Push data on to beginning of list
 *
 * @param[in] list list to operate on
 * @param[in] data data to be pushed
 * @retval 0 successfull
 * @retval else something went wrong
 * @see ..
 **/
int sl_list_push(struct sl_list *list, void *data);


/**
 * Push data on to end of list
 *
 * @param[in] list list to operate on
 * @param[in] data data to be pushed
 * @retval 0 successfull
 * @retval else something went wrong
 * @see ..
 **/
int sl_list_push_tail(struct sl_list *list, void *data);


/**
 * Get first element of list
 *
 * @param[in] list list to operate on
 * @retval NULL something went wrong
 * @retval else pointer to first element
 * @see sl_list_get_last()
 **/
struct sl_list_node *sl_list_get_first(struct sl_list *list);


/**
 * Get last element of list
 *
 * @param[in] list - list to operate on
 * @retval NULL something went wrong
 * @retval else pointer to last element
 * @see sl_list_get_first()
 **/
struct sl_list_node *sl_list_get_last(struct sl_list *list);


/**
 * Get first element of the list and remove it from the list
 * note: node and contents should be manually free()d
 *
 * @param[in] list list to operate on
 * @retval NULL something went wrong
 * @retval else pointer to list node
 * @see sl_list_pop_tail()
 **/
struct sl_list_node *sl_list_pop(struct sl_list *list);


/**
 * Get last element of list and remove it from list
 * note: node and contents should be manually free()d
 *
 * @param[in] list list to operate on
 * @retval NULL something went wrong
 * @retval else pointer to list node
 * @see sl_list_pop()
 **/
struct sl_list_node *sl_list_pop_tail(struct sl_list *list);


/**
 * Get next element of a list
 *
 * @param[in] node the current node
 * @retval NULL something went wrong
 * @retval else pointer to next node in list
 * @see ..
 **/
struct sl_list_node *sl_list_get_next(struct sl_list_node *node);


/**
 * Get a pointer to the data container of a node
 *
 * @param[in] node node to get contents of
 * @retval NULL something went wrong
 * @retval else pointer to data container
 * @see ..
 **/
void *sl_list_get_data(struct sl_list_node *node);

#endif
