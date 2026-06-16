class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        queue<pair<int,int>> q;
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                if(grid[i][j]==0)
                    q.push({i,j});
            }
        }
        vector<pair<int,int>> d={{1,0},{-1,0},{0,1},{0,-1}};
        while(!q.empty())
        {
            int i=q.front().first;
            int j=q.front().second;
            q.pop();
            for(auto t:d)
            {
                int r=i+t.first;
                int c=j+t.second;
                if(r<0 || c<0 || r>=grid.size() || c>=grid[0].size() || grid[r][c] != INT_MAX)
                    continue;
                grid[r][c]=grid[i][j]+1;
                q.push({r,c});
            }
        }
    }
};
