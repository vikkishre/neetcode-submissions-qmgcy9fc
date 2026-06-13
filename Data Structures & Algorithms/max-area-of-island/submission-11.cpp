class Solution {
public:
    int area;
    int bfs(int i,int j,vector<vector<int>>& grid,vector<vector<int>>& visited)
    {
        area=0;
        queue<pair<int,int>> q;
        q.push({i,j});
        visited[i][j]=1;
        area++;
        while(!q.empty())
        {
            int l=q.front().first;
            int r=q.front().second;
            q.pop();
            if(l+1>=0 && l+1<grid.size() && grid[l+1][r]==1 && !visited[l+1][r])
            {
                visited[l+1][r]=1;
                area++;
                q.push({l+1,r});
            }
            if(l-1>=0 && l-1<grid.size() && grid[l-1][r]==1 && !visited[l-1][r])
            {
                visited[l-1][r]=1;
                area++;
                q.push({l-1,r});
            }
            if(r+1>=0 && r+1<grid[0].size() && grid[l][r+1]==1 && !visited[l][r+1])
            {
                visited[l][r+1]=1;
                area++;
                q.push({l,r+1});
            }
            if(r-1>=0 && r-1<grid[0].size() && grid[l][r-1]==1 && !visited[l][r-1])
            {
                visited[l][r-1]=1;
                area++;
                q.push({l,r-1});
            }
            
        }
        return area;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int maxarea=0;
        int r=grid.size();
        int c=grid[0].size();
        vector<vector<int>> visited(r,vector<int>(c,0));
        for(int i=0;i<r;i++)
        {
            for(int j=0;j<c;j++)
            {
                if(grid[i][j]==1 && !visited[i][j])
                {
                    int temparea=bfs(i,j,grid,visited);
                    maxarea=max(temparea,maxarea);
                }
                
            }
        }
        return maxarea;
    }
};
