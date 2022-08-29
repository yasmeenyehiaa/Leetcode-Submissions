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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> result;
       // if(!root) return result;
        queue<TreeNode*>q;
        q.push(root);
        bool ok = 0;
        while(!q.empty())
        {
              double cur = 0;
              int sz = q.size();
              for(int i=0; i<sz; i++)
              {
                TreeNode* x = q.front();
                q.pop();
                cur += x->val;
                if(x->left) q.push(x->left);
                if(x->right) q.push(x->right);
              }
              cur /= sz;
              result.push_back(cur);
        }
        return result;
    }
};