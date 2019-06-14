#include<iostream>
using namespace std;

void print(int arr[], int n){
	for (int i=n-1 ;i>=0; i--) cout << arr[i] << " ";
	/*cout << "\n" << n;*/
}

int main(){
	int num; cin >> num;
	int n = num-1;
	int res[1000000] = {0};
	int i = 0;
	bool flag = false;
	while(num > 0){
		int d = num%10;
		num /= 10;
		res[i] = d;
		i++;
		flag = true;
	}

	while(n && flag){
		int carry = 0;
		for (int j=0; j<i; j++){
			int rwc = res[j]*n + carry;
			res[j] = rwc%10;
			carry = rwc/10;
		}

		while(carry){
			res[i] = carry%10;
			carry /= 10;
			i++;
		}
		n--;
	}

	print(res, i);

	return 0;
}