#include <iostream>
#include <vector>
#include <stack>
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
https://github.com/swapnai/algol/blob/master/trees/printPaths.cpp  if(arr.empty()) return nullptr;
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
void printTreeWithLevel(Node* root, int level = 1, int parent = 0) {
  if(root == nullptr) return;
  printTreeWithLevel(root->left, level + 1, root->val);
  cout << " level::" << level << "::parent::";
  cout << parent << "::value::" << root->val << endl;
  printTreeWithLevel(root->right, level + 1, root->val);
}
// NEED TO B FIXED!!! SHOULD BE LEVEL ORDER
vector<int> serialize(Node* root) {
  vector<int> data;
  stack<Node*> st;
  Node* curr = root;
  bool done = false;
  while(!done) {
    if(curr) {
      st.push(curr); curr = curr->left; 
    } else if(st.empty())
      done = true;
    else {
      curr = st.top(); st.pop();
      data.push_back(curr->val);
      curr = curr->right;
    }
  }
  return data;
}
void printTreeAsTree(Node* root) {
  vector<int> data = serialize(root);
  int i = 0, max = 1;
  for(auto &elem: data) {
    if(max == i) {
      cout << endl;
      max *= 2; i = 0;
    }
    cout << " " << elem;
  }
  
}
void printBST(Node* root) {
  printTreeWithLevel(root);
  cout << endl;

}
