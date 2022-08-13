/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
                
        ListNode *slow = head, *fast = head, *tmp = head;
        bool flag = 0;
        while(fast!=NULL && fast->next!=NULL)
        {
          fast = fast->next->next;
          slow = slow->next;
          if(fast == slow) 
          {
              flag = 1; break;
          }
        }
        if(!flag) return NULL;
        
        while(tmp!=slow)
        {
            tmp = tmp->next;
            slow = slow->next;
        }
        return tmp;        
    }
};