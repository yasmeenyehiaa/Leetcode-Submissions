/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        
    vector<vector<int>> result;
    if(!root) return result;
    queue<TreeNode*>q;
    q.push(root);
    bool ok = 0;
    while(!q.empty())
    {
      vector<int> v;
      int sz = q.size();
      for(int i=0; i<sz; i++)
      {
        TreeNode* x = q.front();
        q.pop();
        v.push_back(x->val);
        if(x->left) q.push(x->left);
        if(x->right) q.push(x->right);
      }
      if(ok)
      {
        reverse(v.begin(), v.end());
      }
      ok = !ok;
      result.push_back(v);
    }
    return result;
        
    }
};