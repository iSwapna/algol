#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <set>
using namespace std;

vector<bool> visited(6, false);
struct node {
  int v;
  set<int> ns;
  node(int vx): v(vx) {}
  void addEdge(int to) {
    ns.insert(to);
  }

};

vector<node> G(6, 0);





void vecTests() {
  vector<int> vec(5, 5);
  try {
    cout  << vec.at(7) << endl;
  } catch (const out_of_range& e) {
    cout << e.what() << endl;
  }
  cout << "vector size: " << vec.size() << endl;
  vec.pop_back();
  cout << "sz after pop_back: " << vec.size() << endl;
  vec.resize(20);
  vec.clear();
  cout << "after resize: " << vec.size() << endl;
  cout << "Test: " << vec.back() << endl;
  
}
void pSet(set<int>& s) {
  for(auto &u: s)
    cout << u << ",";
  cout << endl;
}
void setTests() {
  set<int> a, b, un, in, di;
  a.insert(3); a.insert(5); a.insert(-2);
  b.insert(4); b.insert(-2); b.insert(9);
  set_union(a.begin(), a.end(), b.begin(), b.end(),
		 insert_iterator<set<int>>(un, un.begin()));
  cout << "a: " << endl;
  pSet(a);
  cout << "b: " << endl;
  pSet(b);
  cout << "union: " << endl;
  pSet(un);
}
int main() {
  //  vecTests();
  setTests();
}
