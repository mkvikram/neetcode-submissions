class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
          int n=triplets.size();

         vector<int>initial={0,0,0};
         for(int i=0;i<n;i++){
            if(triplets[i][0]<=target[0] &&
               triplets[i][1]<=target[1] &&
               triplets[i][2]<=target[2]){
               
               initial[0]=max(initial[0],triplets[i][0]);
               initial[1]=max(initial[1],triplets[i][1]);
               initial[2]=max(initial[2],triplets[i][2]);
            }
            if(initial==target){
                return true;
            }
         }
         return false;
    }
};
