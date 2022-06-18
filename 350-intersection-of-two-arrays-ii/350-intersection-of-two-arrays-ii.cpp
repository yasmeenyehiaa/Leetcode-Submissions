class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        
        map<int,int> cnt1;
        vector<int> ans;
        for(int i=0; i<nums1.size(); i++)
        {
            cnt1[nums1[i]]++;
        }
        for(int i=0; i<nums2.size(); i++)
        {
            if(cnt1[nums2[i]])
            {
                ans.push_back(nums2[i]);
                cnt1[nums2[i]]--;
            }
        }        
        return ans;
        
    }
};