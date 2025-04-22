#include <stdio.h>
#include <stdlib.h>

typedef struct Queue {
    int front;
    int rear;
    int size;
    int* arr;
}Queue;

void createQueue(Queue* queue, int size) {
    queue->front = 0;
    queue->rear = 0;
    queue->size = size;
    //把0作为哨兵，防止队列为空时出队时出错
    queue->arr = (int*)malloc(size * sizeof(int) + 1);
}

int isEmpty(Queue* queue) {
    return queue->front != queue->rear;
}

void push(Queue* queue, int data) {
    if (abs(queue->front - queue->rear) == queue->size) {
        printf("队列满\n");
        return -1;
    }

    queue->arr[queue->rear] = data;//尾指针的前一个位置入队
    queue->rear = (queue->rear + 1) % queue->size;//队列尾指针加1
}

int pop(Queue* queue) {
    if (abs(queue->front - queue->rear) == queue->size) {
        printf("队列满\n");
        return -1;
    }

    int data = queue->arr[queue->front];//队首元素出队
    queue->front = (queue->front + 1) % queue->size;//队列头指针加1
    return data;
}

int top(Queue* queue) {
    if (abs(queue->front - queue->rear) == queue->size) {
        printf("队列满\n");
        return -1;
    }

    return queue->arr[queue->front];
}

int main() {
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    createQueue(queue, 5);
    push(queue, 1);
    push(queue, 2);
    push(queue, 3);
    push(queue, 4);
    push(queue, 5);
    printf("队首元素:%d\n", top(queue));
    printf("队列是否为空:%d\n", isEmpty(queue));
    printf("出队元素:%d\n", pop(queue));
    printf("队首元素:%d\n", top(queue));
    printf("队列是否为空:%d\n", isEmpty(queue));
    return 0;
}
