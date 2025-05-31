#include "./linked_queue.h"

void queue_init(LinkedQueue *queue) {
    queue->front = NULL;
    queue->rear = NULL;
}

bool queue_is_empty(const LinkedQueue *const queue) {
    return !queue->front;
}

bool queue_enqueue(LinkedQueue *queue, const Type *const value) {
    QueueNode *new_node = malloc(sizeof(QueueNode));
    if(!new_node) {
        return false;
    }

    new_node->data = *value;
    new_node->next = NULL;

    if(queue_is_empty(queue)) {
        queue->front = new_node;
        queue->rear = new_node;
    } else {
        queue->rear->next = new_node;
        queue->rear = new_node;
    }
    
    return true;
}

bool queue_dequeue(LinkedQueue *queue, Type *out) {
    if(queue_is_empty(queue)) {
        return false;
    }

    *out = queue->front->data;
    QueueNode *temp = queue->front;
    queue->front = queue->front->next;
    if (queue->front == NULL) {
        queue->rear = NULL;
    }

    free(temp);
    return true;
}

bool queue_peek(const LinkedQueue *const queue, Type *out) {
    if(queue_is_empty(queue)) {
        return false;
    }

    *out = queue->front->data;
    return true;
}

void queue_free(LinkedQueue *queue) {
    Type dummy;
    while(queue_dequeue(queue, &dummy));
    
    queue->front = NULL;
    queue->rear = NULL;
}   