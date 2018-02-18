#include <iostream>
#include <stack>
using namespace std;
/*
  This expression evaluator has 3 caveats:
  1. No character other than digits, operators in [-, +, *, /]
     and ['(', ')'] are allowed in the expression of integer values.
  2. Result (including intermediate) can be floats
  3. Operator precedence does NOT apply!
     This is easily fixed with appropriate parenthesis
 */
double getNum(string expr, int& i) {
  double num = 0;
  while(expr[i] >= '0') {
    num += 10*num + expr[i++] - '0';
  }
  return num;
}

double calc(double result, char op, double num) {
  if(op == '-')
    return result-num;
  else if(op == '+')
    return result+num;
  else if(op == '*')
    return result*num;
  else {
    return result/num;
  }
}

bool isOp(char ch) {
  return (ch == '-' || ch == '+' ||
	  ch == '*' || ch == '/');
}

double eval(const string& expr, stack<char>& op, int& i) {
  double result = 0;
  bool initDone = false;
  while(i < expr.length()) {
    if(expr[i] == '(') {
      int prev = i-1;
      double num = eval(expr, op, ++i);
      initDone = true;
      if((prev >= 0 && expr[prev] != '(') && !op.empty()) {
	result = calc(result, op.top(), num);
	op.pop();
      } else {
	result = num;
      }
    } else if(expr[i] == ')') {
      ++i;
      return result;
    } else if(isOp(expr[i])) {
      op.push(expr[i++]);
    } else {
      double num = getNum(expr, i);
      if(!initDone) {
	result = num;
	initDone = true;
      } else {
	result = calc(result, op.top(), num);
	op.pop();
      }
    }
  }
  return result;
}

int main() {
  string expr = "3-((2+9)*4)+2";
  expr = "(3+4)*(5-2)/2";
  expr = "(4+4)*((5-2)/2)";
  expr = "((4+4)*((5-2)/2))";
  expr = "(4+(4*5)-2)/2";
  stack<char> op; int i = 0;
  cout << eval(expr, op, i) << endl;
}
