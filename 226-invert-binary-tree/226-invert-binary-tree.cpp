/**
 * Definition for a binary tree node.
You have attempted to run code too soon. Please try again in a few seconds, or subscribe to reduce wait time. * struct TreeNode {
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
    TreeNode* invertTree(TreeNode* root) {
        
        if(root == NULL)
        {
            return NULL;
        }        
        invertTree(root->left);
        invertTree(root->right);
        swap(root->right, root->left);
        
        return root;        
    }
};