class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        
        vector<int>result;
        int carry=1;
        int n=digits.size()-1;
        int val=0;
        while(n>=0)
        {
           val=digits[n]+carry;
           carry=val/10;
           result.insert(result.begin(),val%10);
           n--;
        }
        if(carry!=0){result.insert(result.begin(),carry);
        }
        return result;
    }
};
