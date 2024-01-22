#include <bits/stdc++.h>
using namespace std;

vector<int> findLPS(string pattern){
	int n = pattern.size();
	vector<int> LPS(n);
	int len = 0, i=1;
	LPS[0] = 0;

	while(i<n){
		if(pattern[i]==pattern[len])
			LPS[i++] = ++len;
		else{
			if(len==0)
				LPS[i++] = 0;
			else
				len = LPS[len-1];
		}
	}

	return LPS;

}

vector<int> findPattern(const string &text, const string &pattern){
	// KMP Algo:

	auto LPS = findLPS(pattern);
	int i=0, j=0, n=text.size(), m=pattern.size();
	vector<int> startIdx;

	while(i<n){
		if(text[i]==pattern[j]){
			++i; ++j;
		}
		if(j==m){
			startIdx.push_back(i-j);
			j = LPS[j-1];
		}
		else if(i<n && text[i]!=pattern[j]){
			if(j==0)
				++i;
			else
				j = LPS[j-1];
		}

	}

	return startIdx;
}

int main(int argc, char const *argv[]){

	string text = "abbaced";
    string pattern = "abba";

	auto v = findPattern(text, pattern);
    for(auto it:v)
        cout<<it<<", ";

	return EXIT_SUCCESS;
} 