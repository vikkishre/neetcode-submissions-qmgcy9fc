class Solution {
public:
    vector<pair<int,int>> q;
    
    void helper(int i,int j,vector<vector<int>> &grid,int val)
    {
       if(i<0 || i>=grid.size() || j<0 || j>=grid[0].size())
            return;
        if(grid[i][j]==1)
            return;
        if(val>grid[i][j])
            return;
        grid[i][j]=min(grid[i][j],val);
        helper(i+1,j,grid,val+1);
        helper(i-1,j,grid,val+1);
        helper(i,j+1,grid,val+1);
        helper(i,j-1,grid,val+1);
    }
    void islandsAndTreasure(vector<vector<int>>& grid) {
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                if(grid[i][j]==0)
                    q.push_back({i,j});
            }
        }
        //vector<pair<int,int>> d={{1,0},{-1,0},{0,1},{0,-1}};
        for(auto p:q)
        {
            int i=p.first;
            int j=p.second;
            helper(i,j,grid,0);
        }
        
    }
};
