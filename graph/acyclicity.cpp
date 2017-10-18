/*
 * *  Find out if your G is a DAG
 * THIS ALGOL SHOULD BE SIMPLIFIED!!!
 *****************************/


#include <iostream>
#include <vector>

using std::vector;
using std::cout;
using std::endl;

int explore(vector<int> &visited, vector<vector<int>> &adj, int x, int z) {
  visited[x] = 1;
  for(size_t i = 0; i < adj[x].size(); i++) {
    if(adj[x][i] == z) {
      return 1; // found cycle!!
    }
    if(visited[adj[x][i]] != 1) {
      if(explore(visited, adj, adj[x][i], z) == 1){
	return 1;
      }
    }
  }
  return 0;
}


int acyclic(vector<vector<int>> &adj) {
  
  for(size_t j = 0; j < adj.size(); j++) {
    vector<int> visited(adj.size(), 0);
    
    if(explore(visited, adj, j, j) == 1) {
      return 1;
    }
  }
  return 0;
}

int main() {
  size_t n, m;
  std::cin >> n >> m;
  vector<vector<int> > adj(n, vector<int>());
  for(size_t i = 0; i < m; i++) {
    int x, y;
    std::cin >> x >> y;
    adj[x - 1].push_back(y - 1);
  }
  std::cout << acyclic(adj);
}
