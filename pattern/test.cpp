#include <iostream>

#include "palindrome.hpp"

int main() {
  vector<string> res = allP("abb");

  for(auto &s: res) {
    cout << " " << s ;
  }
  cout << endl;

}
