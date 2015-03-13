// sparse.c
#include "sparse.h"
#include <stdio.h>
#include <stdlib.h>
static Node * Node_create(int ind, int val);
static Node * List_insert(Node * head, int ind, int val);
static Node * List_copy(Node * head);
Node * List_read(char * filename)
{
  FILE * fptr = fopen(filename, "r");
  if (fptr == NULL)
    {
      return NULL;
    }
  int ind;
  int val;
  Node * head = NULL;
  while (fscanf(fptr, "%d %d", & ind, & val) == 2)
    {
      head = List_insert(head, ind, val);
    }
  fclose (fptr);
  return head;
}
int List_save(char * filename, Node * arr)
{
  FILE * fptr = fopen(filename, "w");
  if (fptr == NULL)
    {
      return 0;
    }
  while (arr != NULL)
    {
      fprintf(fptr, "%d %d\n", arr -> index, arr -> value);
      arr = arr -> next;
    }
  fclose (fptr);
  return 1;
}
Node * List_merge(Node * arr1, Node * arr2)
{
  Node * arr3 = List_copy(arr1);
  while (arr2 != NULL)
    {
      arr3 = List_insert(arr3, arr2 -> index, 
			 arr2 -> value);
      arr2 = arr2 -> next;
    }
  return arr3;
}
void List_destroy(Node * arr)
{
  if (arr == NULL)
    {
      return;
    }
  while (arr != NULL)
    {
      Node * ptr = arr -> next;
      free (arr);
      arr = ptr;
    }
}
static Node * Node_create(int ind, int val)
{
  Node * nd = malloc(sizeof(Node));
  if(nd == NULL)
    {
      return NULL;
    }
  nd -> index = ind;
  nd -> value = val;
  nd -> next = NULL;
  return nd;
}
// If the same index appears again, add the value
// The returned list is sorted by the index.
static Node * List_insert(Node * head, int ind, int val)
{
  if (val == 0) // do not insert zero value
    {
      return head; 
    }
  if (head == NULL)
    {
      return Node_create(ind, val);
    }
  if ((head -> index) > ind)
    {
      // insert the new node before the list
      Node * ptr = Node_create(ind, val);
      ptr -> next = head;
      return ptr;
    }
  if ((head -> index) == ind)
    {
      // merge the nodes
      head -> value += val;
      if ((head -> value) == 0)
	{
	  // delete this node
	  Node * ptr = head -> next;
	  free (head);
	  return ptr;
	}
      return head;
    }
  head -> next = List_insert(head -> next, ind, val);
  return head;
}
Node * List_copy(Node * arr)
{
  Node * arr2 = NULL;
  while (arr != NULL)
    {
      arr2 = List_insert(arr2, arr -> index, arr -> value);
      arr = arr -> next;
    }
  return arr2;
}
