#ifndef LINKED_LIST
#define LINKED_LIST 1

/*
 *
 */

// types
typedef struct linked_list_type linked_list;
typedef struct list_node_type list_node;

// list functions
linked_list* new_linked_list(void);
void delete_linked_list(linked_list*);

// insert functions
int linked_list_insert(linked_list*, int);

// retrieval functions
list_node* linked_list_get_first_element(linked_list*);
list_node* linked_list_get_last_element(linked_list*);

// node functions
int linked_list_get_element_data(list_node*);
list_node* linked_list_get_next_element(list_node*);

#endif