#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
  int data;
  struct Node* next;
} Node;

typedef struct {
  Node* head;
} Stack;

int   peek(Stack* stack);
int   is_empty(Stack* stack);
void  pop(Stack* stack);
void  init_stack(Stack* stack);
void  push(Stack* stack, int new_data);
Node* create_node(int new_data);

Node* create_node(int new_data){
  Node* node = malloc(sizeof(Node));
  node->data = new_data;
  node->next = NULL;
  return node;
}

void init_stack(Stack* stack){
  stack->head = NULL;
}

int is_empty(Stack* stack){
  return stack->head == NULL;
}

void push(Stack* stack, int new_data){
  Node* node = create_node(new_data);
  if (!node){
    printf("\nStack Overflow");
    return;
  }

  node->next = stack->head;
  stack->head = node;
}

void pop(Stack* stack){
  if (is_empty(stack)){
    printf("\nStack Overflow");
    return;
  } else {
    Node* temp = stack->head;
    stack->head = temp->next;
    free(temp);
  }
}

int peek(Stack* stack){
  if (!is_empty(stack)){
    return stack->head->data;
  } else {
    printf("\nStack Overflow");
    return INT_MIN;
  }
}
