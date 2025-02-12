// // linear search

// int linearSearch(int arr[], int n, int target) {
//   for (int i = 0; i < n; i++) {
//     if (arr[i] == target) {
//       return i;
//     }
//   }
//   return -1;
// }

// Binary Search Tree
// #include <iostream>
// #include <algorithm>
// using namespace std;

// struct Node
// {
//   /* data */
//   int data;
//   Node *left;
//   Node *right;

//   Node(int value) {
//     data = value;
//     left = right = nullptr;
//   }
// };

// Node* searchBST(Node* root, int target) {
//   if (root == nullptr || root->data == target) {
//     return root;
//   }
//   if (target < root->data) {
//     return searchBST(root->left, target);
//   }

//   return searchBST(root->right, target);
// }

// Node* searchBSTIterative(Node* root, int target) {
//   while(root != nullptr && root->data != target) {
//     root = (target < root->data) ? root->left : root->right;
//   }
//   return root;
// }

// int main() {
//   Node *root = new Node(8);
//   root->left = new Node(3);
//   root->right = new Node(10);
//   root->left->left = new Node(1);
//   root->left->right = new Node(6);

//       /*
//         BST structure:
//              8
//            /   \
//           3     10
//          / \
//         1   6
//     */
//   int target = 6;
//   Node *result = searchBST(root, target);
// }


// Kruskal's Algorithm
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class DisjointSet{
  private:
  vector<int> parent;
  vector<int> rank; // Used for weighted union
  int n; // Number of elements

  public:
  DisjointSet(int size) : n(size){
    parent.resize(n);
    rank.resize(n, 0);
    // Initialize each element as its own parent
    for (int i = 0; i < n; i++) {
      parent[i] = i;
    }
  }
  
  // Collapsing Find - Path Compression
  int find(int x) {
    if (parent[x] != x) {
      parent[x] = find(parent[x]); // Path Compression
    }
    return parent[x];
  }

  // Weighted Union
  void unionSets(int x, int y) {
    int rootX = find(x);
    int rootY = find(y);

    if(rootX != rootY){
      // Union by rank
      if(rank[rootX] < rank[rootY]) {
        swap(rootX, rootY);
      }
      parent[rootY] = rootX;
      if(rank[rootX] == rank[rootY]) {
        rank[rootX]++;
      }
    }
  }

  // Check if two elements are in same set
  bool connected(int x, int y) {
    return find(x) == find(y);
  }
};

vector<Edge> kruskalMST(vector<Edge>& edges,int V) {
  // Sort edges by weight
  sort(edges.begin(), edges.end(),
       [](Edge &a, Edge &b)
       { return a.weight < b.weight; });
  DisjointSet ds(V);
  vector<Edge> mst;

  for(Edge& e: edges) {
    if(!ds.connected(e.src, e.dest)) {
      ds.unionSets(e.src, e.dest);
      mst.push_back(e);
    }
  }
  return mst;
}

// Example usage with Kruskal's Algorithm
struct Edge {
  int src, dest, weight;
  Edge(int s, int d, int w) : src(s), dest(d), weight(w) {}
};

int main() {
  // Example usage
  vector<Edge> edges = {
      Edge(0, 1, 4),
      Edge(0, 2, 3),
      Edge(1, 2, 1),
      Edge(1, 3, 2),
      Edge(2, 3, 4)};
  int V = 4; // Number of Vertices

  vector<Edge> mst = kruskalMST(edges, V);
  cout << "Edges in MST: \n";
  for (Edge &e: mst) {
    cout << e.src << " - " << e.dest << " : " << e.weight << endl;
  }
  return 0;
}