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

#include <stdio.h>
#include <stdlib.h>

#include "sl_list.h"

void
free_int(void *int_p)
{
        
        free((int *)int_p);
}

int
main(int argc, char *argv[])
{
        struct sl_list *list;
        struct sl_list_node *iter;
        int i = 0;
        int *temp_data;

        list = sl_list_new(&free_int);

        for (i = 10; i < 20; i++) {
                temp_data = malloc(sizeof(int));
                *temp_data = i;
                sl_list_insert(list, temp_data);
        }

        iter = sl_list_get_first(list);
        while (iter != NULL) {
                printf("value %d\n", *((int *)sl_list_get_data(iter)));
                iter = sl_list_get_next(iter);
        }

        sl_list_delete(list);
        return (EXIT_SUCCESS);
}
