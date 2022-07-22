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
    ListNode* partition(ListNode* head, int x) {
        
        ListNode *st = new ListNode(), *mid = new ListNode(), *end = new ListNode(), tmp = *head;
        ListNode *p1 = st, *p2 = mid;
        while(head != NULL)
        {
            if(head->val < x)
            {
                st->next = new ListNode(head->val);
                st = st->next;
            }
            else
            {
                mid->next = new ListNode(head->val);
                mid = mid->next;
            }
            head = head->next;
        }
       st->next  = p2->next;
       return p1->next;
    }
};