#pragma once

#include <stdint.h>

typedef struct dlist_node {
	struct dlist_node* previous;
	void* item;
	struct dlist_node* next;
} dlist_node_t;

dlist_node_t* dlist_create_empty(void);
void dlist_push_back(dlist_node_t* head, void* item);
void dlist_push_front(dlist_node_t* head, void* item);
void* dlist_get_item(dlist_node_t* head, uint64_t index);
void dlist_remove_item(dlist_node_t* head, void* item);
uint64_t dlist_length(dlist_node_t* head);

#define DLIST_PUSH_BACK(list, item) dlist_push_back(list, (item))
#define DLIST_PUSH_FRONT(list, item) dlist_push_front(list, (item))
#define DLIST_GET_ITEM(list, index, type) ((type*)dlist_get_item(list, index))
#define DLIST_EMPTY dlist_create_empty()
#define DLIST_LENGTH(list) dlist_length(list)
#define DLIST_REMOVE(list, item) dlist_remove_item(list, item);
#define DLIST_FOR(list, name) for(void* name = list; name->next != NULL; name = name->next)