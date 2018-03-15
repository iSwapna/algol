/*****
 * An O(N) algorithm to evaluate expression, expr:
 * where expr contains only integers, '+', '-' and spaces. 
 *
 *******/

#include <iostream>
using namespace std;
long long getNum(string expr, int& idx) {
  long long num = 0;
  while(expr[idx] >= '0' && expr[idx] <= '9')
    num = num * 10 + expr[idx++] - '0';
  return num;
}
bool isDigit(char ch) {
  return (ch >= '0' && ch <= '9');
}

long long doOp(long long result, char op, long long num) {
  if(op == '-')
    return result - num;
  else
    return result + num;
}
long long evalExpr(string expr) {
  long long result = 0;
  char op = '+'; int idx = 0;
  while(idx < expr.size()) {
    if(expr[idx] == '+') {
      op = '+'; idx++;
    } else if(expr[idx] == '-') {
      op = '-'; idx++;
    } else if(isDigit(expr[idx])) {
      int num = getNum(expr, idx);
      result = doOp(result, op, num);
    } else
      idx++;
  }
  return result;
}
int main() {

  string expr = "16 + 9 - 12";

  cout << evalExpr(expr) << endl;

}
