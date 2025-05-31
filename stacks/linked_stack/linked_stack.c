#include "./linked_stack.h"

void linked_stack_init(LinkedStack *stack) {
    stack->top = NULL;
}

bool linked_stack_is_empty(const LinkedStack *const stack) {
    return stack->top == NULL;
}

bool linked_stack_push(LinkedStack *stack, const Type *const value) {
    StackNode *node = malloc(sizeof(StackNode));
    if(!node) {
        return false;
    }

    node->data = *value;
    node->next = stack->top; // For future pop operations
    stack->top = node;

    return true;
}

bool linked_stack_pop(LinkedStack *stack, Type *out) {
    if(linked_stack_is_empty(stack)) {
        return false;
    }

    StackNode *node_to_remove = stack->top;
    *out = node_to_remove->data;
    stack->top = node_to_remove->next;
    free(node_to_remove);

    return true;
}

bool linked_stack_peek(const LinkedStack *const stack, Type *out) {
    if(linked_stack_is_empty(stack)) {
        return false;
    }

    *out = stack->top->data;
    return true;
}

void linked_stack_free(LinkedStack *stack) {
    Type dummy;
    while(linked_stack_pop(stack, &dummy));

    stack->top = NULL;
}