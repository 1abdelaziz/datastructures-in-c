#ifndef STATIC_STACK_H
#define STATIC_STACK_H

#include <stdbool.h>
#include <stddef.h>

typedef int Type;  // Change this to float, struct, etc., for a different data type

typedef struct {
    Type *items;
    size_t capacity; 
    size_t top;
} StaticStack;

/**
 * @brief Initializes the stack.
 * @param stack Pointer to the stack to initialize.
 */
bool stack_init(StaticStack *stack, size_t capacity);

/**
 * @brief Checks if the stack is empty.
 * @param stack Pointer to the stack.
 * @return true if empty, false otherwise.
 */
bool stack_is_empty(const StaticStack *stack);

/**
 * @brief Checks if the stack is full.
 * @param stack Pointer to the stack.
 * @return true if full, false otherwise.
 */
bool stack_is_full(const StaticStack *stack);

/**
 * @brief Pushes a value onto the stack.
 * @param stack Pointer to the stack.
 * @param value Pointer to the value to push.
 * @return true if successful, false if stack is full.
 */
bool stack_push(StaticStack *stack, const Type *const value);

/**
 * @brief Pops a value from the stack.
 * @param stack Pointer to the stack.
 * @param out Pointer to store the popped value.
 * @return true if successful, false if stack is empty.
 */
bool stack_pop(StaticStack *stack, Type *out);

/**
 * @brief Peeks at the top value of the stack without popping it.
 * @param stack Pointer to the stack.
 * @param out Pointer to store the top value.
 * @return true if successful, false if stack is empty.
 */
bool stack_peek(const StaticStack *stack, Type *out);

/**
 * @brief Frees the memory allocated for the stack.
 * @param stack Pointer to the stack.
 */
void stack_free(StaticStack *stack);

#endif // STATIC_STACK_H
