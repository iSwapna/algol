#include <iostream>
#include <vector>

using namespace std;
/*
 *  Is it possible to divide the array into two groups, 
 *  so that the sum of one group is a multiple of 10, 
 *  and the sum of the other group is odd. Every int must
 *  be in one group or the other.
 */
bool splitO10(vector<int> arr, int mult10 = 0,
	      int odd = 0, int idx = 0) {
  if(idx == arr.size())
    return (mult10 % 10 == 0 && odd % 2 == 1);
  if(splitO10(arr, mult10 + arr[idx], odd, idx + 1)) return true;
  if(splitO10(arr, mult10, odd + arr[idx], idx + 1)) return true;
  return false;
}

int main() {

  vector<vector<int>> arrList = {{5,5,5}, {5,5,6}, {5,5,6,1}};

  for(auto &arr: arrList) {
    cout << "Arr: " << endl;
    for(auto &x: arr)
      cout << x << " ";
    cout << endl;
    cout << "SplitOdd10 possible?: " << splitO10(arr) << endl;
  }


}
