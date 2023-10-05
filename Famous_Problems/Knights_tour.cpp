#include<iostream>
#include<vector>
using namespace std;

int possible_count;

void display(vector <vector<int> > &grid){
    int n = grid.size();

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++)
            cout<<grid[i][j]<<" ";
        cout<<endl;
    }
}

bool isSafe(vector<vector <int> > &grid, int i, int j){
    int n = grid.size();
    return i>=0 && j>=0 && i<n && j<n && grid[i][j]==-1;
}

void knights_tour(vector<vector <int> > &grid, int i, int j, int count){
    int n = grid.size();
    grid[i][j] = count;

    if(n*n-1 == count){
        ++possible_count;
        display(grid);
        cout<<endl;
        grid[i][j] = -1;    //Back-Tracking Step
        return;
    }

    if(count>=n*n)  return;


    int dY[] = {-2, -2, -1, -1, 2, 2, 1, 1};
    int dX[] = {1, -1, 2, -2, 1, -1, 2, -2};
    for(int k=0; k<8; k++)
        if(isSafe(grid, i+dY[k], j+dX[k])){
            knights_tour(grid, i+dY[k], j+dX[k], count+1);
        }
    
    
    grid[i][j] = -1;    //Back-Tracking Step

}

int main(){
    int n;
    cout<<"Enter Dimensions: ";
    cin>>n;
    vector<vector <int> > grid(n, vector<int>(n, -1));
    knights_tour(grid, 0, 0, 0);
    cout<<"\nNo. of possible arrangements: "<<possible_count;


    return EXIT_SUCCESS;
}