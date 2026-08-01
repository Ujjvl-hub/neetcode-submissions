class Solution {
private:
    int solve(int i, int n, int free, vector<int> &nums,vector<vector<int>>& dp){
        if(i==n) return 0;

        if(dp[i][free]!=-1) return dp[i][free];

        if(free==0) return dp[i][free] = solve(i+1,n,1,nums,dp);

        int c1 = nums[i] + solve(i+1,n,0,nums,dp);
        int c2 = solve(i+1,n,1,nums,dp);
        return dp[i][free] = max(c1,c2);
    }
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n,vector<int>(2,-1));
        return solve(0,n,1,nums,dp);
    }
};
