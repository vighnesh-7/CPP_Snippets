//DFS
   bool detectCycle(bool vis[],int src,int par,vector<int> adj[] )
   {
        vis[src]=true;
        for(auto itr:adj[src])
        {
            if(!vis[itr])
            {
                vis[itr]=true;
                if( detectCycle(vis,itr,src,adj) == true) return true;
            }
            else if( itr!=par ){
                return true;
            }
        }
        
        return false;
   }
   
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        bool vis[V] = {false};
        

        for(int i=0;i<V;i++)
        {

            if(!vis[i])
            {
                if(detectCycle(vis,i,-1,adj)){
                    return 1;
                }
            }

        }
        return 0;
    }


// ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//BFS

   bool detectCycle(bool vis[],int src,vector<int> adj[] )
   {
        queue<pair<int,int>> q ;
        
        q.push({src,-1});
        vis[src] = true; 
        
        while(!q.empty())
        {
            int curr = q.front().first;
            int prev = q.front().second;
            
            q.pop();
            
            for(int i=0;i<adj[curr].size();i++)
            {
                int adjnode = adj[curr][i];
                if( !vis[adjnode] )
                {
                    vis[adjnode]=true;
                    q.push({ adj[curr][i] ,curr});
                }
                else if(adjnode !=prev ) return 1;
            }
        }
        return 0;
   }
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        bool vis[V] = {false};
        

        for(int i=0;i<V;i++)
        {

            if(!vis[i])
            {
                if(detectCycle(vis,i,adj)){
                    return 1;
                }
            }

        }
        return 0;
    }
