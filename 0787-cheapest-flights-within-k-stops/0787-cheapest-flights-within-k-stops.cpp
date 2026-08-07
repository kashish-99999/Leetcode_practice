class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights,
                          int src, int dst, int k) {

        vector<vector<pair<int,int>>> adj(n);

        for (auto &f : flights) 
        {
            adj[f[0]].push_back({f[1], f[2]});
        }

        vector<int> cost(n, INT_MAX);
        queue<pair<int,int>> q;

        q.push({src, 0});
        cost[src] = 0;

        int stops = 0;

        while (!q.empty() && stops <= k) 
        {
            int sz = q.size();

            vector<int> temp = cost;

            while (sz--) 
            {
                auto [node, currCost] = q.front();
                q.pop();

                for (auto &[next, price] : adj[node]) 
                {
                    if (currCost + price < temp[next]) 
                    {
                        temp[next] = currCost + price;
                        q.push({next, temp[next]});
                    }
                }
            }

            cost = temp;
            stops++;
        }
if (cost[dst] == INT_MAX) {
    return -1;
}

return cost[dst];
    }
};