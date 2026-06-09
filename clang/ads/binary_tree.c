#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
  int data;
  struct Node* left;
  struct Node* right;
} Node;

Node* create_node(int data);
Node* search_node(Node *root, int data);
Node* get_deepest_right_node(Node *root);
void  inorder_traversal(Node *root);
void  insert_node(Node **root, int data);
void  delete_node(Node **root, int data);
void  del_deepest_right_node(Node *root, Node *d_node);

Node *create_node(int data) {
  Node *node = malloc(sizeof(Node));
  node->data = data;
  node->left = NULL;
  node->right = NULL;
  return node;
}

void insert_node(Node **root, int data) {
  Node *node = create_node(data);
  if (*root == NULL) {
    *root = node;
    return;
  }

  int rear = -1;
  int front = -1;
  Node *temp = {0};
  Node *queue[100];
  queue[++rear] = *root;

  while (front != rear) {
    temp = queue[++front];

    if (temp->left == NULL) {
      temp->left = node;
      return;
    } else {
      queue[++rear] = temp->left;
    }

    if (temp->right == NULL) {
      temp->right = node;
      return;
    } else {
      queue[++rear] = temp->right;
    }
  }
}

Node *get_deepest_right_node(Node *root) {
  Node *temp = {0};
  Node *queue[100];

  int rear = -1;
  int front = -1;
  queue[++rear] = root;

  while (front != rear) {
    temp = queue[++front];

    if (temp->left != NULL)
      queue[++rear] = temp->left;

    if (temp->right != NULL)
      queue[++rear] = temp->right;
  }

  return temp;
}

void del_deepest_right_node(Node *root, Node *d_node) {
  Node *temp;
  Node *queue[100];

  int rear = -1;
  int front = -1;
  queue[++rear] = root;

  while (front != rear) {
    temp = queue[++front];

    if (temp == d_node) {
      temp = NULL;
      free(d_node);
      return;
    }

    if (temp->right != NULL) {
      if (temp->right == d_node) {
        temp->right = NULL;
        free(d_node);
        return;
      } else {
        queue[++rear] = temp->right;
      }
    }

    if (temp->left != NULL) {
      if (temp->left == d_node) {
        temp->left = NULL;
        free(d_node);
        return;
      } else {
        queue[++rear] = temp->left;
      }
    }
  }
}

void delete_node(Node **root, int data) {
  if (*root == NULL) {
    printf("Tree is empty.\n");
    return;
  }

  if ((*root)->left == NULL && (*root)->right == NULL) {
    if ((*root)->data == data) {
      free(*root);
      *root = NULL;
      return;
    } else {
      printf("Node not found.\n");
      return;
    }
  }

  Node *temp;
  Node *queue[100];

  int rear = -1;
  int front = -1;
  queue[++rear] = *root;
  Node *key_node = NULL;

  while (front != rear) {
    temp = queue[++front];

    if (temp->data == data)
      key_node = temp;

    if (temp->left != NULL)
      queue[++rear] = temp->left;

    if (temp->right != NULL)
      queue[++rear] = temp->right;
  }

  if (key_node != NULL) {
    Node *deepest_node = get_deepest_right_node(*root);
    key_node->data = deepest_node->data;
    del_deepest_right_node(*root, deepest_node);
  } else {
    printf("Node not found.\n");
  }
}

Node *search_node(Node *root, int data) {
  if (root == NULL) return NULL;

  Node *temp;
  Node *queue[100];

  int rear = -1;
  int front = -1;
  queue[++rear] = root;

  while (front != rear) {
    temp = queue[++front];

    if (temp->data == data)
      return temp;

    if (temp->left != NULL)
      queue[++rear] = temp->left;

    if (temp->right != NULL)
      queue[++rear] = temp->right;
  }

  return NULL;
}

void inorder_traversal(Node *root) {
  if (root == NULL) return;
  inorder_traversal(root->left);
  printf("%d ", root->data);
  inorder_traversal(root->right);
}

int main() {
  Node *root = NULL;

  // Inserting nodes
  insert_node(&root, 20);
  insert_node(&root, 30);
  insert_node(&root, 40);
  insert_node(&root, 50);
  insert_node(&root, 60);
  insert_node(&root, 70);
  insert_node(&root, 80);

  // Inorder traversal
  printf("Inorder traversal of the given Binary Search Tree is: ");
  inorder_traversal(root);
  printf("\n");

  // Deleting a node
  int delete_value = 20;
  delete_node(&root, delete_value);
  printf("After deletion of %d: ", delete_value);
  inorder_traversal(root);
  printf("\n");

  // Inserting a new node
  int insert_value = 25;
  insert_node(&root, insert_value);
  printf("After insertion of %d: ", insert_value);
  inorder_traversal(root);
  printf("\n");

  // Searching for a node
  int target = 25;
  Node *search_result = search_node(root, target);
  if (search_result != NULL) {
    printf("Node %d found in the BST.\n", target);
  } else {
    printf("Node %d not found in the BST.\n", target);
  }

  return 0;
}
