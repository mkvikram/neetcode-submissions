class Solution {
public:
    bool checkcycle(vector<vector<int>>& adj,int u,int parent,vector<bool>&visit)
    {
        visit[u]=true;
        for(auto v:adj[u]){
           if(v==parent){continue;}// 0 --> 1 or 1--->0 is not a cycle it just path
           if(visit[v]){return true; // this alreday visited it means cycle
           }
           if(checkcycle(adj,v,u,visit)){
            return true; // khi pe bhi ydi visited hai to return ture kr do
           }
        }
        return false; // cycle nhi mila
    }
    bool validTree(int n, vector<vector<int>>& edges) {

        if(edges.empty()){return true;}
        // 1. constion : for making tree these always should be n-1 edage in n nodes
        // it means its making if edage.size is equal to n it means their should be one
        // cycle available so we can return from here only

        int edge_count=edges.size();
        if(edge_count!=n-1){return false;} // it should be always be equal

        // 2. check cycle if their is cycle than return false
        // for cycle first we need adjency list
        // kiyo cycle: ho skta h edage se count se km mai bhi cycle ho isliye

        cout<<"part1"<<endl;
        vector<vector<int>>adj(n);// it should as equal to nodes
        for(int i=0;i<edge_count;i++)
        {
           adj[edges[i][0]].push_back(edges[i][1]);
           adj[edges[i][1]].push_back(edges[i][0]);
        }
        
        vector<bool>visited(n,false);
        if(checkcycle(adj,edges[0][0],-1,visited)){return false;}
        cout<<"part2"<<endl;
        //3. condition: check all visited or not if not it means all nodes were not
        // connected so it will not make tree

        for(int i=0;i<n;i++)
        {
            if(!visited[i]){
                return false; // not connected, connected hota to visit ho gya hota 
            }
        }
        cout<<"part3"<<endl;
        return true; // iska mtlb ye nodes tree bna skta h 
    }
};
