#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

class BestSeller {

public:
  string findBestSeller(vector<string> goods) {
    if(goods.size() == 0) return "";
    sort(goods.begin(), goods.end());
    int maxCnt = 0;
    string ans = goods[0]; int cnt = 1;
    for(int i = 1; i < goods.size(); ++i) {
      if(goods[i] == goods[i - 1]) {
	cnt++;
	if(cnt > maxCnt) {
	  maxCnt = cnt;
	  ans = goods[i];
	}
      }
      else
	cnt = 1;
    }
    return ans;
  }
};
