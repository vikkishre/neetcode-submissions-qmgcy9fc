class Solution {
public:
    void helper(vector<vector<int>>& grid,int i,int j,vector<vector<int>> &visited)
    {
        int d=0;
        queue<pair<pair<int,int>,int>> q;
        q.push({{i,j},d});
        int l,r;
        visited[i][j]=1;
        while(!q.empty())
        {
            
             l=q.front().first.first;
             r=q.front().first.second;
             int td=q.front().second;
            q.pop();
            grid[l][r]=min(grid[l][r],td);
            if(l+1>=0 && l+1<grid.size() && grid[l+1][r]!=-1 && !visited[l+1][r])
            {
                q.push({{l+1,r},td+1});
                visited[l+1][r]=1;
            }
            if(l-1>=0 && l-1<grid.size() && grid[l-1][r]!=-1 && !visited[l-1][r])
            {
                q.push({{l-1,r},td+1});
                visited[l-1][r]=1;
            }
            if(r+1>=0 && r+1<grid[0].size() && grid[l][r+1]!=-1 && !visited[l][r+1])
            {
                q.push({{l,r+1},td+1});
                visited[l][r+1]=1;
            }
            if(r-1>=0 && r-1<grid[0].size() && grid[l][r-1]!=-1 && !visited[l][r-1])
            {
                q.push({{l,r-1},td+1});
                visited[l][r-1]=1;
            }
        }

    }
    void islandsAndTreasure(vector<vector<int>>& grid) {
        vector<pair<int,int>> treasure;
        vector<vector<int>> visited(grid.size(),vector<int>(grid[0].size(),0));
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                if(grid[i][j]==0)
                    treasure.push_back({i,j});
            }
        }
        for(auto t:treasure)
        {
            int i=t.first;
            int j=t.second;
            helper(grid,i,j,visited);
            visited = vector<vector<int>>(grid.size(),
                              vector<int>(grid[0].size(),0));
        }
    }
};
