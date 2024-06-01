class Disjoint_set{
    public:
    vector<int>rank,parent,size;
    Disjoint_set(int n)
    {
        rank.resize(n+1,0);
        parent.resize(n+1);
        for(int i=0;i<=n;i++)
        {
            parent[i]=i;
        }
        size.resize(n+1,1);
    }
    int findParent(int u)
    {
        if(u==parent[u])
        {
            return u;
        }
        return parent[u]=findParent(parent[u]);
    }
    void unionSet(int u,int v)
    {
        int ulp_u=findParent(u);
        int ulp_v=findParent(v);
        if(ulp_u==ulp_v)
        {
            return;
        }
        if(rank[ulp_u]>rank[ulp_v])
        {
            parent[ulp_v]=ulp_u;
        }
        else if(rank[ulp_u]<rank[ulp_v])
        {
            parent[ulp_u]=ulp_v;
        }
        else{
            parent[ulp_u]=ulp_v;
            rank[ulp_v]++;
        }
    }
    void unionBySize(int u,int v)
    {
        int ulp_u=findParent(u);
        int ulp_v=findParent(v);
        if(ulp_u==ulp_v)
        {
            return;
        }
        if(size[ulp_u]>size[ulp_v])
        {
            parent[ulp_v]=ulp_u;
            size[ulp_u]+=size[ulp_v];
        }
        else{
            parent[ulp_u]=ulp_v;
            size[ulp_v]+=size[ulp_u];
        }
    }
};
class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        Disjoint_set ds(n*n);
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                
                if(grid[i][j]==0)
                {
                    continue;
                }
                if(grid[i][j]==1)
                {
                    int delRow[4]={-1,0,1,0};
                    int delCol[4]={0,1,0,-1};
                    for(int k=0;k<4;k++)
                    {
                        int newr=i+delRow[k];
                        int newc=j+delCol[k];
                        if(newr>=0 && newr<n && newc>=0 && newc<n){
                        if(grid[newr][newc]==1)
                        {
                            int u=(i*n)+j;
                            int v=(newr*n)+newc;
                            ds.unionBySize(u,v);
                        }
                        }
                    }
                }
            }
        }
        int maxi=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==1)
                {
                    continue;
                }
                set<int>components;
                if(grid[i][j]==0)
                {
                    int delRow[4]={-1,0,1,0};
                    int delCol[4]={0,1,0,-1};
                    for(int k=0;k<4;k++)
                    {
                        int newr=i+delRow[k];
                        int newc=j+delCol[k];
                        if(newr>=0 && newr<n && newc>=0 && newc<n){
                        if(grid[newr][newc]==1)
                        {
                            components.insert(ds.findParent(newr*n+newc));
                        }
                        }
                    }
                }
                int cnt=0;
                for(auto it:components)
                {
                    cnt+=ds.size[it];
                }
                maxi=max(cnt+1,maxi);
            }
        }
        for(int i=0;i<n*n;i++)
        {
            maxi=max(maxi,ds.size[ds.findParent(i)]);
        }
        return maxi;
    }
    
};