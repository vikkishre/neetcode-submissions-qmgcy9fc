class Solution {
public:
    int m, n;

    void dfs(int i, int j, vector<vector<int>>& heights,
             vector<vector<int>>& visited)
    {
        visited[i][j] = 1;

        int dx[4] = {1, -1, 0, 0};
        int dy[4] = {0, 0, 1, -1};

        for(int k = 0; k < 4; k++)
        {
            int ni = i + dx[k];
            int nj = j + dy[k];

            if(ni < 0 || ni >= m || nj < 0 || nj >= n)
                continue;

            if(visited[ni][nj])
                continue;

            // Reverse flow condition:
            // move only to equal or higher height
            if(heights[ni][nj] < heights[i][j])
                continue;

            dfs(ni, nj, heights, visited);
        }
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        m = heights.size();
        n = heights[0].size();

        vector<vector<int>> pacific(m, vector<int>(n, 0));
        vector<vector<int>> atlantic(m, vector<int>(n, 0));

        // Pacific: left column
        for(int i = 0; i < m; i++)
            dfs(i, 0, heights, pacific);

        // Pacific: top row
        for(int j = 0; j < n; j++)
            dfs(0, j, heights, pacific);

        // Atlantic: right column
        for(int i = 0; i < m; i++)
            dfs(i, n - 1, heights, atlantic);

        // Atlantic: bottom row
        for(int j = 0; j < n; j++)
            dfs(m - 1, j, heights, atlantic);

        vector<vector<int>> ans;

        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(pacific[i][j] && atlantic[i][j])
                {
                    ans.push_back({i, j});
                }
            }
        }

        return ans;
    }
};