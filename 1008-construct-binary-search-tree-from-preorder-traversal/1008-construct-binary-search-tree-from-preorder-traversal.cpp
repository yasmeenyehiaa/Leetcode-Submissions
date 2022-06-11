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
    void solve(TreeNode* root, int val)
    {
        if(val < root->val)
        {
            if(root->left)
            {
                solve(root->left, val);
            }
            else root->left = new TreeNode{val};
        }
        else
        {
            if(root->right)
            {
                solve(root->right, val);
            }
            else root->right = new TreeNode{val};
        }
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) 
    {        
        auto root = new TreeNode{ preorder[0]};
        
        for(int i = 1; i < preorder.size(); i++)
        {
            solve(root, preorder[i]);
        }
        
        return root;        
    }
};