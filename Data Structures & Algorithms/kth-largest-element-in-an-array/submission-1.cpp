class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        //1. sort min to high and traverse from end till kth 
        //2. priority queue

        priority_queue<int,vector<int>,greater<int>>pq;

        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            if(pq.empty()){pq.push(nums[i]);}
            else
            {               
                    pq.push(nums[i]);
            }

            if(pq.size()>k){
                pq.pop();
            }
        }
        return pq.top();
    }
};
