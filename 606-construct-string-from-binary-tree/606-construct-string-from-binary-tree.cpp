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
    string ans = "";
    string tree2str(TreeNode* root) {
        if(root == NULL) return"";
        ans += to_string(root->val); 
        if(root->left == NULL && root->right == NULL)  
        {
            return to_string(root->val) + "";  
        }
        if(root->right == NULL)
        {
            ans += "(";
            tree2str(root->left);
            ans += ")";
        }
        else
        {
            ans += "(";
            tree2str(root->left);
            ans += ")";
            ans += "(";
            tree2str(root->right);
            ans += ")";
        }  
        return ans;
    }
};