class Solution {
public:
   bool  Same(int frq1[] , int frq2[])
   {
        for(int i=0; i<26; i++)
        {
          if(frq1[i] != frq2[i]) return 0;
        }
        return true;
   }
   bool checkInclusion(string p, string s) {
       
        if(s.size() < p.size()) return false;
        int frq1[27] = {0} , frq2[27] = {0}, n = s.size(), l = 0;
        for(auto c: p) frq1[c-'a']++;
        for(int r=0; r<n; r++)
        {
              frq2[s[r]-'a']++;
              if(Same(frq1, frq2) == 1) return true;
              if(r-l+1 >= p.size())
              {
                frq2[s[l]-'a']--;
                l++;
              }
        }
        return false;
        
    }
};