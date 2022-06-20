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
    int isGood(TreeNode* root, int mx)
    {
        if(root == NULL)
        {
            return 0;
        }
        
        mx = max(mx, root->val);        
        return isGood(root->left, mx) + isGood(root->right, mx) + (mx == root->val); 
    }
    int goodNodes(TreeNode* root) {
        
        return isGood(root->left, root->val) + isGood(root->right, root->val) + 1;       
    }
};