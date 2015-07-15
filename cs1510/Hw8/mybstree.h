//Ryan Andrews
//CS 1510       Section: B

#ifndef MYBSTREE_H
#define MYBSTREE_H

#include <iostream>
using namespace std;

template <typename T>
struct TreeNode
{
  T data;
  T* left;
  T* right;
}

template <typename T>
class MyBSTree : public AbstractBSTree
{
  TreeNode* root;
  int size;
  
  MyBSTree() : root(NULL), size(0) {}
  //////////////////////////////////////////////////////
  int size() const
  {
    return size;
  }
  //////////////////////////////////////////////////////
  bool isEmpty() const
  {
    if (root != NULL)
      return false;
    else
      return true;
  }
  //////////////////////////////////////////////////////
  int height() const
  {
    return height(root);
  }
  int height(TreeNode* & t) const
  {
    int Height = 0;
    if (t->left == NULL && t->right == NULL)
      return Height;
    else if (t->left != NULL && t->right == NULL)
    {
      Height += height(r->left);
      Height++;
    }
    else if (t->left == NULL && t->right != NULL)
    {
      Height += height(r->right);
      Height++;
    }
    else
    {
      Height += height(r->left);
      if (height(r->right) > Height)
        Height = height(r->right)
      Height++;
      return Height;
    }
  }
  //////////////////////////////////////////////////////
  const T& findMax() const throw (Oops)
  {
    Oops Empty("Oops : Tree is Empty!!");
    T Max;
    try
    {
      if (isEmpty())
        throw (Empty);
      Max = findMax(root);
    }
    return Max;
    }
  }
  const T& findMax(TreeNode* & t) const
  {
    if (t->left != NULL && t->right == NULL)
      return t.data;
    else if (t->right != NULL)
      return findMax(t->right);
  }
  //////////////////////////////////////////////////////
  const T& findMin() const throw (Oops)
  {
    Oops Empty("Oops : Tree is Empty!!");
    T Max;
    try
    {
      if (isEmpty())
        throw (Empty);
      Max = findMax(root);
    }
    return Max;
    }
  }
  const T& findMin(TreeNode* & t) const
  {
    if (t->left == NULL && t->right != NULL)
      return t->data;
    else if (t->left != NULL)
      return findMax(t->left);
  }
  //////////////////////////////////////////////////////
  int find(const T& x) const
  {
    return find(root, x);
  }
  int find(TreeNode* & t, const T& x) const
  {
    int Height = 0;
    if (t->left != NULL)
    {
      if (t->left->data > x)
      {
        Height += find(t->left, x);
        return Height;
      }
      if (t->left->data == x)
        return 1;
    }
    if (t->right != NULL)
    {
      if (t->right->data < x)
      {
        Height += find(t->right, x);
        return Height;
      }
      if (t->right->data == x)
        return 1;
    }