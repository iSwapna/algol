#include <iostream>
#include <unordered_map>
using namespace std;

// Find the minimum window if str containing all chars in chk
string minWindow(const string& chk, const string& str) {
  unordered_map<char, int> need;
  for(auto &ch: chk)
    need[ch]++;
  int missing = chk.size();
  int j = 0; int start = 0; int end = -1;
  for(int i = 0; i < str.size(); ++i) {
    char ch = str[i];
    if(need[ch] > 0)
      missing--;
    //negative vales for all irrelevant chars in str!!
    //BRILLIANT insight from stefanpochman @leetcode.
    need[ch]--;
    if(missing == 0) {
      while(j < i && need[str[j]] < 0) {
	need[str[j]]++;
	j++;
      }
      if(end == -1 || i-j < end-start) {
	start = j;
	end = i;
      }
    }
  }
  return str.substr(start, end-start+1);
}
int main() {

  string matchSet = "a";
  string findStr = "ayzabobecodxbanc";
  findStr = "abcd";

  cout << minWindow(matchSet, findStr) << endl;


}
