class Solution {
    vector<int> x = {-1,1,0,0};
    vector<int> y = {0,0,-1,1};

private:
    bool isValid(int i,int j, int n, int m){
        if(i<0 || i>=n || j<0 || j>=m) return false;
        return true;
    }

public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        int freshCount=0;
        int time=0;

        queue<pair<int,int>> q;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                    q.push({i,j});
                }
                else if(grid[i][j]==1) freshCount++;
            }
        }

        while(!q.empty() && freshCount>0){
            time++;
            int size = q.size();

            while(size--){
                pair<int,int> p = q.front();
                q.pop();

                int row = p.first;
                int col = p.second;

                for(int k=0;k<4;k++){
                    int r = row+ x[k];
                    int c = col + y[k];

                    if(isValid(r,c,n,m) && grid[r][c]==1){
                        q.push({r,c});
                        grid[r][c] = 2;
                        freshCount--;
                    }
                }
            }
        }

        if(freshCount>0) return -1;
        return time;
    }
};
