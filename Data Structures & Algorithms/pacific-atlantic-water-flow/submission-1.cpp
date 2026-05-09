class Solution {
public:
    vector<vector<bool>> pac;
vector<vector<bool>> alt;
    void dfs(int i,int j,int pH,vector<vector<int>> &heights,vector<vector<bool>>& vis)
    {
        if(i<0 || j<0 || i==heights.size()|| j==heights[0].size() || 
        vis[i][j] || heights[i][j]<pH)
            return;
        vis[i][j]=true;;
        dfs(i-1,j,heights[i][j],heights,vis);
        dfs(i,j-1,heights[i][j],heights,vis);
        dfs(i+1,j,heights[i][j],heights,vis);
        dfs(i,j+1,heights[i][j],heights,vis);
    } 
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {

       int rows=heights.size();
       int  cols=heights[0].size();
       pac = vector<vector<bool>>(rows, vector<bool>(cols,false));
        alt = vector<vector<bool>>(rows, vector<bool>(cols,false));
       for(int i=0;i<cols;i++)
       {
        dfs(0,i,heights[0][i],heights,pac);
        dfs(rows-1,i,heights[rows-1][i],heights,alt);
       }
       for(int j=0;j<rows;j++)
       {
        dfs(j,0,heights[j][0],heights,pac);
        dfs(j,cols-1,heights[j][cols-1],heights,alt);
       }
        vector<vector<int>> result;
       for(int i=0;i<heights.size();i++)
       {
        for(int j=0;j<heights[0].size();j++)
        {
            if(pac[i][j] && alt[i][j])
                result.push_back({i,j});
        }
       }
       return result;
    }
};
