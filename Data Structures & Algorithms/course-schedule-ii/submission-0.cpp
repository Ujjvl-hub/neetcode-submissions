class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        
        unordered_map<int,vector<int>> adj;
        vector<int> indegree(numCourses,0);

        for(int i=0;i<prerequisites.size();i++){
            int u = prerequisites[i][0];
            int v = prerequisites[i][1];

            adj[v].push_back(u);

            indegree[u]++;
        }

        queue<int> q;
        for(int i=0;i<numCourses;i++){
            if(indegree[i]==0) q.push(i);
        }

        vector<int> res;

        while(!q.empty()){
            int node = q.front();
            q.pop();

            res.push_back(node);

            for(auto i: adj[node]){
                indegree[i]--;
                if(indegree[i]==0){
                    q.push(i);
                }
            }
        }
        if(res.size()==numCourses) return res;
        return {};
    }
};
