#include<iostream>
#include<vector>
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

int main(){
    int v = 7;
    DSU u(v);

    u.Union(0,1);
    u.Union(2,3);
    cout<<(u.Union(1,3));
    cout<<(u.Get(3));
    cout<<(u.Get(2));
    u.Union(0,4);
    cout<<(u.Get(4));
    cout<<(u.Union(2,0));


    return EXIT_SUCCESS;

}