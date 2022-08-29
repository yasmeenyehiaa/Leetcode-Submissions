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
    int minDepth(TreeNode* root) {
        
        int minimumTreeDepth = 0;
        if(!root) return minimumTreeDepth;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
            minimumTreeDepth++;
            int sz = q.size();
            for(int i=0; i<sz; i++)
            {
                TreeNode* x = q.front();
                q.pop();
                if(!x->left && !x->right) return minimumTreeDepth;
                if(x->left)  q.push(x->left);
                if(x->right) q.push(x->right);
             }
        }
        return minimumTreeDepth;        
    }
};