#include <iostream>

using std::shared_ptr;

struct Node {

  int data;
  shared_ptr<Node> left;
  shared_ptr<Node> right;
  shared_ptr<Node> parent;
  Node(int data_): data(data_),
		   left(nullptr),
		   right(nullptr),
		   parent(nullptr) {
    std::cout << "In Constructor: " << data << std::endl;
  }
  ~Node() {
    std::cout << "In Destructor: " << data << std::endl;
  }
};

void makeTree() {
  shared_ptr<Node> ptr(new Node(5));
  shared_ptr<Node> lt(new Node(3));
  shared_ptr<Node> rt(new Node(7));
  ptr->left = lt;
  std::cout << "lt count: " << lt.use_count() << std::endl;
  std::cout << "rt count: " << rt.use_count() << std::endl;
  std::cout << "parent count: " << ptr.use_count() << std::endl;
  //ptr->right = rt;
   rt->parent = ptr;
  std::cout << "lt count: " << lt.use_count() << std::endl;
  std::cout << "rt count: " << rt.use_count() << std::endl;
  std::cout << "parent count: " << ptr.use_count() << std::endl;
}

int main() {

  makeTree();
}

  
