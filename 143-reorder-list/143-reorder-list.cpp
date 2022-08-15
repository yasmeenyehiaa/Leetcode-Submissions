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
  ListNode* rev(ListNode *head)
  {
    ListNode *prev = NULL;
    while(head)
    {
      ListNode *tmp = head->next;
      head->next = prev;
      prev = head;
      head = tmp;
    }
    return prev;
  }
    void reorderList(ListNode* head) {
                
        if(head==NULL || head->next==NULL) return;
        
        ListNode *slow = head, *fast = head;
        while(fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }  
        ListNode* second = rev(slow), *first = head, *tmp;
        while(second != NULL && first != NULL)
        {
            tmp = first->next;
            first->next = second;
            first = tmp;
            
            tmp = second->next;
            second->next = first;
            second = tmp;
        }   
        if(first != NULL)  first->next = NULL;
    }    
};