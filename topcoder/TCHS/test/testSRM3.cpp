#include <iostream>
#include "../src/SRM3.cpp"
using namespace std;

int main() {
  vector<string> arr = {"table", "chair", "table", "table", "lamp", "door", "lamp", "table", "chair"};
  arr = {"A"};
  BestSeller b;
  cout << "Best: " << b.findBestSeller(arr) << endl;
  int a;
  int & ref = a;
  cout << &ref << ":" << &a << endl;
}
