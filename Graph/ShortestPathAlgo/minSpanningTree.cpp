#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class DSU{
    private:
        vector <int> parent;
        vector <int> rank;
    
    public:
        DSU(int v){
            parent.resize(v+1);
            rank.resize(v+1,0);
            for(int i=0; i<=v; i++)
                parent[i] = i;
        }

        int Get(int val){
            return parent[val] = (parent[val]==val?val:Get(parent[val]));
        }

        bool Union(int a, int b){
            a = Get(a);
            b = Get(b);
            if(a==b)  return false;

            if(rank[a]==rank[b])
                rank[a]++;
            if(rank[a]>rank[b])
                parent[b] = a;
            else
                parent[a] = b;

            return true;
        }

};

class Solution{
    private:
        int prims(int V, vector<vector<int>> adj[]){
            int wt_sum = 0, edge_cnt = 0;
            // as you don't need the edges; you need not store the parent
            priority_queue <pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
            pq.push({0,0});     // {weight, node}
            vector <bool> vis(V, false);
            
            while(!pq.empty()){
                int wt = pq.top().first;
                int node = pq.top().second;
                pq.pop();
                
                if(vis[node])   continue;
                vis[node] = true;
                wt_sum += wt;
                ++edge_cnt;
                if(edge_cnt==V)   break; //for {0,0} there shouldn’t be an edge count
                
                for(auto it:adj[node]){
                    int adj_node = it[0];
                    int edW = it[1];
                    if(!vis[adj_node])
                        pq.push({edW, adj_node});
                }
            }
            
            return wt_sum;
        }
        
        int kruskals(int V, vector<vector<int>> adj[]){
            vector <bool> vis(V, false);
            vector <tuple<int,int,int>> edges;
            for(int i=0; i<V; i++){
                vis[i] = true;
                for(auto it:adj[i]){
                    int v = it[0];
                    int edW = it[1];
                    if(!vis[v]) edges.push_back(make_tuple(edW, i, v));
                }
            }
            sort(edges.begin(), edges.end());
            
            int wt_sum = 0;
            DSU ds(V);
            for(auto it:edges){
                int u = get<1>(it);
                int v = get<2>(it);
                if(ds.Union(u,v))
                    wt_sum += get<0>(it);
            }
            
            return wt_sum;
        }
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[]){
        // return prims(V, adj);
        return kruskals(V, adj);
    }
};