class Disjoint_set{
    public:
    vector<int>rank,parent;
    Disjoint_set(int size)
    {
        rank.resize(size+1,0);
        parent.resize(size+1);
        for(int i=0;i<=size;i++)
        {
            parent[i]=i;
        }
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
};
class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        int cntExtra=0;
        Disjoint_set ds(n);
        for(auto it:connections)
        {
            int u=it[0];
            int v=it[1];
            if(ds.findParent(u)==ds.findParent(v))
            {
                cntExtra++;
            }
            else{
                ds.unionSet(u,v);
            }
        }
        int cnt=0;
        for(int i=0;i<n;i++)
        {
            if(ds.parent[i]==i)
            {
                cnt++;
            }
        }
        int ans=cnt-1;
        if(cntExtra>=ans)
        {
            return ans;
        }
        else{
            return -1;
        }
    }
};