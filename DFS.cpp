    void dfsUtil(int start,int vis[],vector<int> &vec,vector<int> adj[] )
    {
        if(vis[start]==0){
            vec.push_back(start);
            // cout<<start<<" ";
        }
        vis[start ]=1;
        for(auto itr:adj[start])
        {
            if(vis[itr]==0)
            {
                dfsUtil(itr,vis,vec,adj);
            }
        }
    }
    
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        vector<int> vec ;
        int vis[V] ={0};
        int start = 0;
        dfsUtil(start,vis,vec,adj);
        return vec;
        
    }
    
