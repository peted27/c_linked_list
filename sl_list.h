#ifndef LINKED_LIST_H
#define LINKED_LIST_H

struct sl_list_node;

struct sl_list_node
{
    struct sl_list_node *next;
    void *data;
};

struct sl_list
{
    int length;
    struct sl_list_node *head;
    struct sl_list_node *tail;
    void (*free_data)(void *data);
};

/**
* Create the list.
*
* @param[in] free_data - function pointer to free data container
* @return a pointer to a new empty list
* @see sl_list_delete()
**/
struct sl_list *sl_list_new(void (*free_data)(void *data));

/**
* Delete the list and all nodes (inclduing their data containers).
*
* @param[in] list - list to free
* @see sl_list_new()
**/
void sl_list_delete(struct sl_list *list);

int sl_list_insert(struct sl_list *list, void *data);

int sl_list_insert_at(struct sl_list *list, void *data, int index);

int sl_list_push(struct sl_list *list, void *data);

int sl_list_push_tail(struct sl_list *list, void *data);

struct sl_list_node *sl_list_get_first_element(struct sl_list *list);

struct sl_list_node *sl_list_get_last_element(struct sl_list *list);

struct sl_list_node *sl_list_pop(struct sl_list *list);

struct sl_list_node *sl_list_pop_tail(struct sl_list *list);

struct sl_list_node *sl_list_get_next_element(struct sl_list_node *node);

void *sl_list_get_element_data(struct sl_list_node *node);

static struct sl_list_node *sl_list_node_create(void *data);

static void sl_list_node_delete(struct sl_list_node *node,
                                void (*free_data)(void *data));

#endif
