/********************************
 *  Find connected components in a simple graph
 *
 *  Input: Adjacency list representation of Graph: 
 *         n => vertices, m => edges
 *         adj(n, vector<int>) => adj. list             
 *
 * Output: number of connected components 
 *
 ********************************/

#include <iostream>
#include <vector>

using std::vector;
using std::pair;

int dfs(vector<int> &visited, vector<vector<int> > &adj, int z){

  visited[z] = 1;
  for(size_t j = 0; j < adj[z].size(); j++) {
    if(visited[adj[z][j]] != 1) {
      dfs(visited, adj, adj[z][j]);
    }
  }

}

int number_of_components(vector<vector<int> > &adj) {
  int cc = 0;
  
  vector<int> visited(adj.size(), 0);
  for(size_t i = 0; i < visited.size(); i++){
    if(visited[i] != 1) {
      dfs(visited, adj, i);
      cc++;
    }

  }

  return cc;
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
  std::cout << number_of_components(adj);
}
