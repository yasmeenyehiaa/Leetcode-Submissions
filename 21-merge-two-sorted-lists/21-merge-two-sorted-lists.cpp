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
   
    ListNode* solve(ListNode* list1, ListNode* list2)
    {
        if(list1 == NULL && list2 == NULL)
        {
            return NULL;
        }
        
        ListNode * node = new ListNode();        
        int val1 = (list1? list1->val : 1000), val2 = (list2? list2->val : 1000);
        
        if(val1 < val2)
        {
            node->val = val1;
            node->next = solve(list1->next, list2);
        }
        else
        {
            node->val = val2;
            node->next = solve(list1, list2->next);
        }       
        
        return node;
    }
    
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        
        return solve(list1,list2);
    }
};