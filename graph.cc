#include <iostream>
#include <vector>
using namespace std;

// int main() {
//     // Create a graph with 4 nodes
//     vector<vector<int>> graph = {
//         {1, 2}, // Node 0 is connected to nodes 1 and 2
//         {0, 2}, // Node 1 is connected to nodes 0 and 2
//         {0, 1, 3}, // Node 2 is connected to nodes 0, 1, and 3
//         {2} // Node 3 is connected to node 2
//     };

//     // Print the graph
//     for (int i = 0; i < graph.size(); i++) {
//         cout << "Node " << i << " is connected to: ";
//         for (int neighbor : graph[i]) {
//             cout << neighbor << " ";
//         }
//         cout << endl;
//     }

//     return 0;
// }

// int main() {
//   int n, m;
//   cin >> n >> m;
//   int adj[n + 1][m + 1];
//   for (int i = 0; i < m; i++) {
//     int u, v;
//     cin >> u >> v;
//     adj[u][v] = 1;
//     adj[v][u] = 1;

//   }
//     return 0;
// }

int main() {
  int n, m;
  cin >> n >> m;
  vector<int> adj[n + 1];
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  return 0;
}