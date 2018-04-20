/*
 * Merge 2 trees into a balaned Tree
 *
 */
#include "bst.h"

vector<int> merge(vector<int>& v1, vector<int>& v2) {
  vector<int> merged;
  int s1 = 0; int s2 = 0;
  while(s1 < v1.size() && s2 < v2.size()) {
    if(v1[s1] < v2[s2])
      merged.push_back(v1[s1++]);
    else
      merged.push_back(v2[s2++]);
  }
  while(s1 < v1.size())
    merged.push_back(v1[s1++]);
  while(s2 < v2.size())
    merged.push_back(v2[s2++]);
  
  return merged;
}
Node* makeNewTree(Node* node, vector<int>& merged) {

  int mid = merged.size()/2;
    for(int i = mid; i < merged.size(); ++i)
        node = insert(node, merged[i]);
    for(int i = mid -1; i >= 0; --i)
        node = insert(node, merged[i]);
    
    return node;
}


Node* makeBalancedTree(Node* node, vector<int>& merged, int hi, int lo = 0) {
  if(hi - lo < 0) return node;
  int mid = lo + ((hi - lo) >> 1);
  node = new Node(merged[mid]);
  node->left = makeBalancedTree(node->left, merged, mid - 1, lo);
  node->right = makeBalancedTree(node->right, merged, hi, mid + 1);
  return node;
}
void orderTree(Node* node, vector<int>& arr) {
    if(node == nullptr) return;
    orderTree(node->left, arr);
    arr.push_back(node->val);
    orderTree(node->right, arr);
}
Node* mergeTrees(Node* n1, Node* n2) {
    vector<int> v1, v2;
    orderTree(n1, v1);
    orderTree(n2, v2);
    Node* node = nullptr;
    vector<int> merged = merge(v1, v2);
    return makeBalancedTree(node, merged, merged.size());
}

int main() {
  vector<int> arr1 = { 7, 2, 4};
  vector<int> arr2 = {5, 6, 1, 3};
  Node* n1 = createBST(arr1);
  Node* n2 = createBST(arr2);
  Node* newTree = mergeTrees(n1, n2);
  printBST(newTree);

}
