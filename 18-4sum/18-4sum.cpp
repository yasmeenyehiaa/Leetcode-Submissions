class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& arr, long long target) {
        sort(arr.begin(), arr.end());
        vector<vector<int>> ans;
        set<vector<int>> st;
        int n = arr.size();
        for(int i=0; i<n-3; i++)
        {
            if(i>0 && arr[i] == arr[i-1]) continue;
            for(int j=i+1; j<n-2; j++)
            {
                if(j>i+1 && arr[j] == arr[j-1]) continue;
                int l = j+1, r = n-1;
                 while(l < r)
                {
                    long long val = (long long) arr[i]+arr[j]+arr[l]+arr[r];
                    if(val == target)
                    {
                        st.insert({arr[i],arr[j],arr[l],arr[r]});
                        l++, r--;
                    }
                    else if(val > target) r--;
                    else l++;
                }
            }
        }
        for(auto a: st) ans.push_back(a);
        return ans;
    }
};