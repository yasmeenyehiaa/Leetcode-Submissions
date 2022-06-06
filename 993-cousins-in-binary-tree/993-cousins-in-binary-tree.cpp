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
    void solve(TreeNode* root, int x, int y, int d, int par)
    {
        if(!root || (d_x != -1 && d_y != -1))
        {
            return;
        }
        if(root->val == x)
        {
            d_x = d;
            p_x = par;
        }          
        if(root->val == y)
        {
            d_y = d;
            p_y = par;
        }        
        solve(root->left, x, y, d+1, root->val);
        solve(root->right, x, y, d+1, root->val);        
    }
    bool isCousins(TreeNode* root, int x, int y)
    {
        solve(root, x, y, 0, -1);
        return p_x != p_y && d_x == d_y;
    }
    
private:
    int p_x = -1, p_y = -1, d_x = -1, d_y = -1;
};