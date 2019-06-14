/*Nishant is a very naughty boy in Launchpad Batch. 
One day he was playing with strings, and randomly shuffled them all. 
Your task is to help Nishant Sort all the strings ( lexicographically ) 
but if a string is present completely as a prefix in another string, 
then string with longer length should come first. Eg bat, batman
 are 2 strings and the string bat is present as a prefix in Batman
 - then sorted order should have - Batman, bat.

Input Format:
N(integer) followed by N strings.

Constraints:
N<=1000

Output Format
N lines each containing one string.

Sample Input
3
bat
apple
batman
Sample Output
apple
batman
bat*/

#include <iostream> 
#include <algorithm>
#include <string>
using namespace std; 
 
bool compare(string a, string b){
	int min_len = min(a.length(), b.length());
	string new_a = a.substr(0, min_len);
	string new_b = b.substr(0, min_len);
	if (new_a == new_b){
		return a.length() > b.length();
	}
	return a<b;
}

int main() 
{ 	
	int t; cin >> t;
	string s[1000];
	for (int i=0; i<t; i++) cin >> s[i];
	
	sort(s, s+t, compare);
	int i=t-1;
	while(t--){
		cout << s[i-t] << "\n";
	}

	return 0; 
} 