class Solution {
public:
    void rotateSegment(int l, int r, vector<int>& nums)
    {
        while(l < r)
        {
            int tmp = nums[l];
            nums[l] = nums[r];
            nums[r] = tmp;
            l++, r--;
        }
    }
    void rotate(vector<int>& nums, int k) {
             
        int n = nums.size();
        k = k%n;
        rotateSegment(0,n-1, nums);
        rotateSegment(0,k-1 ,nums);
        rotateSegment(k,n-1, nums);        
    }
};