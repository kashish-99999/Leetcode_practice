class Solution {
public:
    vector<int> parent;

    int find(int x) {
        if (parent[x] == x) return x;
        return parent[x] = find(parent[x]);
    }

    void unite(int a, int b) {
        parent[find(a)] = find(b);
    }

    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        parent.resize(n);

        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }

        for (auto& edge : edges) {
            unite(edge[0], edge[1]);
        }

        return find(source) == find(destination);
    }
};