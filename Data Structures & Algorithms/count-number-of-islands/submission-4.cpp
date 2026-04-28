class Solution {
public:
    
    void dfs(int i,int j,vector<vector<int>>& visited,vector<vector<char>> &grid)
    {
        if(i<0 ||i>=grid.size()||j<0||j>=grid[0].size()|| visited[i][j] || grid[i][j]=='0')
            return;
        visited[i][j]=1;
       
            dfs(i+1,j,visited,grid);
            dfs(i-1,j,visited,grid);
            dfs(i,j+1,visited,grid);
            dfs(i,j-1,visited,grid);
        
        
       
    }
    int numIslands(vector<vector<char>>& grid) {
        int island=0;
        vector<vector<int>> visited(grid.size(),vector<int>(grid[0].size(),0));
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                if(grid[i][j]=='1' && visited[i][j]==0)
                {
                    dfs(i,j,visited,grid);
                    island++;
                }
            }
        }
        return island;
    }
};
