/* 
 * File:   main.c
 * Author: peterdavis
 *
 * Created on August 28, 2013, 10:45 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"

/*
 * 
 */
int main(int argc, char** argv) {
    linked_list* list;
    list_node* iter;

    list = new_linked_list();
    
    int i = 0;
    for (i = 0; i < 30; i++)
    {
        linked_list_insert(list, i);
    }
    
    iter = linked_list_get_first_element(list);
    while (iter != NULL)
    {
        printf("value %d\n", linked_list_get_element_data(iter));
        iter = linked_list_get_next_element(iter);
    }

    delete_linked_list(list);
    return (EXIT_SUCCESS);
}

