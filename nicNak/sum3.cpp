#include <iostream>
#include <vector>

using namespace std;

vector<string> findSets(int* arr, int len) {
  sort(arr, arr + len);
  cout << "input:";
  for(int i = 0; i < len; ++i)
    cout << arr[i] << " ";
  cout << endl;
  vector<string> res;

  for(int i = 0; i < len; ++i) {
    if(arr[i] > 0) break;
    if(i > 0 && arr[i] == arr[i-1]) continue;
    int j = i + 1; int k = len - 1;
    int target = -arr[i];
    while(j < k) {
      int sum = arr[j] + arr[k];
      cout << "vals:" << arr[i] << ":" << arr[j] << ":" << arr[k] << endl;
      cout << "idx:" << i << ":" << j << ":" << k << endl;
      if(sum == target) {
	res.push_back(to_string(-target) + "," +
		      to_string(arr[j]) + "," +
		      to_string(arr[k]));
	cout << "skipping dups.." << endl;

	//skip all dups before incrementing!!
	while(j < k && arr[j+1] == arr[j]) j++;
	while(j < k && arr[k-1] == arr[k]) k--;
	j++; k--;
      } else if(sum < target) {
	j++;
      } else {
	k--;
      }
    }
  }
  return res;
}

void pprint(const vector<string>& res) {
  for(auto &item: res)
    cout << item << " " << endl;
  cout << endl;
}
int main() {
  int arr[] = {5, -1, -2, 0, 1, 2, 2, -3};
  int len = 8;

  vector<string> res = findSets(arr, len);
  pprint(res);
}
