class Solution {
private:
    void dfs(int node,unordered_map<int,bool> &visited,unordered_map<int,vector<int>>& adj){
        visited[node] =true;

        for(auto i: adj[node]){
            if(!visited[i]){
                dfs(i,visited,adj);
            }
        }
    }
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        int m = edges[0].size();
        unordered_map<int,vector<int>> adj;
        for(int i=0;i<edges.size();i++){
            int u = edges[i][0];
            int v = edges[i][1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        unordered_map<int,bool> visited(false);
        int count=0;
        for(int i=0;i<n;i++){
            if(!visited[i]){
                count++;
                dfs(i,visited,adj);
            }
        }
        return count;
    }
};
