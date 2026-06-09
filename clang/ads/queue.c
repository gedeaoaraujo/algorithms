#include <stdbool.h>
#include <stdio.h>
#include <stdbool.h>

#define MAX_SIZE 100

typedef struct {
  int items[MAX_SIZE];
  int front;
  int rear;
} Queue;

bool  isfull(Queue* queue);
bool  isempty(Queue* queue);
int   peek(Queue* queue);
void  init(Queue* queue);
void  print(Queue* queue);
void  dequeue(Queue* queue);
void  enqueue(Queue* queue, int value);

void init(Queue* queue){
  queue->front = -1;
  queue->rear = 0;
}

bool isempty(Queue* queue){
  return queue->front == (queue->rear - 1);
}

bool isfull(Queue* queue){
  return queue->rear >= MAX_SIZE;
}

void enqueue(Queue* queue, int value){
  if (isfull(queue)){
    printf("Queue is full\n");
    return;
  }

  queue->items[queue->rear] = value;
  queue->rear++;
}

void dequeue(Queue* queue){
  if (isempty(queue)){
    printf("Queue is empty\n");
    return;
  }
  queue->front++;
}

int peek(Queue* queue){
  if (isempty(queue)){
    printf("Queue is empty\n");
    return -1;
  }
  return queue->items[queue->front + 1];
}

void print(Queue* queue){
  if (isempty(queue)){
    printf("Queue is empty\n");
    return;
  }

  printf("Current Queue: ");
  for (int i = queue->front + 1; i < queue->rear; i++){
    printf("%d ", queue->items[i]);
  }

  printf("\n");
}
