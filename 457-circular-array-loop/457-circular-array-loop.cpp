class Solution {
public:
    int getNxt(int i, int d, vector<int>& nums)
    {
        int dir = (nums[i]>=0), n = nums.size();
        if(d!=dir) return -1;
        
        int nxt = (i+nums[i])%(n);
        if(nxt < 0) nxt += n;
        if(nxt == i) return -1;
        return nxt;
    }
    bool circularArrayLoop(vector<int>& nums) {
        
        int n = nums.size();
        for(int i=0; i<n; i++)
        {
            int dir = (nums[i] >= 0), slow = i, fast = i;
            do
            {
                slow = getNxt(slow, dir, nums);
                fast = getNxt(fast, dir, nums);
                if(fast != -1) fast = getNxt(fast, dir, nums);
            }
            while(slow!=fast && slow!=-1 && fast!=-1);
            if(fast==slow && slow!=-1) return true;
        }
        return false;
    }
};