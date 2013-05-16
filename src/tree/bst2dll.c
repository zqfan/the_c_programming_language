/*
convert binary search tree to double linked list, you cannot create
any new node, just can adjust pointer.

sample input bst:
   10
  / /
  6  14
 / / / /
4  8 12 16
sample output dll:
4=6=8=10=12=14=16。
*/
#include<stdlib.h>
#include<stdio.h>

struct BSTreeNode
{
  int value;           // value of node
  BSTreeNode * left;   // left child of node
  BSTreeNode * right;  // right child of node
};

/* binary search tree to double linked list */
void bst2dll(BSTreeNode * root, BSTreeNode ** prev)
{
  if (root == NULL)
    return;
  bst2dll(root->left, prev);
  if (*prev)
    (*prev)->right = root;
  root->left = *prev;
  *prev = root;
  bst2dll(root->right, prev);
}

int main()
{
  BSTreeNode * nodes = (BSTreeNode*)malloc(sizeof(BSTreeNode)*7);
  nodes[0].value = 10;
  nodes[0].left = &nodes[1];
  nodes[0].right = &nodes[2];
  nodes[1].value = 6;
  nodes[1].left = &nodes[3];
  nodes[1].right = &nodes[4];
  nodes[3].value = 4;
  nodes[3].left = NULL;
  nodes[3].right = NULL;
  nodes[4].value = 8;
  nodes[4].left = NULL;
  nodes[4].right = NULL;
  nodes[2].value = 14;
  nodes[2].left = &nodes[5];
  nodes[2].right = &nodes[6];
  nodes[5].value = 12;
  nodes[5].left = NULL;
  nodes[5].right = NULL;
  nodes[6].value = 16;
  nodes[6].left = NULL;
  nodes[6].right = NULL;

  BSTreeNode * prev = NULL;
  bst2dll(&nodes[0], &prev);

  while (prev) {
    printf("%d ", prev->value);
    prev = prev->left;
  }

  free(nodes);
  return 0;
}
