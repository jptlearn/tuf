#include <iostream>
#include <vector>
#include <stack>
#include <queue>
using namespace std;

class TreeNode {
  public:
    int val;
    TreeNode *left;
    TreeNode *right;

  public:
  TreeNode(int val1) {
    val = val1;
    left = nullptr;
    right = nullptr;
  }

  public:
  TreeNode(int val1, TreeNode* left1) {
    val = val1;
    left = left1;
    right = nullptr;
  }

  public:
  TreeNode(int val1, TreeNode* left1, TreeNode *right1) {
    val = val1;
    left = left1;
    right = right1;
  }
};

TreeNode* createTree(vector<int>& arr, int i) {
  if(i>=arr.size())
    return nullptr;
  TreeNode *root = new TreeNode(arr[i]);
  root->left = createTree(arr, 2 * i + 1);
  root->right = createTree(arr, 2 * i + 2);
  return root; }

vector<vector<int>> levelOrder(TreeNode* root) {
  vector<vector<int>> ans;
  if(root==NULL)
    return ans;
  queue<TreeNode *> q;
  q.push(root);
  while(!q.empty()) {
    int size = q.size();
    vector<int> level;
    for (int i = 0; i < size; i++) {
      TreeNode *node = q.front();
      q.pop();
      if(node->left != NULL)
        q.push(node->left);
      if(node->right != NULL)
        q.push(node->right);
      level.push_back(node->val);
    }
    ans.push_back(level);
  };
  return ans;
}

void cleanup(TreeNode* root) {
  if(root==nullptr)
    return;
  cleanup(root->left);
  cleanup(root->right);
  delete root;
}

int
main()
{
  vector<int> arr = {1, 2, 3, 4, 5};
  TreeNode *root = createTree(arr, 0);

  vector<vector<int>> result = levelOrder(root);

  cout << "Level Order Traversal" << endl;
  for(const auto& level: result) {
    for(int val : level) {
      cout << val << " ";
    }
    cout << endl;
  }

  cleanup(root);
  return 0;
}