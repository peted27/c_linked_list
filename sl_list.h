#ifndef LINKED_LIST_H
#define LINKED_LIST_H


/* types */

typedef struct sl_list_node sl_list_node;
typedef struct sl_list sl_list;

struct sl_list_node
{
    sl_list_node* next;
    void* data;
};

struct sl_list
{
    sl_list_node* head;
};

/* list functions */
sl_list* new_sl_list(void);
void delete_sl_list(sl_list*);

/* insert functions */
int sl_list_insert(sl_list*, void*);

/* retrieval functions */
sl_list_node* sl_list_get_first_element(sl_list*);
sl_list_node* sl_list_get_last_element(sl_list*);

/* node functions */
void* sl_list_get_element_data(sl_list_node*);
sl_list_node* sl_list_get_next_element(sl_list_node*);

/* private functions */
static sl_list_node* create_node(void*);
static void delete_node(sl_list_node*);

#endif