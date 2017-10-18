#include <algorithm>
#include <numeric>
#include <iostream>
#include <iomanip>
#include <queue>
#include <vector>
#include <cmath>
using std::priority_queue;
using std::make_pair;
using std::pair;
using std::vector;

using std::endl;
using std::cout;
using std::cin;

typedef pair<double, int> nodeDist;

class compare{
public:
  bool operator() (const nodeDist a, const nodeDist b) {
    return a.first > b.first;
  }
};

double dist(int x1, int y1, int x2, int y2) {
  double res = (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
  res = std::sqrt(res);
  return res;
  
}
double minimum_distance(vector<int> x, vector<int> y) {
  double result = 0.;
  vector<double> cost(x.size(), -1);
  vector<int> parent(x.size(), -1);
  vector<bool> minimized(x.size(), false);
  priority_queue<nodeDist, vector<nodeDist>, compare> prio_q;
  
  cost[0] = 0.; //intial vertex
  
  prio_q.push(make_pair(0., 0));
  
  while(!prio_q.empty()) {
    int curr = prio_q.top().second; prio_q.pop();
    //stop if we encounter duplicates
    minimized[curr] = true;
    for(int j = 0; j < x.size(); j++) {
      if(j == curr || minimized[j]) continue; // disregard cost to oneself
      
      double dd = dist(x[curr], y[curr], x[j], y[j]);
      
      if(cost[j] == -1 || cost[j] > dd) {
	cost[j] = dd ;
	parent[j] = curr;
        prio_q.push(make_pair(cost[j], j));
      }
    }
  }
  result = std::accumulate(cost.begin(), cost.end(), 0.0);
  //write your code here
  return result;
} 

int main() {
  size_t n;
  std::cin >> n;
  vector<int> x(n), y(n);
  for (size_t i = 0; i < n; i++) {
    std::cin >> x[i] >> y[i];
  }
  std::cout << std::setprecision(10) << minimum_distance(x, y) << std::endl;
}
