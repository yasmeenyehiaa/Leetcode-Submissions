class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        unordered_map<string, int> mp;
        vector<vector<string>> ret;
        int cur = 0;
        for(int i=0; i<strs.size(); i++)
        {
            string tmp = strs[i];
            sort(tmp.begin(), tmp.end());
            if(mp.find(tmp) != mp.end())
            {
                ret[mp[tmp]].push_back(strs[i]);
            }
            else 
            {
                mp[tmp] = cur;
                vector<string> v;
                v.push_back(strs[i]);
                ret.push_back(v);
                cur++;
            }
        }    
        return ret;
    }
};