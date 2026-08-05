class Solution {
public:
    void dfs(int u, vector<vector<int>>& adj, vector<bool>& vis) {
        vis[u] = true;
        for (int v : adj[u]) {
            if (!vis[v]) {
                dfs(v, adj, vis);
            }
        }
    }

    vector<int> remainingMethods(int n, int k,vector<vector<int>>& invocations) {
        vector<vector<int>> adj(n);

        for (auto &e : invocations) {
            adj[e[0]].push_back(e[1]);
        }

        vector<bool> vis(n, false);
        dfs(k, adj, vis);

        for (auto &e : invocations) 
        {
            int u = e[0], v = e[1];
            if (!vis[u] && vis[v]) 
            {
                vector<int> ans;
                for (int i = 0; i < n; i++) 
                ans.push_back(i);
                
                return ans;
            }
        }

        vector<int> ans;
        for (int i = 0; i < n; i++) {
            if (!vis[i])
             ans.push_back(i);
        }

        return ans;
    }
};