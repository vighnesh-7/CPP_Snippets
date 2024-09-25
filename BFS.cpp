class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {

        bool vis[V]={false};
        queue<int > q;
        q.push(0);
        vector<int > bfs;
        
        while(!q.empty())
        {
            int curr=q.front() ;
            q.pop();
            if(!vis[curr])
            {
                    
                vis[curr]=true;
                bfs.push_back(curr);
                
                for(auto itr:adj[curr])
                {
                    if(!vis[itr])
                    {
                        q.push(itr);
                    }
                }
            }
        }
        
        return bfs;
        
        
    }
};
