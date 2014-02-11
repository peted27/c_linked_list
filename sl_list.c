#include "sl_list.h"
#include <stdlib.h>


struct sl_list* sl_list_new(void (*free_data)(void* data))
{
    struct sl_list* list;
	
	if (free_data == NULL)
		return NULL;
	
    if ((list = malloc(sizeof (*list))) == NULL)
        return NULL;

    list->head = NULL;
	list->tail = NULL;
	list->length = 0;
	list->free_data = free_data;

    return list;
}

void sl_list_delete(struct sl_list* list) 
{
    struct sl_list_node* current_node = list->head;
    struct sl_list_node* next_node;
    
    while(current_node != NULL) 
    {
        next_node = current_node->next;
        sl_list_node_delete(current_node, list->free_data);
        current_node = next_node;
    }

    free(list);
}

int sl_list_insert(struct sl_list* list, void* data) 
{
    struct sl_list_node* node;

    if (list == NULL) 
        return 1;
	
	if (data == NULL)
		return 1;

    if ((node = sl_list_node_create(data)) == NULL)
        return 1;

    if (list->head == NULL) 
        list->head = node;
    else
        sl_list_get_last_element(list)->next = node;
	
	list->length += 1;
	list->tail = node;
    
    return 0;
}

struct sl_list_node* sl_list_get_first_element(struct sl_list* list) 
{
	if (list == NULL)
		return NULL;
	
    return list->head;
}

struct sl_list_node* sl_list_get_last_element(struct sl_list* list)
{
    if (list == NULL)
        return NULL;
    
    return list->tail;
}

void* sl_list_get_element_data(struct sl_list_node* node)
{
	if (node == NULL)
		return NULL;
	
    return node->data;
}

struct sl_list_node* sl_list_get_next_element(struct sl_list_node* node)
{
	if (node == NULL)
		return NULL;
		
    return node->next;
}

static struct sl_list_node* sl_list_node_create(void* data)
{
    struct sl_list_node* node;

	if (data == NULL)
		return NULL;

    if ((node = malloc(sizeof (node))) == NULL)
        return NULL;
    
    node->data = data;
    node->next = NULL;

    return node;
}

static void sl_list_node_delete(struct sl_list_node* node, 
                                void (*free_data)(void* data))
{
	if (node != NULL) 
	{
		free_data(node->data);
		free(node);
	}
}