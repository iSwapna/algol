#include <iostream>
#include <vector>

using namespace std;
/*
 * Check if it's possible to use nums in array
 * to sum to target value, while using all 6's
 *
 * Subset problem, add check for 6, for non-inclusion case.
 * so elegant!!!
 */
bool count(const vector<int>& arr, int sum, int idx = 0) {

  if(idx == arr.size()) return sum == 0;
  if(count(arr, sum - arr[idx], idx + 1)) return true;
  if(arr[idx] != 6 && count(arr, sum, idx + 1)) return true;
  return false;
}

int main() {

  vector<int> arr = {5, 6, 2};
  vector<int> sums = {8, 9 ,7};
  
  for(auto &y: arr)
    cout << y << " ";
  cout << endl;
	  
  for(auto &x: sums){
    cout << "sum: " << x << endl;
    cout << count(arr, x) << endl;
  }

}
