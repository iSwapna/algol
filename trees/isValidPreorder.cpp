#include <iostream>
#include <stack>

using namespace std;
bool isDigit(char ch) {
  return ch >= '0' && ch <= '9';


}
bool isValid(string str) {
  if(str.size() == 0)
    return false;
  stack<char> stk;
  char prev = '*';
  for(auto &ch: str) {
    if(ch == ',') continue;
    if(isDigit(prev) && isDigit(ch)) continue;
    prev = ch;
    while(ch == '#' && !stk.empty() && stk.top() == '#') {
      stk.pop();
      //we should have a parent node for these nulls
      if(stk.empty())
	return false;
      //pop the non-null parent
      stk.pop();
    }
    //push non-null node to stack
    stk.push(ch);
  }
  cout << stk.size() << endl;
  //we should only have an empty stack, unless we have a null root!
  return (stk.size() == 1 && stk.top() == '#');
}

int main() {


  cout << isValid("9,3,4,#,#,1,#,#,2,#,6,#,#") << endl;
  cout << isValid("9,#,92,#,#") << endl;

}
