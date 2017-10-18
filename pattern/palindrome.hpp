#include <iostream>
#include <vector>

using namespace std;

bool isPalindrome(string &str, int i , int j) {
  int a, b;

  if(i == j) return true;
  for(a = i, b = j; a < b; ++a, --b) {
    if(str[a] != str[b]) break;
  }
  if(a >= b) return true;
  else return false;
}
/*
 * Total no of palindromes in string, brute force
 * Time: O(N^3) Space: O(1)
 */
vector<string> allP(string str) {
  vector<string> res;
  for(int i = 0; i < str.size(); ++i){
    for(int j = i; j <= str.size(); ++j) {

      if(isPalindrome(str, i, j))
	res.push_back(str.substr(i, j));
    }
  }
  return res;
}

