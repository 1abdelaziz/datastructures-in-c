#include "./linked_list.h"

void list_init(LinkedList *list) {
    list->length = 0;
    list->head = NULL;
    list->tail = NULL;
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

    if(list->length == 1) {
        list->tail = list->head;
    }

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

    list->tail->next = new_node;
    list->tail = new_node;
    list->length++;

    return true;
}

bool list_insert_at_index(LinkedList *list, size_t index, const Type *const value) {
    if (index > list->length) {
        return false;
    }

    if (index == 0) {
        return list_insert_front(list, value);
    }

    if (index == list->length) {
        return list_insert_back(list, value);
    }

    ListNode *new_node = malloc(sizeof(ListNode));
    if (!new_node){
        return false;
    }
    new_node->value = *value;

    // Traverse to the node just before the index
    ListNode *current = list->head; // Start with the head
    for (size_t i = 0; i < index - 1; i++) {
        current = current->next;
    }

    new_node->next = current->next;
    current->next = new_node;
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

bool list_remove_at_index(LinkedList *list, size_t index) {
    if(index >= list->length) {
        return false;
    }
    ListNode *current = list->head;

    if(index == 0) {
        list->head = current->next;
        free(current);
        list->length--;

        return true;
    }

    // Traverse to the node just before the index
    for(size_t i = 0; i < index - 1; i++) {
        current = current->next;
    }

    ListNode *temp = current->next->next;
    free(current->next);
    current->next = temp;

    if(index == list->length - 1) {
        list->tail = current;
    }

    list->length--;
    return true;
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

bool list_get_at_index(const LinkedList *const list, size_t index, Type *out) {
    if(index >= list->length) {
        return false;
    }

    ListNode *node = list->head;
    for(size_t i = 0; i < index; i++) {
        node = node->next;
    }

    *out = node->value;
    return true;
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
    list->tail = NULL;
    list->length = 0;
}