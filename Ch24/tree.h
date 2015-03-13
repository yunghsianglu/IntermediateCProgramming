// tree.h
#ifndef TREE_H
#define TREE_H
typedef struct treenode
{
  struct treenode * left;
  struct treenode * right;
  char value; // character
  int freq;  // frequency
} TreeNode;
TreeNode * TreeNode_create(char val, int freq);
TreeNode * Tree_merge(TreeNode * tn1, TreeNode * tn2);
void Tree_print(TreeNode * tn, int level);
// find the maximum height of the leaf nodes
int Tree_height(TreeNode * tn);
// find the number of leaf nodes
int Tree_leaf(TreeNode * tn);
// save the header of a compressed file
void Tree_header(TreeNode * tn, unsigned int numChar, char * outfile);
void Tree_destroy(TreeNode * tn);
#endif
