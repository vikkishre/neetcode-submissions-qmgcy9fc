class Solution {
public:
    vector<pair<int,int>> directions={{1,0},{-1,0},{0,1},{0,-1}};
    void dfs(int i,int j,vector<vector<int>> &heights,vector<vector<int>> &visited)
    {
        if(i<0 || i>=heights.size() || j<0 || j>=heights[0].size() || visited[i][j])
            return;
        visited[i][j]=1;
        for(int k=0;k<4;k++)
        {
            int di=directions[k].first;
            int dj=directions[k].second;
            int ti=i+di;
            int tj=j+dj;
            if(ti>=0 && ti<heights.size() && tj>=0 && tj<heights[0].size())
            {
                if(heights[i][j]<=heights[ti][tj])
                {
                    
                    dfs(ti,tj,heights,visited);
                }
            }
                
        }
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int r=heights.size();
        int c=heights[0].size();
        vector<vector<int>> pacific(r,vector<int>(c,0));
        vector<vector<int>> atlantic(r,vector<int>(c,0));
        for(int i=0;i<r;i++)
        {
            dfs(i,0,heights,pacific);
        }
        for(int i=0;i<c;i++)
        {
            dfs(0,i,heights,pacific);

        }
        for(int i=0;i<r;i++)
        {
            dfs(i,c-1,heights,atlantic);
        }
        for(int i=0;i<c;i++)
        {
            dfs(r-1,i,heights,atlantic);
        }
        vector<vector<int>> result;
        for(int i=0;i<r;i++)
        {
            for(int j=0;j<c;j++)
            {
                if(pacific[i][j] && atlantic[i][j])
                    result.push_back({i,j});
            }
        }
        return result;
    }
};
