class Solution {
public:
       void solve(vector<int>&curr,vector<vector<int>>&result,vector<int>&candiate,int t,int start)
    {
        if(t<0){return;}
        if(t==0)
        {
           result.push_back(curr);
           return;
        }
        
        for(int i=start;i<candiate.size();i++)
        {
            curr.push_back(candiate[i]);
            solve(curr,result,candiate,t-candiate[i],i); // i to stop [2 2 3] -> [2 3 2] or [3 2 2]
            curr.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        
        vector<vector<int>>result;
        vector<int>curr;
        solve(curr,result,candidates,target,0); // to make unique we need to send index i so that same combination 
        // should meet again 
        return result;
    }
};
