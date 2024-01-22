#include <bits/stdc++.h>
using namespace std;

bool isPossible(vector<int> &arr, int c, int dist){
	int lastCow = arr[0], n = arr.size();

	--c;
	for(int i=1; i<n; i++)
		if(arr[i]-lastCow>=dist){
			lastCow = arr[i];
			--c;
			if(c==0)  return true;
		}


	return false;

}

int getMaxMinDist(vector<int> &arr, int c){
	sort(arr.begin(), arr.end());
	int l = 1, r = arr[arr.size()-1]-arr[0];

	// cout<<isPossible(arr, c, 4);

	while(l<=r){
		int mid = l + (r-l)/2;
		if(isPossible(arr, c, mid))
			l = mid+1;
		else
			r = mid-1;

	}

	return r;
}


int main(int argc, char const *argv[]){

	// write your code here...
	int t;
	cin>>t;

	while(t--){
		int n, c;
		cin>>n>>c;
		vector<int> arr(n);

		for(int i=0; i<n; i++)
			cin>>arr[i];

		cout<<getMaxMinDist(arr, c);
	}

	return EXIT_SUCCESS;
} 