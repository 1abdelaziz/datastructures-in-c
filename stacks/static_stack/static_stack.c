#include "./static_stack.h"
#include <stdlib.h>

bool stack_init(StaticStack *stack, size_t capacity) {
    stack->items = malloc(capacity * sizeof(Type));
    if(stack->items == NULL) {
        return false;
    }

    stack->capacity = capacity;
    stack->top = -1;
    return true;
}

bool stack_is_empty(const StaticStack *stack) {
    return stack->top == -1;
}

bool stack_is_full(const StaticStack *stack) {
    return stack->top == stack->capacity - 1;
}

bool stack_push(StaticStack *stack, const Type *const value) {
    if(stack_is_full(stack)) {
        return false;
    }

    stack->items[++stack->top] = *value;
    return true;
}

bool stack_pop(StaticStack *stack, Type *out) {
    if(stack_is_empty(stack)) {
        return false;
    }

    *out = stack->items[stack->top--];
    return true;
}

bool stack_peek(const StaticStack *stack, Type *out) {
    if (stack_is_empty(stack)) {
        return false;
    }

    *out = stack->items[stack->top];
    return true;
}

void stack_free(StaticStack *stack) {
    free(stack->items);
}
