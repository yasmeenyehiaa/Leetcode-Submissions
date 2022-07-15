class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        
        queue<pair<string,int>> q;
        unordered_set<string> st(wordList.begin(), wordList.end());
        
        q.push({beginWord, 1});
        while(!q.empty())
        {
            pair<string,int> p = q.front();
            q.pop();
            string s = p.first;
            int x = p.second;
            if(s == endWord) return x;
            st.erase(s);
            for(int i=0; i<s.size(); i++)
            {
                char tmp = s[i];
                for(int j=0; j<26; j++)
                {
                    s[i] = j+'a';
                    if(st.find(s) != st.end()) q.push({s, x+1});
                }
                s[i] = tmp;
            }            
        }
        return 0;
        
        
        
    }
};