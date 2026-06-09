#include <stdio.h>
#include <stdbool.h>
#include <stdbool.h>

#define MAX_SIZE 100

typedef struct {
  int top;
  int array[MAX_SIZE];
} Stack;

int   pop(Stack* stack);
int   peek(Stack* stack);
bool  is_full(Stack* stack);
bool  is_empty(Stack* stack);
void  init(Stack* stack);
void  push(Stack* stack, int value);

void init(Stack* stack){
  stack->top = -1;
}

bool is_empty(Stack* stack){
  return stack->top == -1;
}

bool is_full(Stack* stack){
  return stack->top == MAX_SIZE - 1;
}

void push(Stack* stack, int value){
  if (is_full(stack)){
    printf("Stack Overflow\n");
    return;
  }

  stack->array[++stack->top] = value;
  printf("Pushed %d onto the stack\n", value);
}

int pop(Stack* stack){
  if (is_empty(stack)){
    printf("Stack Overflow\n");
    return -1;
  }

  int popped = stack->array[stack->top];
  stack->top--;
  printf("Popped %d from the stack\n", popped);

  return popped;
}

int peek(Stack* stack){
  if (is_empty(stack)){
    printf("Stack is empty\n");
    return -1;
  }
  return stack->array[stack->top];
}
