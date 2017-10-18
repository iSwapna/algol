#include <stack>
#include <iostream>
#include <vector>

using std::vector;
using std::cout;
using std::endl;

void explore(vector<vector<int> > &adj,
	     vector<int> &used, int k) {
  used[k] = 1;
  for(size_t i = 0; i < adj[k].size(); i++) {
    if(used[adj[k][i]] != 1) {
      explore(adj, used, adj[k][i]);
    }
  }
}

int number_of_strongly_connected_components(vector<vector<int> > adj, 
					    std::stack<int> &post_order) {
  int result = 0;
  vector<int> used(adj.size(), 0);
  while(!post_order.empty()) {
    int node = post_order.top();
    post_order.pop();
    if(used[node] == 0) {
      explore(adj, used, node);
      result++;
    } 
  }
  return result;
}

void r_dfs(vector<vector<int> > &r_adj,
	   vector<int> &visited, 
	   std::stack<int> &post_order, int k) {

  if(visited[k] != 1) {
    visited[k] = 1;
  
    for(size_t i = 0; i < r_adj[k].size(); i++) {
      if(visited[r_adj[k][i]] != 1) {
	r_dfs(r_adj, visited, post_order, r_adj[k][i]);
      }
    }

    post_order.push(k);  
  }
}

int main() {
  size_t n, m;
  std::cin >> n >> m;
  vector<vector<int> > adj(n, vector<int>());

  //reverse adj list for reverse graph with same scc as original
  vector<vector<int> > r_adj(n, vector<int>());

  for (size_t i = 0; i < m; i++) {
    int x, y;
    std::cin >> x >> y;
    adj[x - 1].push_back(y - 1);
    r_adj[y - 1].push_back(x - 1);
  }
  vector<int> visited(n, 0);
  std::stack<int> post_order;

  //calcualte the post order first
  for(size_t i = 0; i < n; i++) {
    r_dfs(r_adj, visited, post_order, i);
  }
  std::cout <<
    number_of_strongly_connected_components(adj, post_order) << endl;
}
