#include "sl_list.h"
#include <stdlib.h>


sl_list* new_sl_list(void) 
{
    sl_list* list;
	
    if ((list = malloc(sizeof (*list))) == NULL)
        return NULL;

    list->head = NULL;

    return list;
}

void delete_sl_list(sl_list* list) 
{
    sl_list_node* current_node = list->head;
    sl_list_node* next_node;
    
    while(current_node != NULL) 
    {
        next_node = current_node->next;
        delete_node(current_node);
        current_node = next_node;
    }

    free(list);
}

int sl_list_insert(sl_list* list, void* value) 
{
    sl_list_node* node;

    if (list == NULL) 
        return 1;
	
	if (value == NULL)
		return 1;

    if ((node = create_node(value)) == NULL)
        return 1;

    if (list->head == NULL) 
        list->head = node;
    else
        sl_list_get_last_element(list)->next = node;
    
    return 0;
}

sl_list_node* sl_list_get_first_element(sl_list* list) 
{
	if (list == NULL)
		return NULL;
	
    return list->head;
}

sl_list_node* sl_list_get_last_element(sl_list* list)
{
    sl_list_node* current_node;

    if (list->head == NULL)
        return NULL;
    
    current_node = list->head;

    while (current_node->next != NULL) 
        current_node = current_node->next;
    
    return current_node;
}

void* sl_list_get_element_data(sl_list_node* node)
{
	if (node == NULL)
		return NULL;
	
    return node->data;
}

sl_list_node* sl_list_get_next_element(sl_list_node* node)
{
	if (node == NULL)
		return NULL;
		
    return node->next;
}

static sl_list_node* create_node(void* value)
{
    sl_list_node* node;

	if (value == NULL)
		return NULL;

    if ((node = malloc(sizeof (node))) == NULL)
        return NULL;
    
    node->data = value;
    node->next = NULL;

    return node;
}

static void delete_node(sl_list_node* node)
{
    free(node->data);
    free(node);
}