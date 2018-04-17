#include <iostream>
#include <vector>
using namespace std;

struct Node {
  int val;
  Node* left;
  Node* right;

Node(int value = 0): val(value), left(nullptr), right(nullptr) {}

};
Node* insert(Node* root, int value) {
  if(root == nullptr) {
    root = new Node(value);
    return root;
  }
  if(value < root->val)
    root->left = insert(root->left, value);
  else
    root->right = insert(root->right, value);
  
  return root;
}
Node* createBST(const vector<int> arr) {
  if(arr.empty()) return nullptr;
  Node* root = nullptr;
  for(auto &value: arr)
    root = insert(root, value);
  return root;
}
void printTree(Node* root) {
  if(root == nullptr) return;

  printTree(root->left);
  cout << " " << root->val;
  printTree(root->right);

}
void printBST(Node* root) {
  printTree(root);
  cout << endl;

}
