/*******************************************
 *
 * Find if the vertex x is reachable from vertex y
 *
 * DFS
 ***********************************************/

#include <iostream>
#include <vector>

using std::vector;
using std::pair;

int explore(vector<int> &visited,
	    vector<vector<int> > &adj,
	    int z) {

  visited[z] = 1;
  for(size_t j = 0; j < adj[z].size(); j++) {
      if( visited[adj[z][j]] != 1 ) {
	explore(visited, adj, adj[z][j]);
      }
  }
}

int reach(vector<vector<int> > &adj, int x, int y) {
  vector<int> visited(adj.size(), 0);

  explore(visited, adj, x);
  if(visited[y] == 1) 
    return 1;
  else
    return 0;
}

int main() {
  size_t n, m;
  std::cin >> n >> m;
  vector<vector<int> > adj(n, vector<int>());
  for (size_t i = 0; i < m; i++) {
    int x, y;
    std::cin >> x >> y;
    adj[x - 1].push_back(y - 1);
    adj[y - 1].push_back(x - 1);
  }
  int x, y;
  std::cin >> x >> y;
  std::cout << reach(adj, x - 1, y - 1) << std::endl;
}
