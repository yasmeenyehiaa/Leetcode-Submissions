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
    int totLength(ListNode *head)
    {
        int c =  0;
        while(head!= NULL)
        {
            c++;
            head = head->next;
        }
        return c;
    }
    ListNode* reverseKGroup(ListNode* head, int k, int tot) {
        
        if(tot < k) return head;
        ListNode *prv = NULL, *curr = head;
        int c = 0;
        while(c<k && curr!=NULL)
        {
            ListNode* nxt = curr->next;
            curr->next = prv;
            prv = curr;
            curr = nxt;
            c++;
        }
        if(curr != NULL) head->next = reverseKGroup(curr, k, tot-k);
        return prv;
    }
    ListNode* reverseKGroup(ListNode* head, int k)
    {
        int tot = totLength(head);
        return reverseKGroup(head, k, tot);
    }
};