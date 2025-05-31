#ifndef LINKED_QUEUE_H
#define LINKED_QUEUE_H

#include <stdlib.h>
#include <stdbool.h>

typedef int Type; // Change this to a struct or other type as needed

typedef struct QueueNode {
    Type data;
    struct QueueNode *next;
} QueueNode;

typedef struct LinkedQueue {
    QueueNode *front;
    QueueNode *rear;
} LinkedQueue;

/**
 * @brief Initializes an empty linked queue.
 * @param queue Pointer to the queue
 */
void queue_init(LinkedQueue *queue);

/**
 * @brief Checks if the queue is empty.
 * @param queue Pointer to the queue
 * @return true if the queue is empty, false otherwise
 */
bool queue_is_empty(const LinkedQueue *const queue);

/**
 * @brief Adds an element to the rear of the queue.
 * @param queue Pointer to the queue
 * @param value Pointer to the value to enqueue
 * @return true if the operation was successful, false if memory allocation failed
 */
bool queue_enqueue(LinkedQueue *queue, const Type *const value);

/**
 * @brief Removes an element from the front of the queue.
 * @param queue Pointer to the queue
 * @param out Pointer to store the dequeued value
 * @return true if successful, false if the queue is empty
 */
bool queue_dequeue(LinkedQueue *queue, Type *out);

/**
 * @brief Retrieves the front element without removing it.
 * @param queue Pointer to the queue
 * @param out Pointer to store the front value
 * @return true if successful, false if the queue is empty
 */
bool queue_peek(const LinkedQueue *const queue, Type *out);

/**
 * @brief Frees all memory associated with the queue.
 * @param queue Pointer to the queue
 */
void queue_free(LinkedQueue *queue);

#endif // LINKED_QUEUE_H
