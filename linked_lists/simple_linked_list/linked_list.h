#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <stdlib.h>
#include <stdbool.h>

typedef int Type;

typedef struct ListNode {
    Type value;
    struct ListNode *next;
} ListNode;

typedef struct LinkedList {
    size_t length; // Number of elements
    ListNode *head; // First elements of the list
    ListNode *tail; // Last element of the list
} LinkedList;


/**
 * @brief Initializes an empty list.
 * @param list Pointer to the list
 */
void list_init(LinkedList *list);

/**
 * @brief Checks if the list is empty, same as checking using the 'length' member.
 * @param list Pointer to the list
 * @return true if empty, false otherwise
 */
bool list_is_empty(const LinkedList *const list);

/**
 * @brief Returns the number of elements in the list, same as using 'length' member.
 * @param list Pointer to the list
 * @return Number of elements
 */
size_t list_length(const LinkedList *const list);

/**
 * @brief Inserts a new element at the beginning of the list.
 * @param list Pointer to the list
 * @param value Pointer to the value to insert
 * @return true if successful, false if memory allocation failed
 */
bool list_insert_front(LinkedList *list, const Type *const value);

/**
 * @brief Inserts a new element at the end of the list.
 * @param list Pointer to the list
 * @param value Pointer to the value to insert
 * @return true if successful, false if memory allocation failed
 */
bool list_insert_back(LinkedList *list, const Type *const value);

/**
 * @brief Inserts a new element at a specific index.
 * @param list Pointer to the list
 * @param index The index to insert at (0-based)
 * @param value Pointer to the value to insert
 * @return true if successful, false if memory allocation failed or index out of bounds
 */
bool list_insert_at_index(LinkedList *list, size_t index, const Type *const value);

/**
 * @brief Inserts a new element at the correct position in an ascending list.
 * @param list Pointer to the list
 * @param value Pointer to the value to insert
 * @return true if successful, false if memory allocation failed
 */
bool list_insert_ascending(LinkedList *list, const Type *const value);

/**
 * @brief Inserts a new element at the correct position in a descending list.
 * @param list Pointer to the list
 * @param value Pointer to the value to insert
 * @return true if successful, false if memory allocation failed
 */
bool list_insert_descending(LinkedList *list, const Type *const value);

/**
 * @brief Removes the first occurrence of a value.
 * @param list Pointer to the list
 * @param value Pointer to the value to remove
 * @return true if the value was found and removed, false otherwise
 */
bool list_remove(LinkedList *list, const Type *const value);

/**
 * @brief Removes the element at the specified index.
 * @param list Pointer to the list
 * @param index The index of the element to remove (0-based)
 * @return true if the element was found and removed, false if index out of bounds
 */
bool list_remove_at_index(LinkedList *list, size_t index);

/**
 * @brief Searches for a value in the list.
 * @param list Pointer to the list
 * @param value Pointer to the value to search
 * @return true if found, false otherwise
 */
bool list_contains(const LinkedList *const list, const Type *value);

/**
 * @brief Retrieves the value at a specific index.
 * @param list Pointer to the list
 * @param index The index of the element to retrieve (0-based)
 * @param out Pointer to store the retrieved value
 * @return true if successful, false if index is out of bounds
 */
bool list_get_at_index(const LinkedList *const list, size_t index, Type *out);


/**
 * @brief Frees all nodes in the list.
 * @param list Pointer to the list
 */
void list_free(LinkedList *list);

#endif // LINKED_LIST_H