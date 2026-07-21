class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
            int n=hand.size();
        if(n%groupSize){ // ydi completely divisible h to 0 than group possoble h 
            return false;// 1 aaya hoga jiska mtlb group bnanaa muskil
        }

        map<int,int>mp;
        for(int i=0;i<n;i++){
            mp[hand[i]]++;
        }

        while(!mp.empty())
        {
            int curr=mp.begin()->first;

            for(int i=0;i<groupSize;i++){
                if(mp[curr+i]==0){
                   return false;
                }
                mp[curr+i]--;
                if(mp[curr+i]<1){
                    mp.erase(curr+i);
                }
            }
        }

        return true;
    }
};
