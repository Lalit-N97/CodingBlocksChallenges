
#include <iostream>
#include <algorithm>
#include <queue>
#include <cmath>
#include <vector>
#include <utility>  //pair, make_pair()
#include <iterator> // distance
#include <map>
/*#define MOD 1e9+7*/
using namespace std;

typedef long long ll;
typedef pair<int, int> pair;
const unsigned int MOD = 1e9+7;

int sum_of_unique_len(int start, int end){
	int n = end - start;
	int temp = (n*(n+1))%MOD;
	n = (temp*(n+2))%MOD;
	return n/6;
}

int main(){
	int n ;cin >> n;
	int *arr = new int[n];
	int maxm;
	for (int i=0; i<n; i++){
		cin >> arr[i];
		maxm = max(maxm, arr[i]);
	}	

	vector<int> idx(maxm+1, -1);
	int start = 0, end = 0;
	int count = 0;
	while(start<n && end<n){
		if (idx[arr[end]] == -1){
			idx[arr[end]] = end;
			end++;
		}
		else{
			count = (count + sum_of_unique_len(start, end))%MOD;
			while(start != idx[arr[end]]){
				idx[arr[start]] = -1;
				start++;
			}
			idx[arr[start]] = -1;
			start++;
			count = (count - sum_of_unique_len(start, end))%MOD;
		}
	}
	count = (count + sum_of_unique_len(start, end))%MOD;

	cout << count;
    return 0;
}