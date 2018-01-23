//INCOMPLETE

#include <iostream>
// brute force O(N^3)
// think of invariants of the expected res
// eg: res here, start and end elements are in the set and distinct
//
//

#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

string findMinStr(const string in,
		  const vector<char>& chkSet) {

  unordered_map<char, int> count;
  unordered_set<char> grp(chkSet.begin(), chkSet.end());
  int len = in.size();
  int currCount = 0;
  //construct hash
  for(int i = 0; i < len; ++i) {
    //found a char in set
    if(grp.find(in[i]) != grp.end()) {
      count[in[i]]++;
      if(count[in[i]] == 1)
	currCount++;
    }
  }
  cout << currCount << endl;
  if(currCount < grp.size()) return string{};
  int start = -1; int end = 0;
  for(int i = 0; i < len; ++i) {


  }
  //  return in.substr(start, end - start);
  return in;
}
int main() {

  string in = "abcbadadb";
  vector<char> chk = {'b', 'd'};

  cout << findMinStr(in, chk) << endl;

}
