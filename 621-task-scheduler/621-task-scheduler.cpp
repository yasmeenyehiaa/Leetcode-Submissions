class Solution {
public:
    int leastInterval(vector<char>& tasks, int k) {
        
        int intervalCount = 0;
        unordered_map<char,int> frq;
        priority_queue<int> pq;
        queue<pair<int,int>> q;
        for(auto t: tasks) frq[t]++;
        for(auto p: frq) pq.push(p.second);
        
        while(!pq.empty() || !q.empty())
        {
            if(!q.empty() && intervalCount == q.front().second)   
            {
              pq.push(q.front().first);
              q.pop();
            } 
            intervalCount++;
            if(!pq.empty())
            {
              int task = pq.top()-1;
              pq.pop();
              if(task > 0) q.push({task, intervalCount+k});
            }
        }    
        
        return intervalCount;
    }
};