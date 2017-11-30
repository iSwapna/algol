#include <iostream>
#include <vector>
using namespace std;

/*
 * Find idx of min element in rotated and 
 * sorted array with duplicates
 * Modifies the quntessential binary search algorithm
 * Algorithm: If mid is higher than hi, 
 *                search upper half,
 *            Else, 
 *                save (smaller or equal to last saved) mid,
 *                serach lower half.
 */
int findMin(const vector<int>& arr) {

  int lo = 0; int hi = arr.size() - 1; int res = INT_MAX;
  int idx = INT_MAX;
  while(lo <= hi) {
    int mid = lo + ((hi - lo) >> 1);
    if(arr[mid] > arr[hi]) {
      lo = mid + 1;
    }else {
      if(res >= arr[mid]) {
	res = arr[mid];
	idx = mid;
      }
      hi = mid - 1;
    }
  }
  return idx == INT_MAX ? -1 : idx;
}



int main() {

  vector<vector<int>> arrList = {{8, 8, 8}, {6, 7, 9, 9, 3},
				 {11, 13, 3, 5, 5}, {1}, {}};
  for(auto &arr: arrList) {
    cout << "Arr: ";
    for(auto &x: arr)
      cout << x << " ";
    cout << endl;
    cout << "Idx: " << findMin(arr) << endl;
  }
}
