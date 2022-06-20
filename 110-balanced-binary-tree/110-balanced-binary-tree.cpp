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
    int check(TreeNode* root)
    {
        if(root == NULL)
        {
            return 0;
        }
        int left =   check(root->left);
        int right = check(root->right);
        if(abs(right - left) <= 1)
        {
            return max(left, right)+1;
        }
        return -99999;
    }
    bool isBalanced(TreeNode* root) 
    {
        return check(root) >= 0;
    }
};