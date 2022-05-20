class Solution {
public:
    string removeDuplicates(string s) {
        
        if(s == "")
        {
             return "";
        } 
        string ans = "";
        stack<char> st;
        st.push(s[0]);
        for(int i=1;i <s.size(); i++)
        {
            if(st.empty() || s[i] != st.top())
            {
                st.push(s[i]);
            }
            else
            {
                st.pop();
            }
        }
        while(!st.empty())
        {
            char c = st.top();
            st.pop();
            ans += c;
        }
        reverse(ans.begin(), ans.end());
        return ans;
        
    }
};