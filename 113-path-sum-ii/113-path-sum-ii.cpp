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
   vector<vector<int>> allPaths;
   void dfs(TreeNode* root, int sum, vector<int> &v)
    {
        if(root == NULL) return;
        v.push_back(root->val);
        if(sum == root->val && root->left == NULL && root->right == NULL)
        {
          allPaths.push_back(v);
        }
        else 
        {
          dfs(root->left, sum - root->val, v);
          dfs(root->right, sum - root->val, v);
        }
        v.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        
        vector<int> v;
        dfs(root, sum, v);
        return allPaths;        
    }
};