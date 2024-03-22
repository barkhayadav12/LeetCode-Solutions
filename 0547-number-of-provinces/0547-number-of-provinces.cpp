class Solution {
public:
    void dfs(int node,int vis[],vector<int>adj[])
    {
        vis[node]=1;
        for(auto it:adj[node])
        {
            if(vis[it]==0)
            {
                dfs(it,vis,adj);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        vector<int>adj[n];
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(isConnected[i][j]==1 && i!=j)
                {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        int vis[n];
        for(int i=0;i<n;i++)
        {
            vis[i]=0;
        }
        int cnt=0;
        for(int i=0;i<n;i++)
        {
            if(vis[i]==0)
            {
                cnt++;
                dfs(i,vis,adj);
            }
        }
        return cnt;
    }
};