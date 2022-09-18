class Solution {
public:
    string frequencySort(string s) {
        string ans = "";
        map<char, int> frq;
        vector<char> buckets[s.size()+1];
        int mx = 0;
        for(int i=0; i<s.size(); i++) frq[s[i]]++;
        for(auto p:frq)
        {
            buckets[p.second].push_back(p.first);
            mx = max(mx, p.second);
        }
        for(int i=mx; i>=0; i--)
        {
            for(auto a: buckets[i])
            {
                int k = i;
                while(k--)
                {
                    ans += a;
                }
            }
        }
        return ans;
    }
};