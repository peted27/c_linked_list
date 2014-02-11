#ifndef LINKED_LIST_H
#define LINKED_LIST_H


/* types */

struct sl_list_node;

struct sl_list_node
{
    struct sl_list_node* next;
    void* data;
};

struct sl_list
{
	int length;
    struct sl_list_node* head;
	struct sl_list_node* tail;
	void (*free_data)(void* data);
};

/**
*
* Initiate the list.
*
* @param[in] 
* @return 
* @see SLISTdestroy()
*
**/


/**
*
* Create the list.
*
* @return a pointer to a new empty list
* @see sl_list_delete()
*
**/
struct sl_list* sl_list_new(void (*free_data)(void* data));

void sl_list_delete(struct sl_list* list);

int sl_list_insert(struct sl_list* list, void*);

int sl_list_insert_at(struct sl_list* list, void* data, int);

int sl_list_push(struct sl_list* list, void* data);

int sl_list_push_tail(struct sl_list* list, void* data);

struct sl_list_node* sl_list_get_first_element(struct sl_list* list);

struct sl_list_node* sl_list_get_last_element(struct sl_list* list);

struct sl_list_node* sl_list_pop(struct sl_list* list);

struct sl_list_node* sl_list_pop_tail(struct sl_list* list);

struct sl_list_node* sl_list_get_next_element(struct sl_list_node* node);

void* sl_list_get_element_data(struct sl_list_node* node);

static struct sl_list_node* sl_list_node_create(void* data);

static void sl_list_node_delete(struct sl_list_node* node, 
                                void (*free_data)(void* data));

#endif