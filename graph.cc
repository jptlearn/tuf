// #include <iostream>
// #include <vector>
// using namespace std;

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


// vector<int> bfsOfGraph(int V, vector<int> adj[]) {
//   vector<int> vis(V, 0);
//   vis[0] = 1;
//   queue<int> q;
//   q.push(0);
//   vector<int> bfs;
//   while(!q.empty()) {
//     int node = q.front();
//     q.pop();
//     bfs.push_back(node);

//     for(auto neighbor: adj[node]) {
//       if(!vis[neighbor]) {
//         vis[neighbor] = 1;
//         q.push(neighbor);
//       }
//     }
//   }
//   return bfs;
// }

#include <iostream>
#include <vector>
using namespace std;

void dfs(int node, vector<int> adj[], vector<int> vis, vector<int> &ls) {
  vis[node] = 1;
  ls.push_back(node);
  // Traverse all its neighbors
  for(auto it: adj[node]) {
    if(!vis[it]) {
      dfs(it, adj, vis, ls);
    }
  }
}

vector<int> dfsOfGraph(int V, vector<int> adj[]) {
  // Code here
  vector<int> vis{V, 0};
  int start = 0;
  vector<int> ls;
  dfs(start, adj, vis, ls);
}

int main() {
    int n, m;
    cout << "Enter number of nodes and edges: ";
    cin >> n >> m;
    
    // Use vector of vectors instead of array
    vector<vector<int>> adj(n);
    
    cout << "Enter " << m << " edges (u v):" << endl;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        // Add input validation
        if (u >= 0 && u < n && v >= 0 && v < n) {
            adj[u].push_back(v);
            adj[v].push_back(u);
        } else {
            cout << "Invalid edge! Nodes should be between 0 and " << n-1 << endl;
            i--; // Retry this edge
        }
    }
    
    // Print adjacency list using vector size
    for (int i = 0; i < n; i++) {
        cout << "Node " << i << ": ";
        for (int neighbor : adj[i]) {
            cout << neighbor << " ";
        }
        cout << endl;
    }
    
    return 0;
}

// #include <iostream>
// #include <vector>
// using namespace std;

// class Graph {
//   private:
//     vector<vector<int>> adj;
//     int V; // number of vertices
//   public:
//     Graph(int vertices) : V(vertices) {
//       adj.resize(V);
//     }

//     void addEdge(int u, int v, bool isDirected=false) {
//       adj[u].push_back(v);
//       if(!isDirected) {
//         adj[v].push_back(u);
//       }
//     }

//     void printGraph() {
//       for (int i = 0; i < V; i++) {
//         cout << "Node " << i << ": ";
//         for(int neighbor: adj[i]) {
//           cout << neighbor << " ";
//         }
//         cout << endl;
//       }
//     }
// };

// int main() {
//   Graph g(4);

//   g.addEdge(0, 1);
//   g.addEdge(0, 2);
//   g.addEdge(1, 2);
//   g.addEdge(2, 3);

//   g.printGraph();
//   return 0;
// }