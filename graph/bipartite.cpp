#include <iostream>
#include <vector>
#include <queue>

using std::vector;
using std::queue;

int bipartite(vector<vector<int> > &adj) {
  // 1 --> white, 2 --> black, 3 --> unassigned
  vector<int> black_white(adj.size(), 3);
  
  int inf = adj.size() + 99;
  vector<int> dist(adj.size(), inf);
  dist[0] = 0; //init a node as starting node
  black_white[0] = 1; // init the start node to white

  queue<int> nodes;
  nodes.push(0);

  while(!nodes.empty()) {
    int cur = nodes.front();
    nodes.pop();
    for(int i = 0; i < adj[cur].size(); i++) {
      int edge_to_node = adj[cur][i];
      if(dist[edge_to_node] == inf) {
	nodes.push(edge_to_node);
	dist[edge_to_node] = dist[cur] + 1;
	black_white[edge_to_node] = 
	  (black_white[cur]  == 1) ? 2 : 1;
	  
      } else if(black_white[edge_to_node] == black_white[cur])
	return 0;
    }
  }
  //write your code here
  return 1;
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
  std::cout << bipartite(adj);
}
