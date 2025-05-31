#ifndef LINKED_STACK_H
#define LINKED_STACK_H

#include <stdbool.h>
#include <stdlib.h>

typedef int Type; // Change this typedef to any other type as needed

typedef struct StackNode { // A node in the stack
    Type data;
    struct StackNode *next;
} StackNode;

typedef struct { // The stack itself
    StackNode *top; // Addrres to the top stack node
} LinkedStack;

/**
 * @brief Initializes the stack
 * @param stack The stack to initialize
 */
void linked_stack_init(LinkedStack *stack);

/**
 * @brief Returns true if the stack is empty
 * @param stack The stack to check
 * @return true if the stack is empty, false otherwise
 */
bool linked_stack_is_empty(const LinkedStack *const stack);

/**
 * @brief Pushes a value onto the stack.
 * @param stack The stack to push onto
 * @param value Pointer to the value to push
 * @return true if the push was successful, false otherwise
 */
bool linked_stack_push(LinkedStack *stack, const Type *const value);

/**
 * @brief Pops a value from the stack into `out`.
 * @param stack The stack to pop from
 * @param out The location to store the popped value
 * @return false if the stack is empty, true otherwise
 */
bool linked_stack_pop(LinkedStack *stack, Type *out);

/** 
 * @brief Peeks the top value without popping.
 * @param stack The stack to peek from
 * @param out The location to store the peeked value
 * @return false if the stack is empty, true otherwise
 */
bool linked_stack_peek(const LinkedStack *stack, Type *out);

/**
 * @brief Frees all memory used by the stack
 * @param stack The stack to free
 */
void linked_stack_free(LinkedStack *stack);

#endif // LINKED_STACK_H
