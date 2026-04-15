class Solution {
public:
    int dfs(int i,int j,vector<vector<int>>& grid,vector<vector<int>> &visited)
    {
        if(i<0||j<0||i>=grid.size()||j>=grid[0].size()||visited[i][j]||grid[i][j]==0)
            return 0;
        //maxArea++;
        visited[i][j]=1;
      
    visited[i][j] = 1;

    return 1 +
           dfs(i-1, j, grid, visited) +
           dfs(i+1, j, grid, visited) +
           dfs(i, j+1, grid, visited) +
           dfs(i, j-1, grid, visited);
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
         vector<vector<int>> visited(grid.size(),vector<int>(grid[0].size(),0));
         int maxArea=0;
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                if(grid[i][j]==1 && !visited[i][j])
                {
                   int tempMaxArea= dfs(i,j,grid,visited);
                    maxArea=max(maxArea,tempMaxArea);
                }
            }
        }
        return maxArea;
    }
};
