class Solution {
public:
    
    int count=0;
    int numIslands(vector<vector<char>>& grid) {
        int rows=grid.size();
        int cols=grid[0].size();
        vector<vector<bool>> visited(grid.size(),vector<bool>(grid[0].size(),false));
        for(int i=0;i<rows;i++)
        {
            for(int j=0;j<cols;j++)
            {
                if(grid[i][j]=='1' && !visited[i][j])
                {
                    dfs(i,j,visited,grid);
                    count++;
                }
            }
        }
        return count;
    }
    void dfs(int i,int j,vector<vector<bool>> &visited,vector<vector<char>> &grid)
    {
        if(i<0 || j<0||i>=grid.size()|| j>=grid[0].size()||visited[i][j]||grid[i][j]!='1')
        {
            return;
        }
        visited[i][j]=true;
        dfs(i+1,j,visited,grid);
        dfs(i-1,j,visited,grid);
        dfs(i,j+1,visited,grid);
        dfs(i,j-1,visited,grid);
    }
};
