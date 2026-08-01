class Solution {
public:
vector<int> parent;
vector<int> arr;
int find(int x)
{
    if(parent[x]!=x)
    parent[x]=find(parent[x]);

    return parent[x];
}

void union1(int a,int b)
{
    int pu=find(a);
    int pv=find(b);

    if(pu==pv)
    return;

    if(arr[pu]<arr[pv])
    {
        parent[pu]=pv;
    }
    else if(arr[pu]>arr[pv])
    {
        parent[pv]=pu;
    }
    else
    {
        parent[pv]=pu;
        arr[pu]++;
    }
}

    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        parent.resize(n);
        arr.assign(n,0);

        for(int i=0;i<n;i++)
        parent[i]=i;

        for(int u=0;u<n;u++)
        {
            for(int v:graph[u])
            {
                if(find(u)==find(v))
                return false;

                union1(graph[u][0],v);
            }
        }

        return true;
    }
};