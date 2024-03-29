/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    TreeNode* sortedListToBST(ListNode* head) {
        if(head == NULL) return NULL;
        if(head->next == NULL) return new TreeNode(head->val);
        
        ListNode* fast = head, *slow = head, *prv;
        while(fast!=NULL && fast->next!=NULL)
        {
            fast = fast->next->next;
            prv = slow;
            slow = slow->next;
        }
        
        TreeNode* root = new TreeNode(slow->val);
        prv->next = NULL;
        root->left = sortedListToBST(head);        
        root->right = sortedListToBST(slow->next);
        return root;
    }
};

// TC: O(n * log(n)) 
// SC: O(log(n))