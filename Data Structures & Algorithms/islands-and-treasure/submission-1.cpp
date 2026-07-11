class Solution {
public:
 /*   struct node
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
    }*/

    void islandsAndTreasure(vector<vector<int>>& grid) {
      if (grid.empty()) return;
        
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<int, int>> q;

        // Step 1: Saare treasures (0) ko ek saath queue mein daalo
        // Isi wajah se ise "Multi-source BFS" kehte hain
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 0) {
                    q.push({i, j});
                }
            }
        }

        // Direction arrays (Up, Down, Left, Right)
        int dx[] = {-1, 1, 0, 0};
        int dy[] = {0, 0, -1, 1};

        // Step 2: Multi-source BFS start karo
        while (!q.empty()) {
            pair<int, int> curr = q.front();
            q.pop();
            
            int x = curr.first;
            int y = curr.second;

            // 4 directions mein check karo
            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];

                // Agar valid cell hai aur wo 'INF' (2147483647) hai
                // (Yaani wo abhi tak visit nahi hua hai)
                if (nx >= 0 && nx < n && ny >= 0 && ny < m && grid[nx][ny] == 2147483647) {
                    // Shortest distance update karo
                    grid[nx][ny] = grid[x][y] + 1;
                    // Queue mein daalo taaki uske neighbors process ho sakein
                    q.push({nx, ny});
                }
            }
        }   
      
    }
    
};
