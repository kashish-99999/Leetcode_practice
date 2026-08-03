class Solution {
public:
    vector<int> parent;

    int find(int x) {
        if (parent[x] == x) return x;
        return parent[x] = find(parent[x]);
    }

    void unite(int x, int y) {
        int px = find(x);
        int py = find(y);

        if (px != py) {
            parent[py] = px;
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        parent.resize(n);

        for (int i = 0; i < n; i++)
            parent[i] = i;

        int provinces = n;

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (isConnected[i][j] == 1) {
                    int pi = find(i);
                    int pj = find(j);

                    if (pi != pj) {
                        unite(i, j);
                        provinces--;
                    }
                }
            }
        }

        return provinces;
    }
};