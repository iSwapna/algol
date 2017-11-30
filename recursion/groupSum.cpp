#include <iostream>
#include <vector>

using namespace std;

bool findGrp(vector<int> ch,
	     vector<int>& grp,
	     int sum, int curr = 0) {

  if( curr == sum) return true;

  for(int i = 0; i < ch.size(); ++i) {
    if(curr + ch[i] <= sum) {
      curr += ch[i];
      grp.emplace_back(ch[i]);
      if(findGrp(vector<int>(ch.begin() + i + 1, ch.end()),
		 grp, sum, curr)) return true;
      curr -= ch[i];
      grp.pop_back();
    }
  }
  return false;
}

void pprint(vector<int>& arr) {
  for(auto &c: arr)
    cout << c << " ";
  cout << endl;
}

int main() {

  vector<int> ch = {2, 4, 8};
  vector<int> targets ={ 10, 14, 9};
  cout << "Choices: " << endl;
  pprint(ch);
  for(auto &sum: targets) {
  cout << "Target Sum: " << sum << endl;
  vector<int> res;
  if(findGrp(ch, res, sum)) {
    cout << "Res: "<< endl;
    pprint(res);
  } else
    cout << "Not possible!" << endl;
  }
    
  return 0;
}


