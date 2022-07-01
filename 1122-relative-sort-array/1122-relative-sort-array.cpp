class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        
        map<int,int> frq;
        for(int i=0; i<arr1.size(); i++)
        {
            frq[arr1[i]]++;
        }
        
        int j = 0;
        for(int i=0; i<arr2.size(); i++)
        {
            while(frq[arr2[i]])
            {
                arr1[j++] = arr2[i];
                frq[arr2[i]]--;
            }
        }        
        for(auto p: frq)
        {
            for(int i=0; i<p.second; i++) arr1[j++] = p.first;
        }
        
        return arr1;
    }
};