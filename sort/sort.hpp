#include <iostream>
#include <vector>

#include "utils.hpp"

namespace astd {

  /*
   * Insertion sort -maintains invariant, array to left of j is sorted
   * Used when array is almost soretd for O(N) time performance
   * Time: O(N^2), Space:O(1), stable
   */  
  template <typename _Comparable>
    void insertion(std::vector<_Comparable>& arr) {

    for(int j = 1; j < arr.size(); j++) {
      int i = j; _Comparable item = arr[j];
      while(i > 0 && arr[i-1] > item) {
	i--;
	arr[i + 1] = arr[i];
      }
      arr[i] = item;
    }
    return;
  }

  /*
   * Bubble sort -maintains invariant, on every iteration next largest
   * element is moved to correct index on right end
   * Used when array size is less than 10 or so.
   * Time: O(N^2), Space:O(1), un-stable
   */  
  template <typename _Comparable>
    void bubble(std::vector<_Comparable>& arr) {

    for(int i = 1; i < arr.size(); i++) {
      int j = 0; bool didSwap = false;
      while(j < arr.size() - i) {
	if(arr[j] > arr[j + 1]) {
	  std::swap(arr[j], arr[j+1]);
	  didSwap = true;
	}
	j++;
      }
      if(didSwap == false) break;
    }
    return;
  }
  /*
   * mSort helper
   */
  template <typename _Comparable>
           void combine(std::vector<_Comparable>& arr,
			int start, int mid, int end) {

    std::vector<_Comparable>
      lt(arr.begin() + start, arr.begin() + mid+1);
    std::vector<_Comparable>
      rt(arr.begin() + mid + 1, arr.begin() + end+1);
    int curr = start; int lo = 0, hi = 0;

    while(lo < lt.size() && hi < rt.size()) {
      if(lt[lo] < rt[hi] ) 
	arr[curr++] = lt[lo++];
      else arr[curr++] = rt[hi++];
    }
    while(lo < lt.size()) arr[curr++] = lt[lo++];
    while(hi < rt.size()) arr[curr++] = rt[hi++];
  }
  
  /*
   * Classic mergesort - divide and conquer
   * Time: O(NlogN), Space: O(N) for array, stable
   */
  template <typename _Comparable>
           void mSort(std::vector<_Comparable>& arr,
		      int start = 0, int end = INT_MAX) {
    if(end > arr.size())
      end = arr.size() - 1;
    if(start >= end) return;
    int mid = (start + end)/2;

    mSort(arr, start, mid);
    mSort(arr, mid + 1, end);
    combine(arr, start, mid, end);
  }

  /*
   * Quick sort with Djikstra's 3-way partition for equal keys. 
   * In applications with high incidence of duplicate keys
   *  time taken is O(N)
   * Time: NlogN, Space:O(1), un-stable
   */  
  template <typename _Comparable>
            void qSort(std::vector<_Comparable>& arr,
		       int start = 0, int end = INT_MAX) {

    // {1 1 1 3 5 6} fails without bounds check
    // http://algs4.cs.princeton.edu/lectures/23Quicksort.pdf
    // does not use bounds check... 
    if(end < 0 || start >= arr.size()) return;
    if(end > arr.size())
      end = arr.size() - 1;

    if(start >= end) return;

    Random r;
    int idx = r.drawNum(start, end);
    int pivot = arr[idx];
    int i = start; int lt = start; int gt = end;
    while(i <= gt) {
      if(arr[i] < pivot) {
	std::swap(arr[i], arr[lt]);
	i++; lt++;
      } else if (arr[i] > pivot) {
	std::swap(arr[i], arr[gt]);
	gt--;
      } else {
	i++;
      }
    }
    qSort(arr, start, lt - 1);
    qSort(arr, gt + 1, end);
  }

}


