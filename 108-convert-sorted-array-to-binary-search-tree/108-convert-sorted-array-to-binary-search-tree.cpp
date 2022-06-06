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
    TreeNode* solve(vector<int>& nums, int l, int r)
    {
        if(l > r)
        {
            return NULL;
        }
        int mid = (l+r)/2;        
        return new TreeNode(nums[mid], solve(nums, l, mid-1), solve(nums, mid+1, r));
        
    }    
    TreeNode* sortedArrayToBST(vector<int>& nums)
    {
        if(nums.size() == 0)
        {
            return NULL;
        }                
        return solve(nums, 0, nums.size()-1);
        
    }
};