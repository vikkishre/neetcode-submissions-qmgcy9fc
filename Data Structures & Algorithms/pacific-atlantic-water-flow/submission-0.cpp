class Solution {
public:
    int m, n;

    vector<vector<int>> dir = {
        {1,0}, {-1,0}, {0,1}, {0,-1}
    };

    void dfs(int i, int j,
             vector<vector<int>>& heights,
             vector<vector<bool>>& vis)
    {
        vis[i][j] = true;

        for(auto &d : dir)
        {
            int ni = i + d[0];
            int nj = j + d[1];

            if(ni < 0 || nj < 0 || ni >= m || nj >= n)
                continue;

            if(vis[ni][nj])
                continue;

            // reverse flow condition
            if(heights[ni][nj] >= heights[i][j])
            {
                dfs(ni, nj, heights, vis);
            }
        }
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights)
    {
        m = heights.size();
        n = heights[0].size();

        vector<vector<bool>> pac(m, vector<bool>(n, false));
        vector<vector<bool>> atl(m, vector<bool>(n, false));

        // Pacific
        for(int i = 0; i < m; i++)
            dfs(i, 0, heights, pac);

        for(int j = 0; j < n; j++)
            dfs(0, j, heights, pac);

        // Atlantic
        for(int i = 0; i < m; i++)
            dfs(i, n-1, heights, atl);

        for(int j = 0; j < n; j++)
            dfs(m-1, j, heights, atl);

        vector<vector<int>> res;

        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(pac[i][j] && atl[i][j])
                {
                    res.push_back({i, j});
                }
            }
        }

        return res;
    }
};