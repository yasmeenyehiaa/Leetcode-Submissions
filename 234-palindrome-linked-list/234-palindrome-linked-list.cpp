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
    ListNode* rev(ListNode* head)
    {
        ListNode *prev = NULL;
        while(head)
        {
            ListNode*tmp = head->next;
            head->next = prev;
            prev = head;
            head = tmp;
        }
        return prev;
    } 
    bool isPalindrome(ListNode* head) {
        ListNode* slow = head, *fast = head;
        while(fast->next && fast->next->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        slow->next = rev(slow->next);
        slow = slow->next;
        ListNode* node = head;
        while(slow)
        {
            if(slow->val != node->val) return false;
            slow = slow->next;
            node = node->next;            
        }
        return true;
        
    }
};