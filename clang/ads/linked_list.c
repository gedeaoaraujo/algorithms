#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
  int data;
  struct Node* next;
} Node;

Node* create_node(int data);
void  insert_front(Node** head, int data);
void  insert_end(Node** head, int data);
void  insert_at(Node** head, int data, int position);
void  delete_first(Node** head);
void  delete_last(Node** head);
void  delete_at(Node** head, int position);
void  print(Node* head);

Node* create_node(int data){
  Node* node = malloc(sizeof(Node));
  node->data = data;
  node->next = NULL;
  return node;
}

void insert_front(Node** head, int data){
  Node* node = create_node(data);
  node->next = *head;
  *head = node;
}

void insert_end(Node** head, int data){
  Node* node = create_node(data);
  if (*head == NULL){
    *head = node;
    return;
  }

  Node* temp = *head;
  while (temp->next != NULL) {
    temp = temp->next;
  }
  
  temp->next = node;
}

void insert_at(Node** head, int data, int position){
  Node* node = create_node(data);
  if (position == 0){
    insert_front(head, data);
    return;
  }

  Node* temp = *head;
  for (int i = 0; temp != NULL && i < position -1; i++) {
    temp = temp->next;
  }

  if (temp == NULL){
    printf("Position out of range\n");
    free(node);
    return;
  }

  node->next = temp->next;
  temp->next = node;
}

void delete_first(Node** head){
  if (*head == NULL){
    printf("List is empty\n");
    return;
  }

  Node* temp = *head;
  *head = temp->next;
  free(temp);
}

void delete_last(Node** head){
  if (*head == NULL){
    printf("List is empty\n");
    return;
  }

  Node* temp = *head;
  if (temp->next == NULL){
    free(temp);
    *head = NULL;
    return;
  }

  while (temp->next->next != NULL) {
    temp = temp->next;
  }

  free(temp->next);
  temp->next = NULL;
}

void delete_at(Node** head, int position){
  if (*head == NULL){
    printf("List is empty\n");
    return;
  }

  Node* temp = *head;
  if (position == 0){
    delete_first(head);
    return;
  }

  for (int i = 0; temp != NULL && i < position -1; i++) {
    temp = temp->next;
  }

  if (temp == NULL || temp->next == NULL){
    printf("Position out of range\n");
    return;
  }

  Node* next = temp->next->next;
  free(temp->next);
  temp->next = next;
}

void print(Node* head){
  Node* temp = head;
  while (temp != NULL) {
    printf("%d -> ", temp->data);
    temp = temp->next;
  }
  printf("NULL\n");
}
