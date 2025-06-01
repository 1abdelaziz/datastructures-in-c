#ifndef DOUBLY_LINKED_LIST_H
#define DOUBLY_LINKED_LIST_H

#include <stdlib.h>
#include <stdbool.h>

typedef int Type;

typedef struct DListNode {
    Type value;
    struct DListNode *prev;
    struct DListNode *next;
} DListNode;

typedef struct DLinkedList {
    size_t length;
    DListNode *head;
    DListNode *tail;
} DLinkedList;

/**
 * @brief Initializes an empty doubly linked list.
 * @param list Pointer to the LinkedList to initialize.
 */
void list_init(DLinkedList *list);

/**
 * @brief Checks if the doubly linked list is empty.
 * @param list Pointer to the DLinkedList.
 * @return true if the list is empty, false otherwise.
 */
bool list_is_empty(const DLinkedList *const list);

/**
 * @brief Returns the number of elements in the doubly linked list.
 * @param list Pointer to the DLinkedList.
 * @return The length of the list.
 */
size_t list_length(const DLinkedList *const list);

/**
 * @brief Inserts a new element at the front of the doubly linked list.
 * @param list Pointer to the DLinkedList.
 * @param value Pointer to the value to insert.
 * @return true on success, false if memory allocation failed.
 */
bool list_insert_front(DLinkedList *list, const Type *const value);

/**
 * @brief Inserts a new element at the back of the doubly linked list.
 * @param list Pointer to the DLinkedList.
 * @param value Pointer to the value to insert.
 * @return true on success, false if memory allocation failed.
 */
bool list_insert_back(DLinkedList *list, const Type *const value);

/**
 * @brief Inserts a new element at the specified index.
 * @param list Pointer to the DLinkedList.
 * @param index Position to insert the new element (0-based).
 * @param value Pointer to the value to insert.
 * @return true on success, false if the index is out of bounds or allocation fails.
 */
bool list_insert_at_index(DLinkedList *list, size_t index, const Type *const value);

/**
 * @brief Removes the first occurrence of a specified value from the list.
 * @param list Pointer to the DLinkedList.
 * @param value Pointer to the value to remove.
 * @return true if an element was removed, false if not found.
 */
bool list_remove(DLinkedList *list, const Type *const value);

/**
 * @brief Removes the element at the specified index.
 * @param list Pointer to the DLinkedList.
 * @param index Position of the element to remove (0-based).
 * @return true if the element was removed, false if index is out of bounds.
 */
bool list_remove_at_index(DLinkedList *list, size_t index);

/**
 * @brief Checks if a value exists in the list.
 * @param list Pointer to the DLinkedList.
 * @param value Pointer to the value to search for.
 * @return true if the value exists, false otherwise.
 */
bool list_contains(const DLinkedList *const list, const Type *const value);

/**
 * @brief Gets the value at a specific index.
 * @param list Pointer to the DLinkedList.
 * @param index Position of the element to get (0-based).
 * @param out Pointer to store the value.
 * @return true if the index is valid, false otherwise.
 */
bool list_get_at_index(const DLinkedList *const list, size_t index, Type *out);

/**
 * @brief Frees all elements in the list and resets it to empty.
 * @param list Pointer to the DLinkedList.
 */
void list_free(DLinkedList *list);

#endif // DOUBLY_LINKED_LIST_H
