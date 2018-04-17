#include <iostream>
#include <queue>
#include "bst.h"

using namespace std;
void getInOrder(Node* root, queue<int>& qu) {
  if(root == nullptr) return;
  getInOrder(root->left, qu);
  qu.push(root->val);
  getInOrder(root->right, qu);
}
bool isBST(Node* root) {
  if(root == nullptr) return true;
  queue<int> qu;
  getInOrder(root, qu);
  int min = qu.front();
  qu.pop();
  while(!qu.empty()) {
    int nxt = qu.front();
    if(nxt <= min) return false;
    min = nxt;
    qu.pop();
  }
  return true;
}
int main() {
  vector<int> arr = { 3, 5, 2, 4, 1, -3, 9};
  Node* root = createBST(arr);
  //printBST(root);
  cout << isBST(root) << endl;
}
