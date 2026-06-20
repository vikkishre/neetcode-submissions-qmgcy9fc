class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int fresh=0;
        int time=0;
        
        queue<pair<int,int>> q;
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                if(grid[i][j]==1)
                    fresh++;
                if(grid[i][j]==2)
                    q.push({i,j});
            }
        }
        vector<pair<int,int>> directions={{1,0},{-1,0},{0,1},{0,-1}};
        while(!q.empty())
        {
            int len=q.size();
            bool rotten=false;
            for(int i=0;i<len;i++)
            {
                auto it=q.front();
                q.pop();
                for(auto d:directions)
                {
                    int l=it.first+d.first;
                    int r=it.second+d.second;
                    if(l>=0 && l<grid.size() && r>=0 && r<grid[0].size() && grid[l][r]==1)
                    {
                        grid[l][r]=2;
                        fresh--;
                        rotten=true;
                        q.push({l,r});
                    }
                }
            }
            if(rotten)
                time++;
        }
        return fresh==0?time:-1;
    }
    
};
