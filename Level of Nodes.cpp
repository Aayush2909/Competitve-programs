#include <bits/stdc++.h>
using namespace std;

class Graph 
{ 
	int V; 
	vector<int> *adj; 
    
public: 
    Graph(int V); 
	void addEdge(int u, int v); 
	int levels(int x, int in); 
}; 

Graph::Graph(int V) 
{ 
	this->V = V; 
	adj = new vector<int>[V+1]; 
} 

void Graph::addEdge(int u, int v) 
{ 
    adj[u].push_back(v); 
    adj[v].push_back(u); 
} 


int Graph::levels( int x, int in){
    
    bool vis[V];
    for(int i=0; i<V; i++) vis[i] = false;
    
    queue < pair<int,int>> q;
    q.push({x,0});
    
    vis[x] = true;
    
    while(!q.empty())
    {
        int v = q.front().first;
        int lev = q.front().second;
        
        q.pop();
        
        if(v == in)
        {
            return lev;
        }
        
        for(int x : adj[v])
        {
            if(vis[x] == false)
            {
                q.push({x, lev+1});
                vis[x] = true;
            }
        }
    }
    
    return -1;
}


int main() {
	
	int t;
	cin >> t;
	
	while(t--){
	    
	    int n, e;
	    cin >> n >> e;
	    Graph g(n);
	    int u, v;
	    for(int i = 0;i<e;i++){
	        cin >> u >> v;
	        g.addEdge(u, v);
		}
	    
	    int x;
	    cin >> x;
	    
	    if(x >= n) cout << "-1" << endl;
	    else
	        cout << g.levels( 0, x) << endl;
	    
	}
	
	return 0;
}
