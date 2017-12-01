#include <iostream>
#include <vector>

using namespace std;

/*
 * Tests If Is it possible to Split all array elements
 *            - into two sets with equal sum
 */
bool split(vector<int> arr, int lt = 0,
	   int rt = 0, int idx = 0) {

  if(idx == arr.size()) return rt == lt;
  if(split(arr, lt + arr[idx], rt, idx + 1)) return true;
  if(split(arr, lt, rt + arr[idx], idx + 1)) return true;
  return false;
}

int main() {

  vector<vector<int>> arr = {{2,2}, {2,3}, {2,3,5}};

  for(auto &ar: arr) {
    cout << "Arr: " << endl;
    for(auto &x: ar)
      cout << x << " ";
    cout << endl;
    cout << "split: " << split(ar) << endl;
  }
}
