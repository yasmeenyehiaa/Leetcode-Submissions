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
    int frq[10];
    int pseudoPalindromicPaths (TreeNode* root) {
        
       if(root == NULL) return 0;
        if(root->right == NULL && root->left == NULL)
        {
            frq[root->val]++;
            int cnt = 0;
            for(int i=0; i<=9; i++) cnt += (frq[i]%2 == 1);
            frq[root->val]--;
            return cnt <= 1;            
        }
        frq[root->val]++;
        int ans = pseudoPalindromicPaths(root->left);
        ans += pseudoPalindromicPaths(root->right);
        frq[root->val]--;
        return ans;
        
    }
};