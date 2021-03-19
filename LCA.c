#include <stdio.h>
#include <stdlib.h>

struct node {
  int num;
  struct node* left;
  struct node* right;
};

struct node* createNode(int value) {
  struct node* newnode = malloc(sizeof(struct node));

  newnode->num = value;
  newnode->left = NULL;
  newnode->right = NULL;
}

struct node* insertLeft(struct node* root, int value) {
  root->left = createNode(value);

  return root->left;
}

struct node* insertRight(struct node* root, int value) {
  root->right = createNode(value);

  return root->right;
}

void inorderTraversal(struct node* root) {
  if (root == NULL) return;
  inorderTraversal(root->left);
  printf("%d ->", root->num);
  inorderTraversal(root->right);
}

struct node* findLCA(struct node* root, int a, int b) {
  if (root != NULL) {
    if (root->num == a || root->num == b) {
      return root;
    }

    struct node* left = findLCA(root->left, a, b);
    struct node* right = findLCA(root->right, a, b);

    if (left && right) {
      return root;
    }
    if (left) return left;
    if (right) return right;
  }
}

int main() {
  struct node* root = createNode(1);

  insertLeft(root, 2);
  insertRight(root, 3);
  insertLeft(root->left, 4);
  insertLeft(root->right, 6);
  insertRight(root->right, 7);

  inorderTraversal(root);
  printf("%d\n");
  struct node* res = findLCA(root, 4, 6);
  printf("LCA = %d", res->num);
  return 0;
}

