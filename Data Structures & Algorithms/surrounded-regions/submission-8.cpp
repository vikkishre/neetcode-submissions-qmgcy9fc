class Solution {
public:
    void dfs(int i,int j,vector<vector<char>> &board,vector<vector<int>> &visited)
    {
        if(i<0 || i>=board.size() || j<0 || j>=board[0].size()|| visited[i][j])
            return;
        visited[i][j]=1;
        if(board[i][j]=='O')
            board[i][j]='A';
        else
            return;
        dfs(i+1,j,board,visited);
        dfs(i-1,j,board,visited);
        dfs(i,j+1,board,visited);
        dfs(i,j-1,board,visited);
    }
    void solve(vector<vector<char>>& board) {
        int r=board.size();
        int c=board[0].size();
        vector<pair<int,int>> sC;
        vector<vector<int>> visited(r,vector<int>(c,0));
        for(int i=0;i<r;i++)
        {
            if(board[i][0]=='O')
                sC.push_back({i,0});
        }
        for(int i=0;i<r;i++)
        {
            if(board[i][c-1]=='O')
                sC.push_back({i,c-1});
        }
        for(int i=0;i<c;i++)
        {
            if(board[0][i]=='O')
                sC.push_back({0,i});
        }
        for(int i=0;i<c;i++)
        {
            if(board[r-1][i]=='O')
                sC.push_back({r-1,i});
        }
        for(auto s:sC)
        {
            dfs(s.first,s.second,board,visited);
        }
        for(int i=0;i<r;i++)
        {
            for(int j=0;j<c;j++)
            {
                if(board[i][j]=='O')
                    board[i][j]='X';
                else if(board[i][j]=='A')
                    board[i][j]='O';
            }
        }
    }
};
