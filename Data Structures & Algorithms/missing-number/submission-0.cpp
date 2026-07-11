class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int xor1=0;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            xor1=xor1^nums[i]^i;
            cout<<xor1<<endl;
           // xor1^=nums[i];
        }
        xor1=xor1^n;
        return xor1;
    }
};
