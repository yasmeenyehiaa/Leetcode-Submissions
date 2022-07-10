class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        int n = nums.size();
        vector<int> tmp(n);
        sort(nums.begin(), nums.end());
        int i = n/2, j = n-1, k = 0;
        if(n%2 == 0) i--;
        while( (i >= 0 || j > i) && k < n)
        {
            if(k%2 == 0)
            {
                 tmp[k++] = nums[i--];
            }
            else tmp[k++] = nums[j--];
        }
        nums = tmp;
        
    }
};