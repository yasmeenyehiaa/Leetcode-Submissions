class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& p, vector<int>& c) {
        
        priority_queue<pair<int,int>> maxHeap;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> minHeap;
        for(int i=0; i<p.size(); i++)
        {
            if(c[i]>w) minHeap.push({c[i], p[i]});
            else maxHeap.push({p[i], c[i]});
        }
        while(k>0)
        {
            while(!minHeap.empty() && minHeap.top().first <= w)
            {
                maxHeap.push({minHeap.top().second , minHeap.top().first});
                minHeap.pop();
            }
            if(!maxHeap.empty())
            {
                w += maxHeap.top().first;
                maxHeap.pop();
                k--;
            }
            else return w;
        }
        return w;        
    }
};