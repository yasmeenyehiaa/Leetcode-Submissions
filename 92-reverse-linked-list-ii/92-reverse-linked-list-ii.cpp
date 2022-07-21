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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(left == right || head == NULL) return head;        
        ListNode *headCopy = head, *start = new ListNode(0);
        stack<ListNode*> st;        
        int ctr = 1;
        while(ctr < left)
        {
            start = head;
            head = head->next;
            ctr++;
        }
        ListNode *startCopy = start;
        while(ctr <= right)
        {
            st.push(head);
            head = head->next;
            ctr++;
        }
        ListNode *lst = head;
        while(!st.empty())
        {
            start->next = st.top();  
            st.pop();
            start = start->next;
        }
        start->next = head;
        return startCopy->val == 0? startCopy->next:headCopy;
    }
};