#include<iostream>
#include<vector>
#include<queue>
#include<stack>
using namespace std;

class Graph{
    private:
        int v_count;
        int e_count;
        int **adj_mat;
    
    public:
        Graph();
        ~Graph();
        void createGraph(int, int);
        void printMatrix();
        void printAdjNodes(int);
        bool isIsolated(int);
        void BFS(int);
        void DFS(int);
};

Graph::Graph(){
    v_count = 0;
    e_count = 0;
    adj_mat = NULL;
}

Graph::~Graph(){
    for(int i=0; i<v_count; i++)
        delete []adj_mat[i];
    delete []adj_mat;
    adj_mat = NULL;
}

void Graph::createGraph(int v, int e){
    v_count = v;
    e_count = e;
    adj_mat = new int*[v];
    for(int i=0; i<v; i++)
        adj_mat[i] = new int[v];
    cout<<"Enter "<<e<<" adjacent nodes along with there weight:\n";
    for(int i=0; i<e; i++){
        int v1, v2, w;
        cin>>v1>>v2>>w;
        adj_mat[v1][v2] = w;
        adj_mat[v2][v1] = w;
    }
}

void Graph::printMatrix(){
    cout<<"Adjacency Matrix:\n";
    for(int i=0; i<v_count; i++){
        for(int j=0; j<v_count; j++)
            cout<<adj_mat[i][j]<<" ";
        cout<<"\n";
    }
}

void Graph::printAdjNodes(int v){
    if(v<0 || v>=v_count){
        cout<<"Invalid Vertex number!\n";
        return;
    }
    cout<<"Adjacent nodes of v"<<v<<": ";
    for(int i=0; i<v_count; i++)
        if(adj_mat[v][i]>0)
            cout<<"v"<<i<<", ";
    cout<<"\n";
}

bool Graph::isIsolated(int v){
    if(v<0 || v>=v_count){
        cout<<"Invalid Vertex number!\n";
        return 0;
    }
    for(int i=0; i<v_count; i++)
        if(adj_mat[v][i]>0)
            return 0;
    
    return 1;
}

void Graph::BFS(int v){
    vector <bool> isVisited(v_count,0);
    queue <int> q;
    q.push(v);
    isVisited[v] = 1;
    cout<<"BFS Traversal with start node v"<<v<<": ";
    while(!q.empty()){
        int n = q.front();
        cout<<"v"<<n<<", ";
        q.pop();
        for(int i=0; i<v_count; i++){
            if(adj_mat[n][i]>0 && !isVisited[i]){
                q.push(i);
                isVisited[i] = 1;
            }
        }
    }
    cout<<"\n";
}

void Graph::DFS(int v){
    vector <bool> isVisited(v_count,0);
    stack <int> st;
    st.push(v);
    isVisited[v] = 1;
    cout<<"DFS Traversal with start node v"<<v<<": ";
    while(!st.empty()){
        int n = st.top();
        cout<<"v"<<n<<", ";
        st.pop();
        for(int i=0; i<v_count; i++){
            if(adj_mat[n][i]>0 && !isVisited[i]){
                st.push(i);
                isVisited[i] = 1;
            }
        }
    }
    cout<<"\n";
}

int main(){
    Graph g;
    g.createGraph(6,9);
    g.printMatrix();
    g.printAdjNodes(2);
    g.printAdjNodes(5);
    cout<<endl;
    g.BFS(0);
    g.DFS(4);

    return EXIT_SUCCESS;

}