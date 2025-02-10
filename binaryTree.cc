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
  return root; 
}

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


vector<vector<int>> levelOrder1(TreeNode* root) {
  vector<vector<int>> ans;
  if(root == NULL) {
    return ans;
  }
  queue<TreeNode *> q;
  q.push(root);
  while(!q.empty()) {
    int size = q.size();
    vector<int> level;
    for (int i = 0; i < size; i++) {
      TreeNode *node = q.front();
      q.pop();
      if(node->left != NULL) {
        q.push(node->left);
      }
      if(node->right != NULL) {
        q.push(node->right);
      }
      level.push_back(node->val);
    }
    ans.push_back(level);
  }
  return ans;
}

// Iterative Preorder Traversal in binary trees
vector<int> preorderTraversal(TreeNode* root) {
  vector<int> preorder;
  if(root == NULL)
    return preorder;
  stack<TreeNode* > st;
  st.push(root);
  while (!st.empty())
  {
    root = st.top();
    st.pop();
    preorder.push_back(root->val);
    if(root->right != NULL)
      st.push(root->right);
    if(root->left != NULL)
      st.push(root->left);
  }
  return preorder;
}

// Recursive way 
void preorder(TreeNode* root) {
  if(root == NULL) {
    return;
  }
  cout << root->val << " ";
  preorder(root->left);
  preorder(root->right);
}

void inorder(TreeNode* root) {
  if(root == NULL){
    return;
  }
  inorder(root->left);
  cout << root->val << " ";
  inorder(root->right);
}

void postorder(TreeNode* root) {
  if (root == NULL) {
    return;
  }
  postorder(root->left);
  postorder(root->right);
  cout << root->val << " ";
  // cout << endl;
}

vector<int> inorderTraversal(TreeNode* root) {
  vector<int> inorder;
  stack<TreeNode *> st;
  TreeNode *node = root;
  while(true) {
    if(node != NULL) {
      st.push(node);
      node = node->left;
    } else {
      if(st.empty() == true)
        break;
      node = st.top();
      st.pop();
      inorder.push_back(node->val);
      node = node->right;
    }
  }
  return inorder;
}

vector<int> postorderTraversal(TreeNode* root) {
  vector<int> postorder;
  if(root == NULL)
    return postorder;
  stack<TreeNode *> st1, st2;
  st1.push(root);
  while(!st1.empty()) {
    root = st1.top();
    st1.pop();
    st2.push(root);
    if(root->left != NULL) {
      st1.push(root->left);
    }
    if(root->right != NULL) {
      st1.push(root->right);
    }
  }
  while(!st2.empty()) {
    postorder.push_back(st2.top()->val);
    st2.pop();
  }
  return postorder;
}

vector<int> postorderTraversal1(TreeNode* root){
  vector<int> postorder;
  if(root == NULL)
    return postorder;
  stack<TreeNode *> st;
  TreeNode *curr = root;
  while(curr != NULL || !st.empty()) {
    if(curr != NULL) {
      st.push(curr);
      curr = curr->left;
    } else {
      TreeNode *temp = st.top()->right;
      if(temp == NULL) {
        temp = st.top();
        st.pop();
        postorder.push_back(temp->val);
        while(!st.empty() && temp == st.top()->right){
          temp = st.top();
          st.pop();
          postorder.push_back(temp->val);
        }
      }
      else
      {
        curr = temp;
      }
    }
  }
  return postorder;
}

void preInPostTraversal(TreeNode* root) {
  stack<pair<TreeNode *, int>> st;
  st.push({root, 1});
  vector<int> pre, in, post;
  if(root == NULL)
    return;
  while(!st.empty()) {
    auto it = st.top();
    st.pop();

    // this is part of pre
    // increment 1 to 2
    // push the left side of the tree
    if(it.second == 1) {
      pre.push_back(it.first->val);
      it.second++;
      st.push(it);
      if(it.first->left != NULL) {
        st.push({it.first->left, 1});
      }
    }
    // this is part of in
    // increment from 2 to 3
    // push right
    else if(it.second == 2) {
      in.push_back(it.first->val);
      it.second++;
      st.push(it);
      if(it.first->right != NULL) {
        st.push({it.first->right, 1});
      }
    }
    // don't push it back again
    else {
      post.push_back(it.first->val);
    }
  }
  for (int i = 0; i < pre.size(); i++){
    cout << pre[i] << " ";
  }
  cout << endl;
  for (int i = 0; i < in.size(); i++) {
    cout << in[i] << " ";
  }
  cout << endl;
  for (int i = 0; i<post.size();i++) {
    cout << post[i] << " ";
  }
  cout << endl;
}

int maxDepth(TreeNode* root) {
  if(root == NULL)
    return 0;
  int lh = maxDepth(root->left);
  int rh = maxDepth(root->right);
  return 1 + max(lh, rh);
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
  vector<int> arr = {1, 2, 3, 4, 5, 6, 7};
  
  TreeNode *root = createTree(arr, 0);
  // preorder(root);
  // cout << endl;
  // inorder(root);
  // cout << endl;
  // postorder(root);
  // cout << endl;

  // vector<int> result = postorderTraversal1(root);

  // cout << "Level Order Traversal" << endl;
  // for (int i = 0; i < arr.size(); i++) {
  //   cout << result[i] << " ";
  // }
  //   cout << endl;
  preInPostTraversal(root);

  // cleanup(root);
  return 0;
}