#include<iostream>
#include<vector>
#include<queue>
#include<set>
using namespace std;

vector<int> dijkstraSSSP(int V, vector<pair<int,int>> adj[], int source){

    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    vector<int> dist(V, 1e9);

    dist[source] = 0;
    pq.push({0,source});

    while(!pq.empty()){
        auto [currDis, node] = pq.top();
        pq.pop();

        for(auto [adjNode, edW]:adj[node])
            if(currDis+edW<dist[adjNode]){
                dist[adjNode] = currDis+edW;
                pq.push({dist[adjNode], adjNode});
            }
    }

    return dist;
}

vector<int> dijkstraSSSPOptimised(int V, vector<pair<int,int>> adj[], int source){

    set<pair<int,int>> st;
    vector<int> dist(V, 1e9);

    dist[source] = 0;
    st.insert({0,source});

    while(!st.empty()){
        auto it = st.begin();
        auto [currDis, node] = *it;
        st.erase(it);

        for(auto [adjNode, edW]:adj[node])
            if(currDis+edW<dist[adjNode]){
                // erase if alreadt existing
                if(dist[adjNode!=1e9])
                    st.erase({dist[adjNode], adjNode});

                dist[adjNode] = currDis+edW;
                st.insert({dist[adjNode], adjNode});
            }
    }

    return dist;
}

int main(){
    int V, E;
    cin>>V>>E;
    vector<pair<int,int>> adj[V];

    while(E--){
        int v1, v2, edW;
        cin>>v1>>v2>>edW;
        adj[v1].push_back({v2,edW});
        adj[v2].push_back({v1,edW});
    }

    int s;
    cin>>s;
    // vector <int> ans = dijkstraSSSP(V, adj, s);
    vector <int> ans = dijkstraSSSPOptimised(V, adj, s);

    for(int i=0; i<V; i++)
        cout<<"Distance from vertex "<<i<<": "<<ans[i]<<endl;

    return EXIT_SUCCESS;
}