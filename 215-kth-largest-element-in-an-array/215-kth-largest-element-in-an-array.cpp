class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        
        priority_queue<int, vector<int>, greater<int>> pq;
        for(auto el: nums)
        {
            pq.push(el);
            if(pq.size() > k) 
            {
                pq.pop();
            }
        }
        return pq.top();
        
    }
};