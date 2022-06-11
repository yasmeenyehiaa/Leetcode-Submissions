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
    vector<int> rightSideView(TreeNode* root) {
        queue<TreeNode*> q;
        vector<int> ans;
        if(root == NULL)
        {
            return ans;
        }
        q.push(root);
        while(!q.empty())
        {
            int sz = q.size();
            for(int i=0; i<sz; i++)
            {
                TreeNode* top = q.front();
                q.pop();
                if(i == sz-1)
                {
                    ans.push_back(top->val);
                }                
                if(top->left)
                {
                    q.push(top->left);
                }
                if(top->right)
                {
                    q.push(top->right);
                }
            }
        }        
        return ans;
    }
};