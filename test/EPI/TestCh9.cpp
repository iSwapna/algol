#include "../utils.hpp"
#include "../../EPI/ch9.cpp"


int main() {

  std::cout << "running EPI ch9 test: " << std::endl;
  std::vector<uint> arr = astd::getArr(7, 6);
  astd::print(arr);
  std::unique_ptr<BinaryTree<int>> bt;
  for(auto &x: arr)
    unique_ptr<BinaryTree<int>> head = bt->insert(x);
  
  std::cout << "Balanced? :"  << isBalancedTree(bt) << std::endl;
  

}
