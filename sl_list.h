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

#ifndef SL_LIST_H
#define SL_LIST_H

/* LIST MACROS */
#define SL_LIST_ENTRY(type)                     \
        struct type *sl_list_next

#define SL_LIST(name, type)                     \
        struct name {                           \
                struct type *sl_list_head;      \
                struct type *sl_list_tail;      \
                int sl_list_count;              \
        }

/* UTIL MACROS */
#define SL_LIST_INIT(list)                      \
        (list)->sl_list_head = NULL;            \
        (list)->sl_list_tail = NULL;            \
        (list)->sl_list_count = 0; 

#define SL_LIST_HEAD(list)                      \
        (list)->sl_list_head

#define SL_LIST_TAIL(list)                      \
        (list)->sl_list_tail

#define SL_LIST_NEXT(elem)                      \
        (elem)->sl_list_next

#define SL_LIST_COUNT(list)                     \
        (list)->sl_list_count

#define SL_LIST_EMPTY(list)                     \
        ((list)->sl_list_head == NULL)


/* INSERT MACROS */
#define SL_LIST_INSERT_HEAD(list, elem)             \
        SL_LIST_NEXT(elem) = SL_LIST_HEAD(list);    \
        SL_LIST_HEAD(list) = (elem);                \
        SL_LIST_COUNT(list)++;                 

#define SL_LIST_INSERT_TAIL(list, elem)                        \
        if(SL_LIST_EMPTY(list))                                \
                SL_LIST_HEAD(list) = (elem);                   \
        else                                                   \
                SL_LIST_NEXT(SL_LIST_TAIL(list)) = (elem);     \
        SL_LIST_TAIL(list) = (elem);                           \
        SL_LIST_COUNT(list)++;                                 \
                           

/* ITERATION MACROS */
#define SL_LIST_FOREACH(list, var)              \
        for ((var) = SL_LIST_HEAD(list);        \
             (var);                             \
             (var) = SL_LIST_NEXT((var)))


#endif
