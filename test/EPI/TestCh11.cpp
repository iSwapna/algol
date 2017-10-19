#include "../utils.hpp"
#include "../../EPI/ch11.cpp"

using std::cout;
using std::endl;
int main() {

  cout << "running EPI ch11 test: " << endl;

  vector<int> arr = astd::getArrSorted(10);
  //  vector<int> arr{0, 3, 3, 3, 4, 5, 5, 6, 9, 9}; //test for key = 0;
  astd::print(arr);
  int key = astd::randNum(50);
  cout << "bSearch for: " << key << ": " << bSearch(key, arr) << endl;
  key = astd::randNum(10);
  //  arr = {0, 2, 4, 5, 6, 7, 7, 8, 9, 10}; key = 0, for >= in while
  astd::print(arr);
  cout << "findFirst for: " << key << ": " << findFirst(key, arr) << endl;
  arr = astd::getUniquesArr(10);
  std::sort(arr.begin(), arr.end());
  std::rotate(arr.begin(), arr.begin() + astd::randNum(10), arr.end());
  astd::print(arr);
  int idx = findSmallestInShifted(arr);
  cout << "findSmallestInShifted: " << idx << " val: " << arr[idx] << endl;

}
