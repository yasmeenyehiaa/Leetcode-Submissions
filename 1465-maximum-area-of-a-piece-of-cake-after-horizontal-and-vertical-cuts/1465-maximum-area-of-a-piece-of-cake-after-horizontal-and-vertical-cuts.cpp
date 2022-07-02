class Solution {
public:
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) 
    {                  
        horizontalCuts.push_back(0);
        horizontalCuts.push_back(h);
        verticalCuts.push_back(0);        
        verticalCuts.push_back(w);
        
        sort(horizontalCuts.begin(), horizontalCuts.end());
        sort(verticalCuts.begin(), verticalCuts.end());
        
        int maxHeight = 0, maxWidth = 0, mod = 1e9+7;    
        
        for(int i=1; i<horizontalCuts.size(); i++)
        {
            maxHeight = max(maxHeight, horizontalCuts[i]-horizontalCuts[i-1]);
        }
        for(int i=1; i<verticalCuts.size(); i++)
        {
            maxWidth = max(maxWidth, verticalCuts[i]-verticalCuts[i-1]);
        }            
        
        return (1LL*maxHeight*maxWidth) % mod;
    }
};