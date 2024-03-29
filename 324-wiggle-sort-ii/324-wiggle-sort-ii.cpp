class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        int n = nums.size();
        vector<int> tmp(n);
        int i = n/2, j = n-1, k = 0;
        if(n%2 == 0) i--;
        sort(nums.begin(), nums.end());
        while( (i >= 0 || j > i) && k < n)
        {
            if(k%2) tmp[k++] = nums[j--];
            else tmp[k++] = nums[i--];
        }
        nums = tmp;        
    }
};