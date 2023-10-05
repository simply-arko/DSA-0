#include<iostream>
#include<vector>
using namespace std;

int queen_count;

void display(vector <vector<bool> > &grid){
    int n = grid.size();

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++)
            (grid[i][j])?cout<<"Q ":cout<<". ";
        cout<<endl;
    }
}

bool isSafe(vector<vector<bool> > &grid, int row, int col){
    int n = grid.size();
    for(int i=row-1; i>=0; i--)
        if(grid[i][col])    return false;
    
    for(int i=row-1, j=col-1; i>=0 && j>=0; i--, j--)   //left upper diagonal
        if(grid[i][j])  return false;
    
    for(int i=row-1, j=col+1; i>=0 && j<n; i--, j++)    //right upper diagonal
        if(grid[i][j])  return false;
    return true;
}

void count_queen(vector<vector<bool> > &grid, int curr_row){
    int n = grid.size();
    if(curr_row==n){
        ++queen_count;
        display(grid);
        cout<<endl;
        return;
    }

    for(int i=0; i<n; i++)
        if(isSafe(grid, curr_row, i)){
            grid[curr_row][i] = true;
            count_queen(grid, curr_row+1);
            grid[curr_row][i] = false;
        }

}

int main(){
    int n;
    cout<<"Enter dimension of grid: ";
    cin>>n;
    vector <vector<bool> > grid(n, vector<bool>(n, false));
    count_queen(grid, 0);

    cout<<"\nPossible ways: "<<queen_count;

    // T(n) = n!
    // S(n) = n^2;

    return EXIT_SUCCESS;
}