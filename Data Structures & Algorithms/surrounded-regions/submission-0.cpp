class Solution {
    vector<int> x = {-1,1,0,0};
    vector<int> y = {0,0,-1,1};

private: 
    bool isValid(int i,int j,int n, int m){
        if(i<0 || i>=n || j<0 || j>=m) return false;
        return true;
    }

    void dfs(int i,int j,int n,int m, vector<vector<bool>> &visited, vector<vector<char>> &board){
        visited[i][j] = true;
        board[i][j] = 'T';

        for(int k=0;k<4;k++){
            int r = i + x[k];
            int c = j + y[k];

            if(isValid(r,c,n,m) && !visited[r][c] && board[r][c]=='O'){
                dfs(r,c,n,m,visited,board);
            }
        }
    }
public:
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();

        vector<vector<bool>> visited(n,vector<bool>(m,false));

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i==0 || i==n-1 || j==0 || j==m-1){
                    if(!visited[i][j] && board[i][j]=='O'){
                        dfs(i,j,n,m,visited,board);
                    }
                }
            }
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]=='T'){
                    board[i][j] = 'O';
                }else board[i][j]='X';
            }
        }
        
    }
};
