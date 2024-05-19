class Solution {
    private:
        bool bfs(vector<vector<int>>&graph,int color[],int node)
        {
                queue<int>q;
                q.push(node);
                color[node]=1;
        while(!q.empty())
        {
            int node=q.front();
            q.pop();
            for(auto it:graph[node])
            {
                if(color[it]==-1)
                {
                    color[it]=!color[node];
                    q.push(it);
                }
                else if(color[node]==color[it])
                {
                    return false;
                }
            }
            
        }
        return true;
        }
public:
        
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        int m=graph[0].size();
        int color[n];
        for(int i=0;i<n;i++)
        {
            color[i]=-1;
        }
        for(int i=0;i<n;i++)
        {
            if(color[i]==-1)
            {
                if(bfs(graph,color,i)==false)
                {
                    return false;
                }
            }
        }
        return true;
        
    }
};