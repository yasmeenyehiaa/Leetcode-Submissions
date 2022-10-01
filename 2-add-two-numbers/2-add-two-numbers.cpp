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
    
    
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        ListNode *dummy = new ListNode(0), *root = dummy;
        int c = 0;
        while(l1 != NULL || l2 != NULL)
        {
            int a = (l1 == NULL? 0 : l1->val);
            int b = (l2 == NULL? 0 : l2->val);
            root->next = new ListNode((a+b+c)%10);
            c = (a+b+c)/10;
            root = root->next;
            if(l1) l1 = l1->next;
            if(l2) l2 = l2->next;
        }
        if(c > 0) root->next = new ListNode(c);
        return dummy->next;
    }
};