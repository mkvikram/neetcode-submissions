class Solution {
public:
    int jump(vector<int>& nums) {
           int n=nums.size();
        int maxreach=0;
        int jump=0;
        int jump_required=0;
        for(int i=0;i<n-1;i++) // n-1 isliye ki ye fix h ki last index pe jump nhi lena h and 
        {                      // ydi last jump n-1-1 pe khatam ho rah h0ga to wo apne aap jump le lega last 
                               // index ke liye isliye n-2 is fine
           maxreach=max(maxreach,nums[i]+i);
           if(i==jump_required){
              jump++;
              jump_required=maxreach; // iska mtlb huaa ki maxreach tk jump krne ka jrurat nhi prega
           }
        } 
        return jump;

/*       vector<int>mareachsum(n);
       //map<int,int>mareachsum;
        for(int i=0;i<n;i++){
            mareachsum[i]=nums[i]+i;
            cout<<mareachsum[i]<<" "<<endl;
        }

        int low=0;
        int high=n-1;
        int ans=n;
        while(low<high)
        {
            int mid=(low+high)/2;
           // auto it=find(mareachsum.begin(),mareachsum.end(),mid);
           auto it=lower_bound(mareachsum.begin(),mareachsum.end(),mid);
            if(it!=mareachsum.end()){
                high=mid-1;
                ans=mid;
                cout<<"ans:"<<ans<<endl;
            }
            else
            {
                low=mid+1;
            }
        }
        return ans;*/ 
    }
};
