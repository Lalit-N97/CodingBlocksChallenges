/*UNLOCK
Shekhar is a bomb defusal specialist. He once encountered a bomb that can be defused only by a secret code. He is given a number N and a number K. And he is also given permutation of first N natural numbers . The defusal code is the largest permutation possible by doing exactly K swaps among a pair of the given permutation. Help him to find the final permutation.

Input Format:
First line contains ​an integer N and an integer k. The next line contains N space separated integers denoting the given permutation.

Constraints:
1 <= n <= 10^5 1<= K <= 10^9

Output Format
The final permutation of the numbers with every number separated by a space with other number.

Sample Input
5 2
3 4 1 2 5
Sample Output
5 4 3 2 1*/

/*Note : we have to do atmost k swaps not exactly k swaps (problem in question)*/

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
	int n;
	ll k; 
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
			int c = code[p];
			swap(code[p], code[v[maxm]]);
			swap(v[maxm], v[c]);
		}
		else k++;
		k--;
		p++;
		maxm--;
	}

	/*if (k%2!=0){
		swap(code[n-1], code[n-2]);
	}*/

	for (int i=0; i<n; i++){
		cout << code[i] << " ";
	}
	return 0;
}