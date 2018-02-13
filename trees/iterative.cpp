#include <iostream>
#include <stack>
#include <vector>

using namespace std;
struct Node {
  int val;
  Node* left;
  Node* right;
  // need to init pointers! pods, caught segfault!
  Node(int v):val(v), left(nullptr), right(nullptr){}
};

void printT(Node* head) {
  if(head == nullptr) {
    return;
  }
  printT(head->left);
  cout << " " << head->val;
  printT(head->right);
}
Node* insert(Node* head, int val) {
  if(head == nullptr) {
    head = new Node(val);
    return head;
  }
  if(val < head->val) {
    head->left = insert(head->left, val);
  } else if(val > head->val){
    head->right = insert(head->right, val);
  }
  return head;
}
Node* makeTree(vector<int> data) {
  if(data.empty()) return nullptr;
  Node* head = nullptr;
  for(auto &val: data)
    head = insert(head, val);
  return head;
}
void iterativeInOrder(Node* node) {
  if(node == nullptr) return;
  stack<Node*> st;
  auto curr = node;
  bool done = false;
  while(!done) {
    if(curr) {
      st.push(curr);
      curr = curr->left;
    } else if(st.empty()) done = true;
    else {
      curr = st.top();
      st.pop();
      cout << curr->val << " ";
      curr = curr->right;

    }
  }
}
void iterativePostOrder(Node* node) {
  if(node == nullptr) return;
  stack<Node*> in, out;
  in.push(node);
  while(!in.empty()) {
    auto curr = in.top();
    in.pop();
    out.push(curr);
    if(curr->left) in.push(curr->left);
    if(curr->right) in.push(curr->right);
  }
  while(!out.empty()) {
    cout << out.top()->val << " ";
    out.pop();
  }
}
void iterativePreOrder(Node* head) {
  if(head == nullptr) return;
  stack<Node*> st;
  st.push(head);
  while(!st.empty()) {
    auto curr = st.top();
    st.pop();
    cout << curr->val << " ";
    if(curr->right)
      st.push(curr->right);
    if(curr->left)
      st.push(curr->left);
  }
  cout << endl;
}
int main() {
  Node* head = makeTree(vector<int>{3, 6, 8, 2,11, 45, 23, 12, 3, 6, 9, 1});
  //cout << "printing tree in-order: ";
  //printT(head);
  cout << "Iterative Pre-order: ";
  iterativePreOrder(head);
  cout << endl << "Iterative In-order: ";
  iterativeInOrder(head);
  cout << endl << "Iterative Post-order: ";
  iterativePostOrder(head);

}
