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
    
    int countNodes(TreeNode* root, int mx)
    {
        if(root == NULL) return 0;
        int ret = 0;
        if(root->val >= mx) ret++;
        mx = max(mx, root->val);
        ret += countNodes(root->left, mx);
        ret += countNodes(root->right, mx);
        return ret;
    }
    int goodNodes(TreeNode* root) 
    {
        return countNodes(root->left, root->val) + countNodes(root->right, root->val) + 1;
    }
};

