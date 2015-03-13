// tree.h
#ifndef TREE_H
#define TREE_H
#include <stdio.h>
typedef struct treenode
{
  struct treenode * left;
  struct treenode * right;
  int value;
} TreeNode;

// insert a value v to a binary search tree starting 
// with root, return the new root
TreeNode * Tree_insert(TreeNode * root, int v);

// search a value in a binary search tree starting 
// with root, return the node whose value is v, 
// or NULL if no such node exists
TreeNode * Tree_search(TreeNode * root, int v);

// delete the node whose value is v in a binary search 
// tree starting with root, return the root of the 
// remaining tree, or NULL if the tree is empty
TreeNode * Tree_delete(TreeNode * root, int v);

// print the values stored in the binary search tree 
void Tree_print(TreeNode * root);

// delete every node 
void Tree_destroy(TreeNode * root);
#endif
