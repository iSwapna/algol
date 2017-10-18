#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

int negCyc(vector<vector<int> > &adj,
	   vector<vector<int> > &cost, int s) {
  int inf = 1410065407;
  int V = adj.size();
  std::vector<int> dist(V, inf);
  // Repeat FOR ALL V
  for(int i = 0; i <= V-1; i++) {
  dist[i] = 0;
    // FOR ALL E of s
    for(int j = 0; j < adj.size(); j++) {
      for(int k = 0; k < adj[j].size(); k++) {
	int next = adj[j][k];
	if(dist[next] > dist[j] + cost[j][k]) {
	  dist[next] = dist[j] + cost[j][k];
	  if( i == V-1 ) { return 1; }
	}
      }
    }

  }
  return 0;
}

int negative_cycle(vector<vector<int> > &adj,
		   vector<vector<int> > &cost) {
    if(negCyc(adj, cost, 0)) {
      return 1;
    }
  return 0;
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
  std::cout << negative_cycle(adj, cost) << endl;
}
