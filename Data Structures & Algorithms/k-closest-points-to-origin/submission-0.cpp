class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
              int n=points.size();
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq; // min at top;
        for(int i=0;i<n;i++)
        {
            int dist=points[i][0]*points[i][0] + points[i][1]*points[i][1];
           // int sqval=sqrt(dist);
           // cout<<"DIS:"<<dist<<" "<<"SQR:"<<sqval<<endl;
            pq.push({dist,i});
        }
        vector<vector<int>>result;
        for(int i=0;i<k;i++)
        {
            pair<int,int>temp=pq.top();
            cout<<temp.first<<" ";
            result.push_back(points[temp.second]);
            pq.pop();            
        }
        return result;
    }
};
