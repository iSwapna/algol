#include <iostream>
#include <vector>
#include <queue>
#include <functional>

using std::cout;
using std::endl;
using std::vector;
using std::queue;
using std::pair;
using std::priority_queue;
using std::make_pair;
typedef pair<int, int> nodeDist;

class compare{

public:
  bool operator() (const nodeDist a, const nodeDist b) {
    return a.first > b.first;
  }
};

int distance(vector<vector<int> > &adj, vector<vector<int> > &cost, int s, int t) {

  int inf = -1;
  std::vector<int> dist(adj.size(), inf);
  std::vector<int> prev(adj.size(), inf);
  // priority queue with lowest value at top()
  priority_queue<nodeDist, vector<nodeDist>, compare> prio_q;
  dist[s] = 0;
  // init prio q with only s
  prio_q.push(make_pair(0, s));
  while(!prio_q.empty()) {
    int curr = prio_q.top().second; prio_q.pop();

    cout << " Curr node: " << curr << " dist: " << dist[curr] << endl;
    for(int j = 0; j < adj[curr].size(); j++) {
      int next = adj[curr][j];
      if(dist[next] == -1 || dist[next] > dist[curr] + cost[curr][j]) {
	dist[next] = dist[curr] + cost[curr][j];
	cout << " Next: " << next << " dist[next]: " << dist[next] << endl;
	prio_q.push(make_pair(dist[next], next));
      }
    }
  }
  return dist[t];
}

int main() {
  int n, m;
  std::cin >> n >> m;
  if ( n == 1 ) { 
    std::cout << 0 << std::endl; 
    return 0;
  }
  vector<vector<int> > adj(n, vector<int>());
  vector<vector<int> > cost(n, vector<int>());
  for (int i = 0; i < m; i++) {
    int x, y, w;
    std::cin >> x >> y >> w;
    adj[x - 1].push_back(y - 1);
    cost[x - 1].push_back(w);
  }
  int s, t;
  std::cin >> s >> t;
  s--, t--;
  std::cout << distance(adj, cost, s, t) << std::endl;
  
}
