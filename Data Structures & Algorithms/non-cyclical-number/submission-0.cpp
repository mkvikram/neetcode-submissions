class Solution {
public:
    int calsum(int n)
    {
        int sum=0;
        while(n)
        {  int val=n%10;
           cout<<"val"<<val;
           sum+=val*val;
           n=n/10;
        }
        return sum;
    }
    bool isHappy(int n) {
        unordered_map<int,int>ump;
        while(true)
        {
            n=calsum(n);
            if(n==1){return true;}
            if(ump.find(n)!=ump.end())
            {
                break;
            }
            ump[n]++;
        }
        return false;
    }
};
