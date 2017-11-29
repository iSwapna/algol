/*
*  Chapter 11 of EPI
* Searching: Binary Search
*
* 11.1, 11.5, 11.9 
*/

#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;
using std::numeric_limits;

/*
 * Classic Binary Search: Assuming NO negative Indexing possible!
 * 
 */

int bSearch(int num, const vector<int>& arr) {

  int lo = 0; int hi = arr.size() - 1;

  while(lo < hi) {
    int mid = lo + ((hi - lo) >> 1); //(hi + lo)/2 <<-- INT overflow BEWARE!
    if(arr[mid] > num)
      hi = mid - 1;
    else if(arr[mid] < num)
      lo = mid + 1;
    else if(arr[mid] == num)
      return mid;
  }
  return -1;
}

/*
 *  11.1 Return index of first occurence of key 
 *  Time: O(logN) Space: O(1)
 */
int findFirst(int key, const vector<int>& arr) {

  int lo = 0; int hi = arr.size() - 1;
  int res = -1;
  while(hi >= lo) {
    // do not attempt to divide zero!!
    int mid = lo + ((hi -lo) >> 1); // bitshift is faster to div
    if(arr[mid] > key)
      hi = mid - 1;
    else if(arr[mid] < key)
      lo = mid + 1;
    else if(arr[mid] == key) {
      res = mid; hi = mid - 1;
    }
  }
  return res;
}

/*
 * 11.5 Search for smallest in a cyclically sorted array /
 * sorted and shifted array with NO DUPLICATES
 * If duplicates are present, Time: O(N) is the worst case 
 */

int findSmallestInShifted(const vector<int>& arr) {
  int lo = 0; int hi = arr.size() - 1;
  while(hi > lo) {
    int mid = lo + ((hi - lo) >> 1);
    if(arr[mid] > arr[hi]) {
      lo = mid + 1;
    } else {
      hi = mid;
    }
  }
  return lo;
}

/*
 * Helper for 11.9
 */

int compare(double lo, double hi) {
  // use normalized diff instead of absolute
  double diff = (lo - hi)/hi;
  return diff > -numeric_limits<double>::epsilon()
    ? -1
    : diff > numeric_limits<double>::epsilon();



}
/*
 * 11.9 Finds the sqrt of a floating point number
 */

double sqrt(double x) {

  double lo, hi;
  if(compare(x, 1.0) < 0) {
    lo = x; hi = 1.0;
  }else {
    lo = 1.0; hi = x;
  }
  while(compare(lo, hi) == -1) {
    double root = lo + 0.5 * (hi - lo);
    int res = compare(root * root, x);
    if(res == 0)
      return root;
    else if(res == -1) {
      lo = root; 
    } else {
      hi = root;
    }
  }
  return lo;
}
