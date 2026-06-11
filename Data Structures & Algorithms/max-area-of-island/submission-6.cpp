class Solution {
public:
    int area=0;
    vector<vector<int>> visited;
    int dfs(int i,int j,vector<vector<int>> &grid,vector<vector<int>> &visited)
    {
        if(i<0||i>=grid.size()||j<0||j>=grid[0].size()||grid[i][j]==0||visited[i][j])
            return 0;
        visited[i][j]=1;
        area++;
        dfs(i+1,j,grid,visited);
        dfs(i-1,j,grid,visited);
        dfs(i,j+1,grid,visited);
        dfs(i,j-1,grid,visited);
        return area;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int r=grid.size();
        int c=grid[0].size();
        int maxArea=0;
        visited.resize(r,vector<int>(c,0));
        for(int i=0;i<r;i++)
        {
            for(int j=0;j<c;j++)
            {
                if(grid[i][j]==1 && !visited[i][j])
                {
                   int temparea= dfs(i,j,grid,visited);
                   area=0;
                   maxArea=max(maxArea,temparea);
                }
            }
        }
        return maxArea;
    }
};
