class Solution {
public:
    vector<pair<int,int>> v;

    int dfs(vector<vector<int>>& grid, int i, int j,
            vector<pair<int,int>>& next)
    {
        int rotten = 0;

        int dx[4] = {-1,1,0,0};
        int dy[4] = {0,0,-1,1};

        for(int k=0;k<4;k++)
        {
            int ni = i + dx[k];
            int nj = j + dy[k];

            if(ni>=0 && ni<grid.size() &&
               nj>=0 && nj<grid[0].size() &&
               grid[ni][nj]==1)
            {
                grid[ni][nj]=2;
                rotten++;
                next.push_back({ni,nj});
            }
        }

        return rotten;
    }

    int orangesRotting(vector<vector<int>>& grid) {

        int fruits = 0;

        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                if(grid[i][j]==2)
                    v.push_back({i,j});

                if(grid[i][j]==1)
                    fruits++;
            }
        }

        int minutes = 0;

        while(fruits > 0)
        {
            vector<pair<int,int>> next;
            int rotten = 0;

            for(int i=0;i<v.size();i++)
            {
                rotten += dfs(grid,
                              v[i].first,
                              v[i].second,
                              next);
            }

            if(rotten == 0)
                return -1;

            fruits -= rotten;

            v = next;

            minutes++;
        }

        return minutes;
    }
};