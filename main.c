/* 
 * File:   main.c
 * Author: peterdavis
 *
 * Created on August 28, 2013, 10:45 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include "sl_list.h"

/*
 * 
 */
int 
main(int argc, char** argv) 
{
    sl_list* list;
    sl_list_node* iter;
    int i = 0;
    int* temp_data;

    list = new_sl_list();
    

    for (i = 10; i < 20; i++)
    {
        temp_data = malloc(sizeof(int));
        *temp_data = i;
        sl_list_insert(list, (void*)temp_data);
    }
    
    iter = sl_list_get_first_element(list);
    while (iter != NULL)
    {
        printf("value %d\n", *((int*)sl_list_get_element_data(iter)));
        iter = sl_list_get_next_element(iter);
    }

    delete_sl_list(list);
    return (EXIT_SUCCESS);
}

