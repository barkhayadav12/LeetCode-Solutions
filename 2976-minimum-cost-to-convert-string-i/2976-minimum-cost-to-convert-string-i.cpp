class Solution {
public:
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        // building the matrix
        vector<vector<long long>>adj(26,vector<long long>(26,INT_MAX));
        for(int i=0;i<original.size();i++)
        {
            int s=original[i]-'a';
            int t=changed[i]-'a';
            adj[s][t]=min((long long)cost[i],adj[s][t]);
        }
        
        // checking shortest distance
        // apply floyd warshall
        for(int k=0;k<26;k++)
        {
            for(int i=0;i<26;i++)
            {
                for(int j=0;j<26;j++)
                {
                    adj[i][j]=min(adj[i][j],adj[i][k]+adj[k][j]);
                }
            }
        }
        
        // returning the ans by checking the shortest path
        long long ans=0;
        for(int i=0;i<source.length();i++)
        {
            // if equal, no need to change
            if(source[i]==target[i])
            {
                continue;
            }
            int s=source[i]-'a';
            int t=target[i]-'a';
            if(adj[s][t]==INT_MAX)
            {
                return -1;
            }
            ans+=adj[s][t];
        }
        return ans;
        
    }
};