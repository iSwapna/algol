/*
 * print all paths in a tree
 *
 */
#include <queue>
#include "bst.h"

void printPaths(vector<vector<int>>& paths) {
  for(auto &arr: paths) {
    for(auto &elem: arr) {
      cout << " " << elem;
    }
    cout << endl;
  }
}
void getPaths(Node* root, vector<vector<int>>& paths,
	      vector<int> curr) {
  if(root == nullptr)
    return;
  if(root->right == nullptr && root->left == nullptr) {
    curr.push_back(root->val);
    paths.push_back(curr);
    return;
  }
  curr.push_back(root->val);
  getPaths(root->left, paths, curr);
  getPaths(root->right, paths, curr);
  return;
}
void getPaths(Node* root, vector<vector<int>>& paths) {
  vector<int> curr;
  getPaths(root, paths, curr);
}
	      
int main() {
  vector<int> arr = { 3, 5, 2, 4, 1, -3, 9};
  Node* root = createBST(arr);
  printBST(root);
  vector<vector<int>> paths;
  getPaths(root, paths);
  printPaths(paths);
}
