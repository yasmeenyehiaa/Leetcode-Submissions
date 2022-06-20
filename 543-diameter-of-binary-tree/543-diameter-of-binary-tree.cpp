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
    int getDiameter(TreeNode* root, int len)
    {
        if(root == NULL) return 0;
        int l = getDiameter(root->left, len), r =getDiameter(root->right, len);
        ans = max(ans, l+r+1);
        return max(l,r)+1;
    }
    int diameterOfBinaryTree(TreeNode* root) 
    {        
        getDiameter(root, 0);
        return ans-1;        
    }
};