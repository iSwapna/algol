/*****
 *
 * Implements the Knuth-Morris-Pratt algorithm
 * O(N)
 *
 ******/

#include <iostream>
#include <vector>
using namespace std;
void buildPrefix(const string p, vector<int>& prefix) {
  prefix[0] = 0; prefix[1] = 0;
  int i = 0; int j = 2;
  for(;j < prefix.size(); ++j) {
    i = prefix[j-1];
    while(1) {
      //1. can expand
      if(p[i] == p[j-1]) {
	prefix[j] = i + 1;
	break;
	//2. cannot expand even empty string
      } else if(i == 0) {
	prefix[j] = 0;
	break;
      }
      // 3. find next best partial match
      i = prefix[i];
    }
  }
}

int kmp(const string p, const string t,
	const vector<int>& prefix) {
  int j = 0; int i = 0;
  for(;;) {
    if(i == t.size()) break;
    //1. expand current match
    if(p[j] == t[i]) {
      j++; i++;
      if(j == p.size()) return (i - p.size());
      //2. no match even at start of string
    } else if(j == 0)
      i++;
    //3. find next best partial match
    else
      j = prefix[j];
  }
  return -1;
}
void pprint(const vector<int>& prefix) {
  for(auto &i: prefix)
    cout << i << ",";
  cout << endl;
}

int main() {
  string t = "abadababcababc";
  string p = "abab";
  vector<int> prefix(p.size(), 0);
  buildPrefix(p, prefix);
  pprint(prefix);
  cout << t.substr(kmp(p, t, prefix), p.size()) << endl;
}
