#include <memory>
/***

    BinaryTree Class
    Unbalanced binary tree supports insert, delete by value, empty and height
    No duplicates allowed!
***/

template <typename T>
class BinaryTree {
public:
  BinaryTree(): data(0),
		       left(nullptr),
		       right(nullptr),
		       head(nullptr) {}
  
  std::unique_ptr<BinaryTree<T>> insert(T data,
			std::unique_ptr<BinaryTree<T>> curr = nullptr) {
    if(!curr) {
      //      std::unique_ptr<BinaryTree<T>> tmp =
	head = std::unique_ptr<BinaryTree<T>>(new BinaryTree<T> ());
      head->data = data;
      return head;
    }

    if(data < curr->data)
      curr->left = insert(data, curr->left);
    else if(data > curr->data)
      curr->right = insert(data, curr->right);
    else return curr;
  }
  
private:
  T data;
  std::unique_ptr<BinaryTree<T>> left, right;
  std::shared_ptr<BinaryTree<T>> head;

};


