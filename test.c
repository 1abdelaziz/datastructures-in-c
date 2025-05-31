#include <stdio.h>
#include "./linked_lists/simple_linked_list/linked_list.h"

int main() {
    LinkedList list;
    list_init(&list);

    int values[] = {10, 20, 30, 40, 50};

    // Insert elements at the back
    for (int i = 0; i < 3; ++i) {
        printf("Inserting %d at back...\n", values[i]);
        list_insert_back(&list, &values[i]);
    }

    // Insert elements at the front
    for (int i = 3; i < 5; ++i) {
        printf("Inserting %d at front...\n", values[i]);
        list_insert_front(&list, &values[i]);
    }

    // Print list contents
    printf("\nList contains %zu elements:\n", list_length(&list));
    ListNode *current = list.head;
    while (current) {
        printf("%d -> ", current->value);
        current = current->next;
    }
    printf("NULL\n");

    // Check contains
    int check = 20;
    printf("\nContains %d? %s\n", check, list_contains(&list, &check) ? "Yes" : "No");

    // Remove an element
    int to_remove = 10;
    printf("Removing %d...\n", to_remove);
    if (list_remove(&list, &to_remove)) {
        printf("Removed successfully.\n");
    } else {
        printf("Value not found.\n");
    }

    // Print updated list
    printf("\nList after removal:\n");
    current = list.head;
    while (current) {
        printf("%d -> ", current->value);
        current = current->next;
    }
    printf("NULL\n");

    // Free memory
    list_free(&list);
    printf("\nList freed. Is empty? %s\n", list_is_empty(&list) ? "Yes" : "No");

    return 0;
}
