#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

string placeDups(string str, int d) {
  map<char, int> count;
  for(auto &ch: str)
    count[ch]++;
  vector<pair<int, char>> revC;
  for(auto &cnt: count)
    revC.push_back(make_pair(cnt.second, cnt.first));
  sort(revC.rbegin(), revC.rend());
  string result(str.size(), '\0');
  int offset = 0;
  for(int i = 0; i < revC.size();  ++i) {
    while(result[offset] != '\0')
      offset++;
    int reps = revC[i].first; char ch = revC[i].second;
    for(int j = 0; j < reps;  ++j) {
      if(offset+j*d >= str.length()) return "##";
      result[offset+j*d] = ch;
    }
  }
  return result;
}

int main() {
  string input = "aaccddeee";
  cout << placeDups(input, 2) << endl;
}
