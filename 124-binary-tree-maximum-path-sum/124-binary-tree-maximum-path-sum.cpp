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
    int ans = INT_MIN;
    int dfs(TreeNode* root)
    {
        if(root == NULL) return 0;
        int x = root->val, 
        l = max(0,dfs(root->left)),
        r = max(dfs(root->right),0);
        ans = max(ans, l+r+x);
        return max(l,r)+x;
    }
    int maxPathSum(TreeNode* root) {
        
        dfs(root);
        return ans;        
    }
};