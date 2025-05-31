#include "./static_queue.h"

bool queue_init(StaticQueue *queue, size_t capacity) {
    queue->items = malloc(sizeof(Type) * capacity);
    if(!queue->items) {
        return false;
    }
    
    queue->front = 0;
    queue->rear = 0;
    queue->capacity = capacity;
    queue->size = 0;

    return true;
}

bool queue_is_empty(const StaticQueue *const queue) {
    return !queue->size;
}

bool queue_is_full(const StaticQueue *const queue) {
    return queue->size == queue->capacity;
}

bool queue_enqueue(StaticQueue *queue, const Type *const value) {
    if(queue_is_full(queue)) {
        return false;
    }

    queue->items[queue->rear] = *value;
    queue->rear = (queue->rear + 1) % queue->capacity;
    queue->size++;

    return true;
}

bool queue_dequeue(StaticQueue *queue, Type *out) {
    if(queue_is_empty(queue)) {
        return false;
    }

    *out = queue->items[queue->front];
    queue->front = (queue->front + 1) % queue->capacity;
    queue->size--;
    
    return true;
}

bool queue_peek(const StaticQueue *const queue, Type *out) {
    if(queue_is_empty(queue)) {
        return false;
    }

    *out = queue->items[queue->front];
    return true;
}

void queue_free(StaticQueue *queue) {
    free(queue->items);
}