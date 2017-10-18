/***

    Chapter 9 of EPI

***/

#include "BinaryTree.hpp"

template <typename T>
bool isBalancedTree(const unique_ptr<BinaryTree<T>>& node) {
  return getHeight(node) != -2;
}
template <typename T>
int getHeight(const unique_ptr<BinaryTree<T>>& node) {
  if(!node) return -1;

  int leftHt = getHeight(node->left);
  if(leftHt == -2) return -2;
  int rightHt = getHeight(node->right);
  if(rightHt == -2) return -2;

  if(abs(leftHt - rightHt) > 1) return -2;
  return max(leftHt, rightHt) + 1;

}


