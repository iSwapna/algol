#include <iostream>
#include <stack>
#include <vector>
using namespace std;
// what's the deal with '-' ??
bool isOp(char ch) {
  cout << ch << endl;
  return (ch == '$' || ch == '+' ||
	  ch == '*' || ch == '/');
}
char getOp(string str) {
  return str[0];
}
double calc(double num1, char op, double num2) {
  if(op == '$')
    return num1 - num2;
  else if(op == '+')
    return num1 + num2;
  else if(op == '*')
    return num1 * num2;
  else
    return num1/num2;

}
double eval(vector<string>& rpn) {
  stack<string> stk;
  stk.push("0");
  double result = 0;
  for(int i = 0; i < rpn.size(); ++i) {
    cout << "i: " << i << endl;
    string str = rpn[i];
    if(isOp(str[0])) {
      char op = getOp(rpn[i]);
      double num1 = stof(stk.top());
      stk.pop();
      double num2 = stof(stk.top());
      stk.pop();
      result = calc(num1, op, num2);
      cout << "num1: " << num1 << " :num2: " << num2 << " : res: " << result << endl;
      stk.push(to_string(result));
      cout << "into stk 1: " << to_string(result) << endl;
    } else {
      stk.push(rpn[i]);
      cout << "into stk: " << rpn[i] << endl;
    }
  }
  return result;
}
int main() {
vector<string> RPN = {"15","7","1","1","+", "$","/","3",
	      "*","2","1","1","+","+","$"};
  cout << eval(RPN) << endl;

}
