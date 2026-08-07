class Solution {
private:
    void makeParent(vector<int> &parent, int n){
        for(int i=0;i<n;i++){
            parent[i] = i;
        }
    }

    int findParent(vector<int> &parent, int node){
        if(parent[node] == node) return node;
        return parent[node] = findParent(parent,parent[node]);
    }

    void makeUnion(int u, int v, vector<int> &parent, vector<int> &rank){
        u = findParent(parent,u);
        v = findParent(parent,v);

        if(rank[u]<rank[v]){
            parent[u] = v;
        }
        else if(rank[u]> rank[v]){
            parent[v] = u;
        }
        else{
            parent[v] = u;
            rank[u]++;
        }
    }
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int> parent(n+1);
        makeParent(parent,n+1);

        vector<int> rank(n+1,0);
        vector<int> res;
        for(int i=0;i<edges.size();i++){
            int u = edges[i][0];
            int v = edges[i][1];

            int pu = findParent(parent,u);
            int pv = findParent(parent,v);

            if(pu==pv){
                res.push_back(u);
                res.push_back(v);
            }else{
                makeUnion(u,v,parent,rank);
            }

        }
        return res;
    }
};
