#include <iostream>
#include <vector>

using namespace std;
/*
 * Most recursion / backtracking problems are
 * either subsets or permutaions problem
 * First correctly identify, then tackle current item,
 * Let recursion take care of rest! add base case and...
 * You Are Done!!
 * This is a subset problem.
 */
bool poss(vector<int> arr, int sum, int idx = 0) {

  if(idx == arr.size()) return (sum == 0);
  if(poss(arr, sum - arr[idx], idx + 1))
    return true;
  if(poss(arr, sum, idx + 1))
    return true;
  return false;
}

/*
 * This is the wrong way to approach!!
 */
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
    cout << "Is Possible: " << poss(ch, sum) << endl;
  }
  
  return 0;
}


