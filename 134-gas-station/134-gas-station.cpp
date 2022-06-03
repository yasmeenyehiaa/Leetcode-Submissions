class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        
        int tot = 0 , index = 0 , mn = 0;
        for(int i=0; i<gas.size(); i++)
        {
            tot += gas[i] - cost[i];
            if(tot < mn)
            {
                index = i+1;
                mn = tot;
            }   
        }
        
        if(tot >= 0)
        {
            return index;
        }
        
        else return -1;
    }
};