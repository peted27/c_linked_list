#include <stdio.h>
#include <stdlib.h>
#include "sl_list.h"

void free_int(void *int_p)
{
    free((int *)int_p);
}

int main(int argc, char **argv)
{
    struct sl_list *list;
    struct sl_list_node *iter;
    int i = 0;
    int *temp_data;

    list = sl_list_new(&free_int);


    for (i = 10; i < 20; i++)
    {
        temp_data = malloc(sizeof(int));
        *temp_data = i;
        sl_list_insert(list, temp_data);
    }

    iter = sl_list_get_first_element(list);
    while (iter != NULL)
    {
        printf("value %d\n", *((int *)sl_list_get_element_data(iter)));
        iter = sl_list_get_next_element(iter);
    }

    sl_list_delete(list);
    return (EXIT_SUCCESS);
}
