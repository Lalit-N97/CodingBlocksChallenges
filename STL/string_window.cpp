#include <iostream>
#include <string>
#include <utility>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(string a, string b){
	return a.size() < b.size();
}

int Sum(map<char, int> temp){
	int sum = 0;
	for (map<char,int>::iterator it=temp.begin(); it!=temp.end(); it++){
		sum += it->second;
	}
	return sum;
}

string min_window(string s, map<char, int> pat){

	int start=0, end=0;
	vector<string> v;
	map<char, int> temp(pat);
	map<char, int> hash;

	while(end < s.size()){
		while(Sum(temp) != 0 && end<s.size()){
			if (pat[s[end]] != 0) hash[s[end]]++;
			if (temp[s[end]] != 0){
				temp[s[end]]--;
			}
			end++;
		}
		while(start <= end && !Sum(temp)){
			if (pat[s[start]] == 0) start++;
			else if (pat[s[start]] < hash[s[start]]){
				hash[s[start]]--;
				start++;
			}
			else break;
		}
		if (!Sum(temp) ) v.push_back(s.substr(start, end-start));
		
		temp[s[start]]++;
		hash[s[start]]--;
		start++;
	}

	sort(v.begin(), v.end(), compare);
	if (!v.empty()) return v[0];
	else return "No string";
    
}

int main(){
	string s, pat;
	pair<int, int> p;
	map<char, int> m;

	getline(cin, s);
	getline(cin, pat);

	for (int i=0; i<pat.size(); i++){
		if (m.find(pat[i]) != m.end()) m[pat[i]]=1;
		else m[pat[i]]++;
	}

	if (pat.size() > s.size() || pat.size() == 0) cout << "No string";
	else {
		cout << min_window(s, m);
	}

	return 0;
}