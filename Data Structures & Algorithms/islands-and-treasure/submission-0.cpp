class Solution {
public:
    struct node
    {
        int crr;
        int x; 
        int y;
    };
    void bfs(int x1,int y1,vector<vector<int>>&grid,int n,int m)
    {
        queue<node>q;
        q.push({0,x1,y1});
        while(!q.empty())
        {
            node temp=q.front();
            int x=temp.x;
            int y=temp.y;
            int crr1=temp.crr;
            q.pop();

            grid[x][y]=crr1;
            // left
            int crr=INT_MAX;
            if(x-1>=0 && grid[x-1][y]!=-1 && grid[x-1][y]!=0 && grid[x-1][y]>crr1){
                crr=min(crr1+1,grid[x-1][y]);
                q.push({crr,x-1,y});
            }
            if(x+1<n && grid[x+1][y]!=-1 && grid[x+1][y]!=0 && grid[x+1][y]>crr1)
            {
                crr=min(crr1+1,grid[x+1][y]);
                q.push({crr,x+1,y});               
            }
            if(y-1>=0 && grid[x][y-1]!=-1 && grid[x][y-1]!=0 && grid[x][y-1]>crr1)
            {
                crr=min(crr1+1,grid[x][y-1]);
                q.push({crr,x,y-1});                  
            }
            if(y+1<m && grid[x][y+1]!=-1 && grid[x][y+1]!=0 && grid[x][y+1] >crr1)
            {
                crr=min(crr1+1,grid[x][y+1]);
                q.push({crr,x,y+1});                  
            }
        }
        return;
    }
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==0)
                {
                    bfs(i,j,grid,n,m);
                   // break;
                }
            }
        }
    
      
    }
    
};
