class Solution {
public:
    void travesedfs(int u,vector<vector<int>>&adj,vector<bool>&visit)
    {
        visit[u]=true;
        for(auto v:adj[u])
        {
            if(visit[v]){
                continue;
            }
            travesedfs(v,adj,visit);
        }
    }
    int countComponents(int n, vector<vector<int>>& edges) {
        int edge_count=edges.size();
       // if(edge_count==1){return 1;}

        vector<vector<int>>adj(n); // n-> number of nodes

        for(int i=0;i<edge_count;i++)
        {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        vector<bool>visited(n,false);
        
        int count=0;
        for(int i=0;i<n;i++)
        {
            if(!visited[i]){
                travesedfs(i,adj,visited);
                count++;
            }
        }
        return count;
    }
};
