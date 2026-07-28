class Solution {
    vector<int> x = {-1,1,0,0};
    vector<int> y = {0,0,-1,1};

private:
    bool isValid(int i,int j ,int n, int m){
        if(i<0 || i>=n || j<0 || j>=m) return false;
        return true;
    }

    void dfs(int i,int j,int n, int m, vector<vector<bool>>& visited,vector<vector<int>>& grid,int &count){
        visited[i][j]= true;
        count++;

        for(int k=0;k<4;k++){
            int r = i + x[k];
            int c = j + y[k];

            if(isValid(r,c,n,m) && !visited[r][c] && grid[r][c]==1){
                dfs(r,c,n,m,visited,grid,count);
            }
        }
    }
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<bool>> visited(n,vector<bool>(m,false));
        int maxi = 0;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!visited[i][j] && grid[i][j]==1){
                    int count=0;
                    dfs(i,j,n,m,visited,grid,count);
                    maxi = max(maxi,count);
                }
            }
        }
        return maxi;

    }
};
