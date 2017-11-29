#include <iostream>
#include <vector>


using namespace std;
/*
 * Find smallest in cyclic list with duplicates
 */
int findSmallCyclic1(vector<int>& arr) {
  int lo = 0; int hi = arr.size() - 1;
  int res = INT_MAX;
  while(lo <= hi) {
    int mid = lo + ((hi - lo) >> 1);
    
    if(arr[mid] > arr[hi]) {
      lo = mid + 1;
    } else { // arr[mid] <= arr[hi]
      res = (res > arr[mid]) ? arr[mid] : res ;
      hi = mid - 1;
    }
  }
  return res;
}
/*
 * Find smallest(2) in cyclic list with duplicates
 */
int findSmallCyc2(vector<int>& arr) {
  int lo = 0; int hi = arr.size() - 1;

  while(lo < hi) {
    int mid = lo + ((hi - lo) >> 1);
    if(arr[mid] > arr[hi]) {
      lo = mid + 1;
    } else {
      hi = mid;
    }
  }
  return arr[lo];
}

int main() {
  vector<int> arr{9, 3, 4, 5, 6};
  cout << findSmallCyclic1(arr) << endl;
  cout << findSmallCyc2(arr) << endl;

}
