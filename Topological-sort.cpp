//BFS ( Kahn's Alogorithm)

public:
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    // code here
	    int indeg[V]={0};
	    for(int i=0;i<V;i++)
	    {
	        for(auto itr:adj[i])
	        {
	            indeg[itr]++;
	        }
	    }
	    
	    queue<int>q;
	    for(int i=0;i<V;i++)
	    {
	        if(indeg[i]==0)
	        {
	            q.push(i);
	        }
	    }
	    vector<int> vec;
	    while(!q.empty())
	    {
	        int curr = q.front();
	        q.pop();
	        vec.push_back(curr);
	        for(auto itr:adj[curr])
	        {
	            indeg[itr]--;
	            if(indeg[itr]==0) q.push(itr);
	        }
	    }
	    
	    return vec;
	}




// ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//DFS approach using stack 


  private:
    void dfs(int node,vector<int> adj[], int vis[],stack<int> &st)
    {
        vis[node ] =1;
        for(auto itr:adj[node])
        {
            if(!vis[itr])dfs(itr,adj,vis,st);
        }
        st.push(node);
        return;
    }
	public:
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    // code here
	    int vis[V] ={0} ;
	    stack<int> st ;
	    for(int i=0;i<V;i++)
	    {
	        if(!vis[i])
	        {
	            dfs(i,adj,vis,st);
	        }
	    }
	    
	    vector<int> vec ;
	    while(!st.empty())
	    {
	        vec.push_back(st.top());
	        st.pop();
	    }
	    return vec;
	}



