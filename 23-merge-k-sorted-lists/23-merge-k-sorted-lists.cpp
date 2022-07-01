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
ListNode* mergeKLists(vector<ListNode*>& lists) {
    
    priority_queue<int,vector<int>,greater<int>>pq;
    for(int i=0;i<lists.size();i++)
    {
        ListNode* head = lists[i];
        while(head!=NULL)
        {
            pq.push(head->val);
            head = head->next;
        }
    }
    
    ListNode* start = NULL, *end = NULL;
    
    while(!pq.empty())
    {
        if(start==NULL)  start = end = new ListNode(pq.top());
        else
        {
            end->next = new ListNode(pq.top());
            end= end->next;
        }
        pq.pop();
    }
    return start;
}
};