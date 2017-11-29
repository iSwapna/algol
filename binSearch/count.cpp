#include <iostream>
#include <vector>

/*
 * c screen - 11/20/2017
 * find the count of an element in a sorted array.
 */
using namespace std;

int findLo(int* arr, int len, int val) {
  int ret = -1; int lo = 0; int hi = len - 1;
  while(lo <= hi) {
    int mid = lo + ((hi - lo) >> 1);
    if(arr[mid] == val) {
      ret = mid;
      hi = mid - 1;
    } else if(arr[mid] < val) {
      lo = mid + 1;
    } else {
      hi = mid - 1;
    }
  }
  return ret;
}
int findHi(int* arr, int len, int lo, int val) {
  int ret = -1;	int hi = len - 1;
  while(lo <= hi) {
    int	mid = lo + ((hi - lo) >> 1);
    if(arr[mid] == val) {
      ret = mid;
      lo = mid + 1;
    } else if(arr[mid] < val) {
      lo = mid + 1;
    } else {
      hi = mid - 1;
    }
  }
  return ret;
}


int count(int* arr, int len, int val) {

  int lo = findLo(arr, val, len);
  int hi = findHi(arr, len, lo, val);
  cout << "hi: " << hi << " lo: " << lo << endl;
  return hi - lo + 1;
}


int main() {

  int arr[] = {1, 5, 5, 5, 5, 8};

  cout << count(arr, 5, 5) << endl;


}
