class Solution {
public:
    string reorganizeString(string s) {
        string ans = "";
        priority_queue<pair<int,char>> pq;
        map<char, int> cnt;
        for(auto ch:s)
        {
            cnt[ch]++;
        }
        for(auto p: cnt)
        {
            pq.push({p.second, p.first});
        }
        while(!pq.empty())
        {
            auto top1 = pq.top();
            pq.pop();
            if(pq.empty()) 
            {
                if(top1.first > 1) return "";
                ans += top1.second;
            }
            else
            {
                ans += top1.second;
                auto top2 = pq.top();
                pq.pop();
                ans += top2.second;
                if(top1.first > 1)
                {
                    top1.first--;
                    pq.push(top1);
                }
                if(top2.first > 1)
                {
                    top2.first--;
                    pq.push(top2);
                }
            }                

        }
        return ans;        
    }
};