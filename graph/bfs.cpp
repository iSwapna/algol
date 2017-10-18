/************************
*
*  bfs: shortest path in unweighted graphs
*
*
*************************/

#include <iostream>
#include <vector>
#include <queue>

using std::vector;
using std::queue;

int distance(vector<vector<int> > &adj, int s, int t) {
  int inf = adj.size() + 99;
  vector<int> dist(adj.size(), inf);
  dist[s] = 0;
  queue<int> nodes;
  nodes.push(s); // init queue

  while(!nodes.empty()) {
    int uu = nodes.front();
    nodes.pop();
    for(int j = 0; j < adj[uu].size(); j++) {
      int vv = adj[uu][j];
      if(dist[vv] == inf) {
	nodes.push(vv);
	dist[vv] = dist[uu] + 1;
      }
    }
  }

  // return result
  if(dist[t] != inf) {
    return dist[t];
  }
  return -1;
}


int main() {
  int n, m;
  std::cin >> n >> m;
  vector<vector<int> > adj(n, vector<int>());
  for (int i = 0; i < m; i++) {
    int x, y;
    std::cin >> x >> y;
    adj[x - 1].push_back(y - 1);
    adj[y - 1].push_back(x - 1);
  }
  int s, t;
  std::cin >> s >> t;
  s--, t--;
  std::cout << distance(adj, s, t);
}
