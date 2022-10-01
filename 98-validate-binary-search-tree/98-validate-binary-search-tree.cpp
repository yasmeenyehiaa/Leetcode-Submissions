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
    
    bool isValidBST(TreeNode* root, TreeNode* left = NULL, TreeNode* right = NULL) {
        
        return isValid(root, LONG_MIN, LONG_MAX);
    }
    bool isValid(TreeNode *root, long long low, long long high)
    {
        if(root == NULL) return true;        
        if(root->val < high && root->val > low)
        {
            return isValid(root->left, low, root->val) && isValid(root->right, root->val, high);
        }
        else return false;
    }
};
// TC: O(n), each node is visited once
// SC: O(n), stack space used for recursion