#include<iostream>
#include <algorithm>
using namespace std;
int main() {
	int n; cin >> n;
	int arr1[1000], arr2[1000];
	for (int i=0; i<n; i++) {
		cin >> arr1[i];
	}
	for (int i=0; i<n; i++){
		cin >> arr2[i];
	}
	int *arr3 = new int[2*n];

	merge(arr1, arr1+n, arr2, arr2+n, arr3);
	double median = (double)(arr3[n-1] + arr3[n])/2.0;
	cout << (int)median;
	return 0;
}