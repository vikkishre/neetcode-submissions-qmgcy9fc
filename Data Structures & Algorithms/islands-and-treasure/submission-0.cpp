class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        queue<pair<int,int>> q;
        
        // Step 1: Push all gates (0s) into queue
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 0) {
                    q.push({i, j});
                }
            }
        }
        
        // Directions (up, down, left, right)
        vector<pair<int,int>> dir = {{-1,0}, {1,0}, {0,-1}, {0,1}};
        
        // Step 2: BFS
        while(!q.empty()) {
            auto [x, y] = q.front();
            q.pop();
            
            for(auto d : dir) {
                int nx = x + d.first;
                int ny = y + d.second;
                
                // Valid cell and not visited yet (INF)
                if(nx >= 0 && ny >= 0 && nx < m && ny < n && grid[nx][ny] == INT_MAX) {
                    grid[nx][ny] = grid[x][y] + 1;
                    q.push({nx, ny});
                }
            }
        }
    }
};