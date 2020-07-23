#include<bits/stdc++.h>
using namespace std;

vector <int> dijkstra(vector<vector<int>> , int ,int );

int printSolution(vector <int> dist, int n)
{
  
   for (int i = 0; i < n; i++)
      printf("%d ", dist[i]);
  
}
int main()
{
    int t;
    int V;
    cin>>t;
    while(t--){
        cin>>V;
        
        vector<vector<int>> g(V);
        
        for(int i = 0;i<V;i++){
            vector<int> temp(V);
            g[i] = temp;
        }
        
        for(int i=0;i<V;i++)
        {
      	    for(int j=0;j<V;j++)
      	    {
      		    cin>>g[i][j];
      	    }
        }
        
        int s;
        cin>>s;
        
        vector <int> res = dijkstra(g, s, V);
        printSolution (res, V);
        cout<<endl;
       }
        return 0;
}


/*
*   g: vector of vectors which represents the graph
*   src: source vertex to start traversing graph with
*   V: number of vertices
*/

vector <int> dijkstra(vector<vector<int>> g, int src, int V)
{
    
    vector<int> dist(V, INT_MAX);
    
    queue <int> q;
    q.push(src);
    dist[src] = 0;
    
    while(!q.empty())
    {
        int u = q.front();
        q.pop();
        
        for(int x=0; x<V; x++)
        {
            if(g[u][x] != 0)
            {
                if(dist[x] > dist[u]+g[u][x])
                {
                    dist[x] = dist[u] + g[u][x];
                    q.push(x);
                }
            }
        }
    }
    
    return dist;
}
