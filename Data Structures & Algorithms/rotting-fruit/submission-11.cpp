class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        vector<pair<int,int>> dr={{1,0},{-1,0},{0,1},{0,-1}};
        int time=0;
        int fresh=0;
        queue<pair<int,int>> q;
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                if(grid[i][j]==1)
                    fresh++;
                if(grid[i][j]==2)
                {
                    q.push({i,j});
                }
            }
        }
        while(!q.empty())
        {
            int rotten=false;
            int len=q.size();
            for(int i=0;i<len;i++)
            {
                auto it=q.front();
                q.pop();
                for(auto d:dr)
                {
                    int l=it.first+d.first;
                    int r=it.second+d.second;
                    if(l<0 || l>=grid.size() || r<0 || r>=grid[0].size())
                        continue;
                    if(grid[l][r]==1)
                    {
                        grid[l][r]=2;
                        q.push({l,r});
                        rotten=true;
                        fresh--;
                    }
                    
                }
            }
            if(rotten)
                time++;

        }
        return fresh==0?time:-1;
    }
};
