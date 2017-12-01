#include <iostream>
#include <vector>

using namespace std;

/*
 * Is it possible to choose a group of some array elements
 * such that the group sums to the given target with this 
 * additional constraint: If a value in the array is chosen to
 * be in the group, the value immediately following it in the
 * array must not be chosen. 
 */

bool grpNoAdj(vector<int> arr, int sum,
	      int idx = 0, bool use = true) {

  if(idx == arr.size()) return sum == 0;
  if(use)
    if(grpNoAdj(arr, sum - arr[idx], idx + 1, !use)) return true;
  if(idx == 0 || !use)
    if(grpNoAdj(arr, sum, idx + 1, !use)) return true;
  
  return false;
}

int main() {

  vector<int> arr = {2, 5, 10, 4};
  vector<int> sums = {12, 14, 7};

  for(auto &x: arr)
    cout << x << " ";
  cout << endl;

  for(auto &sum: sums)
    cout << "Possible? : " << grpNoAdj(arr, sum) << endl;

}
