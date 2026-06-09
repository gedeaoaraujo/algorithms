#include <stdio.h>
#include <stdlib.h>

typedef struct BTreeNode {
  int key;
  struct BTreeNode *left;
  struct BTreeNode *right;
} BTreeNode;

void inOrder(BTreeNode *root);
void preOrder(BTreeNode *root);
void postOrder(BTreeNode *root);
BTreeNode *newNode(int value);
BTreeNode *findMin(BTreeNode *root);
BTreeNode *delete(BTreeNode *root, int x);
BTreeNode *searchNode(BTreeNode *root, int target);
BTreeNode *insertNode(BTreeNode *node, int value);

BTreeNode *newNode(int value) {
  BTreeNode *temp = malloc(sizeof(BTreeNode));
  temp->key = value;
  temp->left = temp->right = NULL;
  return temp;
}

BTreeNode *searchNode(BTreeNode *root, int target) {
  if (root == NULL || root->key == target) {
    return root;
  }
  if (root->key < target) {
    return searchNode(root->right, target);
  }
  return searchNode(root->left, target);
}

BTreeNode *insertNode(BTreeNode *node, int value) {
  if (node == NULL)
    return newNode(value);

  if (value < node->key) {
    node->left = insertNode(node->left, value);
  } else if (value > node->key) {
    node->right = insertNode(node->right, value);
  }
  return node;
}

void postOrder(BTreeNode *root) {
  if (root == NULL) return;
  postOrder(root->left);
  postOrder(root->right);
  printf(" %d ", root->key);
}

void inOrder(BTreeNode *root) {
  if (root == NULL) return;
  inOrder(root->left);
  printf(" %d ", root->key);
  inOrder(root->right);
}

void preOrder(BTreeNode *root) {
  if (root == NULL) return;
  printf(" %d ", root->key);
  preOrder(root->left);
  preOrder(root->right);
}

BTreeNode *findMin(BTreeNode *root) {
  if (root == NULL) {
    return NULL;
  } else if (root->left != NULL) {
    return findMin(root->left);
  }
  return root;
}

BTreeNode *delete(BTreeNode *root, int x) {
  if (root == NULL) return NULL;

  if (x > root->key) {
    root->right = delete(root->right, x);
    return root;
  }

  if (x < root->key) {
    root->left = delete(root->left, x);
    return root;
  }

  if (root->left == NULL && root->right == NULL) {
    free(root);
    return NULL;
  }

  if (root->left == NULL || root->right == NULL) {
    BTreeNode *temp;

    if (root->left == NULL)
      temp = root->right;
    else
      temp = root->left;

    free(root);
    return temp;
  }

  BTreeNode *temp = findMin(root->right);
  root->key = temp->key;
  root->right = delete (root->right, temp->key);
  return root;
}

int main() {
  BTreeNode *root = NULL;

  root = insertNode(root, 50);
  insertNode(root, 30);
  insertNode(root, 20);
  insertNode(root, 40);
  insertNode(root, 70);
  insertNode(root, 60);
  insertNode(root, 80);

  if (searchNode(root, 60) != NULL) {
    printf("60 found");
  } else {
    printf("60 not found");
  }

  printf("\n");

  postOrder(root);
  printf("\n");

  preOrder(root);
  printf("\n");

  inOrder(root);
  printf("\n");

  /* BTreeNode *temp = */ delete(root, 70);
  printf("After Delete: \n");
  inOrder(root);

  return 0;
}
