
#ifndef _FORWARD_forward_list_H_
#define _FORWARD_forward_list_H_

typedef struct ForwardList ForwardList;

/**
 * @brief Construct a new Linked List:: Linked List object
 *  Allocates memory for a new linked list and returns a pointer to it.
 */
ForwardList *forward_list_construct();

/**
 * @brief Returns the number of nodes in the linked list.
 */
int forward_list_size(ForwardList *l);

/**
 * @brief Pushes a new node to the front of the linked list.
 *  Allocates memory for a new node and inserts it at the front of the linked list.
 */
void forward_list_push_front(ForwardList *l, int data);

/**
 * @brief Print the elements of the linked list.
 */
void forward_list_print(ForwardList *l);

/**
 * @brief Remove the first node of the linked list and returns its data.
 */
int forward_list_pop_front(ForwardList *l);

/**
 * @brief Return a deep copy of the linked list
 */
ForwardList* forward_list_clone(ForwardList *l);

/**
 * @brief Destroys the linked list.
 *  Frees the memory allocated for the linked list and all its nodes.
 */
void forward_list_destroy(ForwardList *l);

#endif