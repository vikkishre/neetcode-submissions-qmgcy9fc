class Solution {
public:
    void dfs(int i,int j,vector<vector<char>>&board,vector<vector<bool>>&vis)
    {
        if(i<0 || j<0 || i==board.size() || j==board[0].size() || vis[i][j])
            return;
        vis[i][j]=true;
        if(board[i][j]=='X')
            return;
        if(board[i][j]=='O')
        {
            board[i][j]='#';
            dfs(i+1,j,board,vis);
            dfs(i-1,j,board,vis);
            dfs(i,j-1,board,vis);
            dfs(i,j+1,board,vis);
        }
    }
    void solve(vector<vector<char>>& board) {
        int r=board.size();
        int c=board[0].size();
        vector<vector<bool>> vis(r,vector<bool>(c,false));
        for(int i=0;i<c;i++)
        {
            dfs(0,i,board,vis);
            dfs(r-1,i,board,vis);
        }
        for(int i=0;i<r;i++)
        {
            dfs(i,0,board,vis);
            dfs(i,c-1,board,vis);
        }
        for(int i=0;i<board.size();i++)
        {
            for(int j=0;j<board[0].size();j++)
            {
                if(board[i][j]=='O')
                    board[i][j]='X';
                if(board[i][j]=='#')
                    board[i][j]='O';
            }
        }
    }
};
