#include "linked_list.h"
#include <stdlib.h>


linked_list*
new_linked_list(void) 
{
    linked_list* list;

    list = malloc(sizeof (*list));
    list->head = NULL;

    return list;
}

void
delete_linked_list(linked_list* list) 
{
    list_node* current_node = list->head;
    list_node* next_node;
    
    while(current_node != NULL) 
    {
        next_node = current_node->next;
        delete_node(current_node);
        current_node = next_node;
    }
    
    free(list);
}

int 
linked_list_insert(linked_list* list, 
                   int value) 
{
    list_node* node;

    /* return error if list is null */
    if (list == NULL) 
        return -1;

    if ((node = create_node(value)) == NULL)
        return -1;

    if (list->head == NULL) 
        list->head = node;
    else
        linked_list_get_last_element(list)->next = node;
    
    return 1;
}

list_node*
linked_list_get_first_element(linked_list* list) 
{
    return list->head;
}

list_node*
linked_list_get_last_element(linked_list* list)
{
    list_node* current_node;

    if (list->head == NULL)
        return NULL;
    
    current_node = list->head;

    while (current_node->next != NULL) 
        current_node = current_node->next;
    
    return current_node;
}

int
linked_list_get_element_data(list_node* node)
{
    return node->data;
}

list_node* 
linked_list_get_next_element(list_node* node)
{
    return node->next;
}

static
list_node*
create_node(int value)
{
    list_node* node;
    
    /* try to create node, return error if unsuccessful */
    if ((node = malloc(sizeof (node))) == NULL)
        return NULL;
    
    node->data = value;
    node->next = NULL;

    return node;
}

static
void
delete_node(list_node* node)
{
    free(node);
}