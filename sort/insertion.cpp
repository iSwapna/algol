#include <iostream>
#include <vector>

using namespace std;
/*
  Insertion sort: good for almost sorted or streaming input
  Is stable, but O(N*N), linear when only few are out of place

 */
void iSort(vector<int>& arr) {
  if(arr.size() <= 1) return;

  for(int i = 1; i < arr.size(); ++i) {
    int j = i;
    while( j >= 0 && arr[j] < arr[j-1]) {
    	swap(arr[j], arr[j-1]);
	j--;
    }
  }
}

void pprint(vector<int>& arr) {
  for(auto &item: arr)
    cout << item << " ";
  cout << endl;
}
int main() {

  vector<int> arr = {7, 0, 3, 4, 9, 3};
  pprint(arr);
  iSort(arr);
  cout << "after sort: " << endl;
  pprint(arr);


}

