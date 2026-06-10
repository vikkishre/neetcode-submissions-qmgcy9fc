class Solution {
public:
    vector<vector<int>> visited;
    void bfs(int i,int j,vector<vector<char>> &grid,vector<vector<int>> &visited)
    {
        queue<pair<int,int>> q;
        q.push({i,j});
        visited[i][j]=1;
        while(!q.empty())
        {
            int row=q.front().first;
            int col=q.front().second;
            q.pop();
            if(row+1>=0 && row+1<grid.size() && col<grid[0].size()&&col>=0 && grid[row+1][col]=='1' && !visited[row+1][col])
            {
                q.push({row+1,col});
                visited[row+1][col]=1;
            }
                
            if(row-1>=0 && row-1<grid.size() && col<grid[0].size() && col>=0 && grid[row-1][col]=='1' && !visited[row-1][col])
            {
                q.push({row-1,col});
                visited[row-1][col]=1;
            }
                
            if(row>=0 && row<grid.size() && col+1<grid[0].size()&& col+1>=0&& grid[row][col+1]=='1' && !visited[row][col+1])
            {
                q.push({row,col+1});
                visited[row][col+1]=1;
            }
                
            if(row>=0 && row<grid.size() && col-1<grid[0].size() && col-1>=0 && grid[row][col-1]=='1' && !visited[row][col-1])
            {
                q.push({row,col-1});
                visited[row][col-1]=1;
            }
                

        }
        
    }
    int numIslands(vector<vector<char>>& grid) {
        int count=0;
        visited.resize(grid.size(),vector<int>(grid[0].size(),0));
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                if(grid[i][j]=='1' && !visited[i][j])
                {
                    count++;
                    bfs(i,j,grid,visited);
                }
            }
        }
        return count;
    }
};
