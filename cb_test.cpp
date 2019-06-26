
#include <iostream>
#include <algorithm>
#include <queue>
#include <cmath>
#include <vector>
#include <utility>  //pair, make_pair()
#define MOD 1e9+7
using namespace std;

typedef long long ll;
typedef pair<int, int> pair;

int main(){
	int n, k; 
	cin >> n >> k;
	int maxm = n;
	int *code = new int[n];
	vector<int> v(n+1, -1);
	for (int i=0; i<n; i++){
		cin >> code[i];
		v[code[i]] = i;
	} 

	int p = 0;
	while(k && p<n){
		if(code[p] != maxm){
			int temp = code[p];
			code[p] = maxm;
			code[v[maxm]] = temp;
			int tmp = v[temp];
			v[temp] = v[code[p]];
			v[code[p]] = tmp;
		}
		else k++;
		k--;
		p++;
		maxm--;
	}

	if (k%2!=0){
		int temp = code[n-1];
		code[n-1] = code[n-2];
		code[n-2] = temp;
	}

	for (int i=0; i<n; i++){
		cout << code[i] << " ";
	}
	return 0;
}