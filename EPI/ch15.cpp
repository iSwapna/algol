/***

    Chapter 15 of EPI

***/


#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

/*
 * 15.11 Levenshtein_dist Min no of edits to tranform string A to B
 *
 */
  
int levenshteinDist(string A, string B) {
  //Try to reduce space usage
  if(A.size() < B.size())
    swap(A, B);
  vector<int> D(B.size()+ 1);
  iota(D.begin(), D.end(), 0);
  int Di_1j_1, Di_1j;
  for(int i = 1; i <= A.size(); ++i) {
    Di_1j_1 = D[0];
    D[0] = i;
    cout << " D Arr: ";
    for(int k = 0; k <D.size(); ++k)
      cout << D[k] << " ";
    cout << endl;

    for(int j = 1; j <= B.size(); ++j) {
      Di_1j = D[j];
      D[j] = A[i - 1] == B[j - 1] ? Di_1j_1 : 1 + min(Di_1j_1, min(D[j-1], D[j]));
      Di_1j_1 = Di_1j;
    }
  }
  return D.back();
}

int main() {

  cout << levenshteinDist("carthorse", "orchestra") << endl;
    cout << levenshteinDist("Carthorse", "Orchestra") << endl;
    cout << levenshteinDist("orichas", "orchat") << endl;

}
