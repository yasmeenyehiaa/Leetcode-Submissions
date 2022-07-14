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
    int n, x;
    unordered_map<int,int> mp;
    TreeNode* solve(int st, int ed, vector<int>& preorder, vector<int>& inorder)
    {
        if(st > ed) return NULL;
        int el = preorder[x++], pos = mp[el]; 
        
        TreeNode *root = new TreeNode(el);
        root->left  = solve(st, pos-1, preorder, inorder);
        root->right = solve(pos+1, ed, preorder, inorder);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        n = preorder.size();
        for(int i=0; i<n; i++)
        {
            mp[inorder[i]] = i;
        }        
        return solve(0, n-1, preorder, inorder);
    }
};