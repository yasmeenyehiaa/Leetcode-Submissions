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
    vector<string> ans; 
    void rec(TreeNode* root, string s)
    {
        if(root == NULL) return;
        
        s += to_string(root->val);
        if(!root->left && !root->right)
        {
            ans.push_back(s);
            return;
        }
        
        s+= "->";
        rec(root->left, s);
        rec(root->right, s);
    }
    vector<string> binaryTreePaths(TreeNode* root) 
    {
        rec(root, "");
        
        return ans;
    }
};