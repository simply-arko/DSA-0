#include<iostream>
#include<vector>
#include<queue>
#include<stack>
using namespace std;

class node{
    public:
        int vertex;
        node *next;

        node(int vertex):vertex(vertex), next(NULL){} 
};

class AdjList{
    private:
        node *start;
    
    public:
        AdjList();
        ~AdjList();
        node* getStart();
        bool isEmpty();
        void insert(int);
        void displayList();
};

AdjList::AdjList(){
    start = NULL;
}

AdjList::~AdjList(){
    while(start){
        node *del = start;
        start = start->next;
        delete del;
    }
}

node* AdjList::getStart(){
    return start;
}

bool AdjList::isEmpty(){
    return start == NULL;
}

void AdjList::insert(int item){
    node *newNode = new node(item);
    if(isEmpty())
        start = newNode;
    else{
        node *temp = start;
        while(temp->next)
            temp = temp->next;
        temp->next = newNode;
    }
}
void AdjList::displayList(){
    node *temp = start;
    while(temp){
        cout<<"v"<<temp->vertex<<" ";
        temp = temp->next;
    }
}

class Graph{
    private:
        int v_count;
        AdjList *arr;
    
    public:
        Graph();
        ~Graph();
        void createGraph(int, int);
        void addEdge(int, int);
        void printGraph();
        void BFS(int);
        void DFS(int);
};

Graph::Graph(){
    v_count = 0;
    arr = NULL;
}

Graph::~Graph(){
    delete []arr;
}

void Graph::createGraph(int v, int e){
    v_count = v;
    arr = new AdjList[v];
    
    cout<<"Enter "<<e<<" adjacent nodes:\n";
    for(int i=0; i<e; i++){
        int v1, v2;
        cin>>v1>>v2;
        arr[v1].insert(v2);
        arr[v2].insert(v1);
    }
}

void Graph::addEdge(int v1, int v2){
    arr[v1].insert(v2);
    arr[v2].insert(v1);
}

void Graph::printGraph(){
    cout<<"Adjacency List:\n";
    for(int i=0; i<v_count; i++){
        cout<<"v"<<i<<"-> ";
        arr[i].displayList();
        cout<<"\n";
    }
}

void Graph::BFS(int v){
    vector <bool> isVisited(v_count, 0);
    queue <int> q;
    q.push(v);
    isVisited[v] = 1;
    cout<<"BFS Traversal with start node v"<<v<<": ";
    while(!q.empty()){
        int n = q.front();
        cout<<"v"<<n<<", ";
        q.pop();
        node *temp = arr[n].getStart();
        while(temp){
            if(!isVisited[temp->vertex]){
                q.push(temp->vertex);
                isVisited[temp->vertex] = 1;
            }
            temp = temp->next;
        }
    }
    cout<<"\n";
}

void Graph::DFS(int v){
    vector <bool> isVisited(v_count, 0);
    stack <int> st;
    st.push(v);
    isVisited[v] = 1;
    cout<<"DFS Traversal with start node v"<<v<<": ";
    while(!st.empty()){
        int n = st.top();
        cout<<"v"<<n<<", ";
        st.pop();
        node *temp = arr[n].getStart();
        while(temp){
            if(!isVisited[temp->vertex]){
                st.push(temp->vertex);
                isVisited[temp->vertex] = 1;
            }
            temp = temp->next;
        }
    }
    cout<<"\n";
}

int main(){
    Graph g;
    g.createGraph(6, 9);
    g.printGraph();
    g.BFS(0);
    g.DFS(4);

    return EXIT_SUCCESS;
}