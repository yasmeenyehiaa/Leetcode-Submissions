class Solution {
public:
    int totalFruit(vector<int>& arr) {
        int maxLength = 0, n = arr.size(), l = 0;
        unordered_map<int, int> cnt;
        for(int r=0; r<n; r++)
        {
              cnt[arr[r]]++;
              while(l<n && cnt.size() > 2)
              {
                cnt[arr[l]]--;
                if(cnt[arr[l]] == 0) cnt.erase(arr[l]);
                l++;
              }
              maxLength = max(maxLength, r-l+1);
        }
        return maxLength;
   }
};