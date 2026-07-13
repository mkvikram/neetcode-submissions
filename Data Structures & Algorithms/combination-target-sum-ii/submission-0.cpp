class Solution {
public:
   /* vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        
    }*/
    void solve(vector<int>&curr,vector<vector<int>>&result,vector<int>&candiate,int t,int start)
    {

        //if(t<0){return;} kiyo hmne phle hi candidates[i] > t) break 
        // ho gya mtlb bda value jayega hi nhi jo negative dega
        if(t==0)
        {
           result.push_back(curr);
           return;
        }
        
   
        for(int i=start;i<candiate.size();i++)
        {
                 // DUPLICATE SKIP KA MAGIC:
            if (i > start && candiate[i] == candiate[i-1]) continue;             
            if (candiate[i] > t) break; // Optimized: aage ke sab bade honge

            curr.push_back(candiate[i]);
            solve(curr,result,candiate,t-candiate[i],i+1); // i to stop [2 2 3] -> [2 3 2] or [3 2 2]
            curr.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end()); //
        // sort krne se sara similar ak sath hojayega ans i ==i-1 se hm skip kr skte 
        // skip kr skte hai
        vector<vector<int>>result;
        vector<int>curr;
        solve(curr,result,candidates,target,0); // to make unique we need to send index i so that same combination 
        // should meet again 
        return result;
    }
};
