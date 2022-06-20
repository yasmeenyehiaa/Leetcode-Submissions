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
    int ans = 0;
    void getSum(TreeNode* root, int curTotal)
    {
        curTotal = (curTotal*10) + (root->val);
        
        if(root->left) getSum(root->left, curTotal);
        if(root->right) getSum(root->right, curTotal);
        
        if(!root->left && !root->right)
        {
            ans += curTotal;
        }
    }
    int sumNumbers(TreeNode* root) 
    {
        
        getSum(root, 0);  
        return ans;
    }
};