#ifndef LINKED_LIST_H
#define LINKED_LIST_H


/* types */

typedef struct list_node_t list_node;
typedef struct linked_list_t linked_list;

struct list_node_t 
{
    list_node* next;
    int data;
};

struct linked_list_t
{
    list_node* head;
};

/* list functions */
linked_list* new_linked_list(void);
void delete_linked_list(linked_list*);

/* insert functions */
int linked_list_insert(linked_list*, int);

/* retrieval functions */
list_node* linked_list_get_first_element(linked_list*);
list_node* linked_list_get_last_element(linked_list*);

/* node functions */
int linked_list_get_element_data(list_node*);
list_node* linked_list_get_next_element(list_node*);

/* private functions */
static list_node* create_node(int);
static void delete_node(list_node*);

#endif