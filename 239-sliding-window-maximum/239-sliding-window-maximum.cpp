class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        
        int n = nums.size();
        int preMax[n], suffMax[n];
        vector<int> ans;
        for(int i=0; i<n; i++)
        {
            if(i%k == 0)
            {
                preMax[i] = nums[i];
            }
            else preMax[i] = max(preMax[i-1], nums[i]);
        }        
        suffMax[n-1] = nums[n-1];
        for(int i=n-2; i>=0; i--)
        {
            if((i+1)%k == 0)
            {
                suffMax[i] = nums[i];
            }
            else suffMax[i] = max(suffMax[i+1], nums[i]);
        }
        
        for(int i=0; i<n-k+1; i++)
        {
            ans.push_back(max(preMax[i+k-1], suffMax[i]));   
        }
        
        return ans;
    }
};