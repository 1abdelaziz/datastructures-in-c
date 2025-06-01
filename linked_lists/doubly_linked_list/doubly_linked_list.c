#include "doubly_linked_list.h"

void list_init(DLinkedList *list) {
    list->length = 0;
    list->head = NULL;
    list->tail = NULL;
}

bool list_is_empty(const DLinkedList *const list) {
    return !list->length;
}

size_t list_length(const DLinkedList *const list) {
    return list->length;
}

bool list_insert_front(DLinkedList *list, const Type *const value) {
    DListNode *node = malloc(sizeof(DListNode));
    if(!node) {
        return false;
    }

    node->value = *value;
    node->next = list->head;
    node->prev = NULL;

    if(list_is_empty(list)) {
        list->tail = node;
    } else {
        list->head->prev = node;
    }

    list->head = node;
    list->length++;
    return true;
}

bool list_insert_back(DLinkedList *list, const Type *const value) {
    DListNode *node = malloc(sizeof(DListNode));
    if(!node) {
        return false;
    }

    node->value = *value;
    node->next = NULL;
    node->prev = list->tail;

    if(list_is_empty(list)) {
        list->head = node;
    } else {
        list->tail->next = node;
    }

    list->tail = node;
    list->length++;
    return true;
}

bool list_insert_at_index(DLinkedList *list, size_t index, const Type *const value) {
    if(index > list->length) {
        return false;
    }

    if(index == 0) {
        return list_insert_front(list, value);
    }

    if(index == list->length) {
        return list_insert_back(list, value);
    }

    DListNode *node = malloc(sizeof(DListNode));
    if(!node) {
        return false;
    }

    node->value = *value;

    // Traverse to the index - 1
    DListNode *current;
    if (index - 1 < list->length / 2) {
        current = list->head;
        for (size_t i = 0; i < index - 1; i++) {
            current = current->next;
        }
    } else {
        current = list->tail;
        for (size_t i = list->length - 1; i > index - 1; i--) {
            current = current->prev;
        }
    }

    node->prev = current;
    node->next = current->next;
    current->next->prev = node;
    current->next = node;

    list->length++;
    return true;
}

bool list_remove(DLinkedList *list, const Type *const value) {
    DListNode *node = list->head;

    while(node) {
        if(node->value == *value) {
            break;
        }

        node = node->next;
    }

    if(!node) {
        return false;
    }

    if(node != list->head) {
        node->prev->next = node->next;
    } else {
        list->head = node->next;
    }

    if(node != list->tail) {
        node->next->prev = node->prev;
    } else {
        list->tail = node->prev; 
    }

    free(node);
    list->length--;
    return true;
}

bool list_remove_at_index(DLinkedList *list, size_t index) {
    if(index >= list->length) {
        return false;
    }

    DListNode *node;
    if (index < list->length / 2) {
        node = list->head;
        for (size_t i = 0; i < index; i++) {
            node = node->next;
        }
    } else {
        node = list->tail;
        for (size_t i = list->length - 1; i > index; i--) {
            node = node->prev;
        }
    }

    if(node != list->head) {
        node->prev->next = node->next;
    } else {
        list->head = node->next;
    }

    if(node != list->tail) {
        node->next->prev = node->prev;
    } else {
        list->tail = node->prev; 
    }

    free(node);
    list->length--;
    return true;
}

bool list_contains(const DLinkedList *const list, const Type *const value) {
    DListNode *node = list->head;

    while(node) {
        if(node->value == *value) {
            return true;
        }

        node = node->next;
    }

    return false;
}

bool list_get_at_index(const DLinkedList *const list, size_t index, Type *out) {
    if(index >= list->length) {
        return false;
    }

    DListNode *node;
    if (index < list->length / 2) {
        node = list->head;
        for (size_t i = 0; i < index; i++) {
            node = node->next;
        }
    } else {
        node = list->tail;
        for (size_t i = list->length - 1; i > index; i--) {
            node = node->prev;
        }
    }

    *out = node->value;
    return true;
}

void list_free(DLinkedList *list) {
    DListNode *current = list->head;

    while(current) {
        DListNode  *next = current->next;
        free(current);
        current = next;
    }

    list->head = NULL;
    list->tail = NULL;
    list->length = 0;
}