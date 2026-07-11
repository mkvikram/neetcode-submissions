class Solution {
public:
    int countbit(int x)
    {

        int count=0;
        while(x)
        {
            count++;
            x=x&x-1;
        }
        
        return count;
    }
    vector<int> countBits(int n) {
        vector<int>result;
        for(int i=0;i<=n;i++)
        {
            result.push_back(countbit(i));
        }
        return result;
    }
};
