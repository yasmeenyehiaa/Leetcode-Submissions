class Solution {
public:
    void solve(TreeNode* root, vector<int>& nodes)
    {
        if(!root) return;
        
        solve(root->left, nodes);
        nodes.push_back(root->val);
        solve(root->right, nodes);
    }
        
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> nodes;
        solve(root, nodes);        
        return nodes;
    }
};