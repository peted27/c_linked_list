#include "linked_list.h"
#include <stdlib.h>

struct list_node_type 
{
    list_node* next;
    int data;
};

struct linked_list_type 
{
    list_node* head;
};

linked_list*
new_linked_list(void) 
{
    linked_list* list;
    list = (linked_list*) malloc(sizeof (*list));
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
        free(current_node);
        current_node = next_node;
    }
    free(list);
}

int 
linked_list_insert(linked_list* list, 
                   int value) 
{
    list_node* node;
    
    // try to create node, return error if unsuccessful
    if ((node = malloc(sizeof (node))) == NULL)
    {
        return -1;
    }
    
    // return error if list is null
    if (list == NULL) 
    {
        return -1;
    }
    
    node->data = value;
    node->next = NULL;

    if (list->head == NULL) {
        list->head = node;
    } else {
        linked_list_get_last_element(list)->next = node;
    }
    
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
    if (list->head == NULL)
    {
        return NULL;
    }
    
    list_node* current_node = list->head;

    while (current_node->next != NULL) {
        current_node = current_node->next;
    }
    
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