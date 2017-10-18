/***

    Chapter 8 of EPI

***/


#include <iostream>
#include <stack>

using namespace std;

template <typename T>
class Stack {

public:
  bool empty() const { return s_.empty(); }
  
  const T& max() const {
    if(!empty()) {
      return s_.top().second;
    }
    throw length_error("Empty stack");
  }
  
  T pop() {
    if(empty()) {
      throw length_error("Empty stack");
    }
    T ret = s_.top().first;
    s_.pop();
    return ret;
  }

  void push(const T& x) {
    
    s_.emplace(x, std::max(x, empty() ? x : s_.top().second));
  }
      
  private:
  stack <std::pair<T, T>> s_;
      
};


#include <vector>
int main() {

    Stack<int> sk;
    sk.push(10);
    cout << sk.max() << endl;
    sk.push(9);
    sk.push(15);
    sk.push(3);
    cout << sk.max() << endl;
    sk.pop(); sk.pop();
    cout << sk.max() << endl;
    

}
