class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        
        set<int> s1, s2;
        vector<int> ans;
        for(int i=0; i<nums1.size(); i++)
        {
            s1.insert(nums1[i]);
        }
        
        for(int i=0; i<nums2.size(); i++)
        {
            s2.insert(nums2[i]);
        }
        
        for(auto el: s1)
        {
            if(s2.find(el)!= s2.end())
            {
                ans.push_back(el);
            }
        }
        return ans;
        
    }
};