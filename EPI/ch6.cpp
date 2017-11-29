/*
*  Chapter 6 of EPI
*  Arrays and strings
*/

#include <iostream>

void dutchFlagPartition(vector<int>* A, int pivotIndex) {
  int pivot = (*A)[pivotIndex];
  /*
   *Keep the following invariants during partitioning:
   *bottom group: (*A)[0 : smaller - 1]
   *middle group: (*A)[smaller : equal - 1]
   *unclassified group: (*A)[equal : larger]
   *top group: (*A)[larger + 1 : A->size() - 1]
   */
  int smaller = 0, equal = 0, larger = A->size() - 1;
  // When there is any unclassified element.
  while(equal <= larger) {
    // (*A)[equal] is the incoming unclassified element
    if((*A)[equal] < pivot) {
      swap((*A)[smaller++], (*A)[equal++]);
    } else if((*A)[equal] == pivot) {
      ++equal;
    } else { // (*A)[equal] > pivot
      swap((*A)[equal], (*A)[larger--]);
    }
  }
}

