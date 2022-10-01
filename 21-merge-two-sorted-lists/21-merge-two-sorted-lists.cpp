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
class Solution {
public:
    
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        
        ListNode *dummy = new ListNode(0);
        ListNode *root = dummy;
        while(l1 != NULL && l2 != NULL)
        {
            if(l1->val < l2->val)
            {
                root->next = l1;
                l1 = l1->next;
            }
            else 
            {
                root->next = l2;
                l2 = l2->next;
            }
            root = root->next;
        }
        if(l1 != NULL) root->next = l1;
        if(l2 != NULL) root->next = l2;
        return dummy->next;
    }
};