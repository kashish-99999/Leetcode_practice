class Solution {
public:

     vector<int> parent;
    int find(int u)
    {
        if(parent[u]<0)
        {
           return u;
        }

        return parent[u]=find(parent[u]);
    }

    void union1(int u,int v)
    {
        int p1=find(u);
        int p2=find(v);

        if(p1==p2)  return;

        if(abs(parent[p1]) < abs(parent[p2]))
        {            
            parent[p2] += parent[p1];
            parent[p1] = p2;
            }
        else        
        {
            parent[p1] += parent[p2];
            parent[p2] = p1;
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int nr=grid.size();
        int nc=grid[0].size();

        parent.assign(nr*nc,-1);

        int c=0;
        for(int i=0;i<nr;i++)
        {
            for(int j=0;j<nc;j++)
            {
                if(grid[i][j]=='1')
                c++;
            }
        }

        int arr[2][2]={{1,0},{0,1}};
         for(int i=0;i<nr;i++)
        {
            for(int j=0;j<nc;j++)
            {
                if(grid[i][j]=='0') continue;

                int cur=i*nc+j;

                for(auto &d:arr)
                {
                    int ni=i+d[0];
                    int nj=j+d[1];

                    if(ni<nr && nj<nc  && grid[ni][nj]=='1')
                    {
                        int next=ni*nc+nj;

                        if(find(cur) !=find(next))
                        {
                            union1(cur,next);
                            c--;
                        }
                    }
                }
            }
        }

        return c;
    }
};