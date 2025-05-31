#include "./linked_list.h"

void list_init(LinkedList *list) {
    list->length = 0;
    list->head = NULL;
}

bool list_is_empty(const LinkedList *const list) {
    return !list->length;
}

size_t list_length(const LinkedList *const list) {
    return list->length;
}

bool list_insert_front(LinkedList *list, const Type *const value) {
    ListNode *new_node = malloc(sizeof(ListNode));
    if(!new_node) {
        return false;
    }

    new_node->value = *value;
    new_node->next = list->head;
    list->head = new_node;
    list->length++;

    return true;
}

bool list_insert_back(LinkedList *list, const Type *const value) {
    if(list_is_empty(list)) {
        return list_insert_front(list, value);
    }

    ListNode *new_node = malloc(sizeof(ListNode));
    if(!new_node) {
        return false;
    }
    new_node->next = NULL;
    new_node->value = *value;

    // Get the last node's address
    ListNode *last_node = list->head;
    while(last_node->next) {
        last_node = last_node->next;
    }

    last_node->next = new_node;
    list->length++;
    return true;
}

bool list_remove(LinkedList *list, const Type *const value) {
    if(list_is_empty(list)) {
        return false;
    }

    if(list->head->value == *value) {
        ListNode *temp = list->head;
        list->head = list->head->next;

        list->length--;
        free(temp);
        return true;
    }

    ListNode *previous_node = list->head;
    while(previous_node->next) {
        if(previous_node->next->value == *value) {
            ListNode *temp = previous_node->next;
            previous_node->next = temp->next;

            list->length--;
            free(temp);
            return true;
        }

        previous_node = previous_node->next;
    }

    return false;
}

bool list_contains(const LinkedList *const list, const Type *const value) {
    if(list_is_empty(list)) {
        return false;
    }

    ListNode *node = list->head;
    while(node) {
        if(node->value == *value) {
            return true;
        }

        node = node->next;
    }

    return false;
}

void list_free(LinkedList *list) {
    ListNode *node = list->head;
    ListNode *temp;

    while(node) {
        temp = node;
        node = node->next;
        free(temp);
    }

    list->head = NULL;
    list->length = 0;
}