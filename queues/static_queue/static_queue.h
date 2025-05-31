#ifndef STATIC_QUEUE_H
#define STATIC_QUEUE_H

#include <stdbool.h>
#include <stdlib.h>

typedef int Type; // Change this to another type when needed

typedef struct {
    Type *items;
    size_t capacity;
    size_t size; // Number of elements
    size_t front; // Front index
    size_t rear; // Rear index
} StaticQueue;

/**
 * @brief Initializes the queue.
 * @param queue Pointer to the queue
 * @param capacity Maximum number of elements the queue can hold
 * @return true if initialization is successful, false otherwise
 */
bool queue_init(StaticQueue *queue, size_t capacity);

/**
 * @brief Checks if the queue is empty.
 * @param queue Pointer to the queue
 * @return true if empty, false otherwise
 */
bool queue_is_empty(const StaticQueue *const queue);

/**
 * @brief Checks if the queue is full.
 * @param queue Pointer to the queue
 * @return true if full, false otherwise
 */
bool queue_is_full(const StaticQueue *const queue);

/**
 * @brief Enqueues an element into the queue.
 * @param queue Pointer to the queue
 * @param value The value to enqueue
 * @return true if successful, false if queue is full
 */
bool queue_enqueue(StaticQueue *queue, const Type *const value);

/**
 * @brief Dequeues an element from the queue.
 * @param queue Pointer to the queue
 * @param out Pointer to store the dequeued value
 * @return true if successful, false if queue is empty
 */
bool queue_dequeue(StaticQueue *queue, Type *out);

/**
 * @brief Peeks at the front element without removing it.
 * @param queue Pointer to the queue
 * @param out Pointer to store the value
 * @return true if successful, false if queue is empty
 */
bool queue_peek(const StaticQueue *const queue, Type *out);

/**
 * @brief Frees any memory used by the queue.
 * @param queue Pointer to the queue
 */
void queue_free(StaticQueue *queue);

#endif // STATIC_QUEUE_H
