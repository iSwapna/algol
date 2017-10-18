/***

    Chapter 10 of EPI
***/

#include <iostream>
using namespace std;
#include <vector>
#include <queue>

struct Compare {
  bool operator()(const pair<int, int>& lhs,
		  const pair<int,int>& rhs) const {
    return lhs.first > rhs.first;
  }
};

vector<int> mergeArrays(const vector<vector<int>>& S) {
  priority_queue<pair<int, int>, vector<pair<int,int>>, Compare> minHeap;
  vector<int> Sidx(S.size(), 0);

  //for every array in S, put smallest element in heap
  for(int i = 0; i < S.size(); ++i) {
    if(S[i].size() > 0) {
      minHeap.emplace(S[i][0],i);
      Sidx[i] = 1;
    }
  }
 
  vector<int> ret;
  while(!minHeap.empty()) {
    pair<int, int> p = minHeap.top();
    minHeap.pop();
    ret.emplace_back(p.first);
    // add the next element to heap, if possible
    if(Sidx[p.second] < S[p.second].size()) {
      minHeap.emplace(S[p.second][Sidx[p.second]++], p.second);
    }
  }
  return ret;
}
