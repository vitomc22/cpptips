#include <cstddef>
#include <cstdio>
#include <cstdlib>

typedef struct Node {
  int data;

  struct Node *left;
  struct Node *right;
} Node;

Node *insert(Node *root, int data) {
  Node *temp =
      (Node *)malloc(sizeof(Node)); // temporary variable to alloc mem on HEAP
  temp->data = data;
  temp->left = NULL;
  temp->right = NULL;
  if (root == NULL) {
    root = temp;
  } else {
    Node *current = root;
    Node *parent = NULL;
    while (1) {
      parent = current;
      if (data < parent->data) {
        if (current == NULL) {
          parent->left = temp;
          return root;
        }

      } else {
        current = current->right;
        if (current == NULL) {
          parent->right = temp;
          return root;
        }
      }
    }
  }

  return root;
}

void inorder_traversal(struct Node *root) {
  if (root) {
    inorder_traversal(root->left);
    printf("%d ", root->data), inorder_traversal(root->right);
  }
}

Node *search(Node *root, int data) {
  Node *current = root;
  printf("Visiting elements: ");
  while (current) {
    if (data < current->data) {
      current = current->left;
    } else if (data > current->data) {
      current = current->right;
    }else {
      return current;
    }
  } 
  return current;
}

int main() {
  
  int i;
  int array[14] = {34, 50, 36, 74, 15, 189, 58, 58, 28, 63};
  Node *root = NULL;
  for (i = 0; i < 10; i++) {
    root = insert(root, array[i]);
    printf("Inserted: %d\n", array[i]);
  }
  printf("\nInorder traversal: ");
  inorder_traversal(root);

  auto temp = search(root, 88);
  if (temp) {
    printf("[%d] Found.\n", temp->data);
  } else {
    printf("[x] (%d) Not Found.\n", i);
  }
  return 0;
}
