#include <stdlib.h>

typedef struct Node {
  int data;
  struct Node* next;
  struct Node* prev;
} Node;

Node* create_node(int data);

Node* create_node(int data){
  Node* node = malloc(sizeof(Node));
  node->data = data;
  node->next = NULL;
  node->prev = NULL;
  return node;
}
