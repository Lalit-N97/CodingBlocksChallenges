
#include <iostream>
#define MOD 1e9+7
#include <algorithm>
#include <queue>
#include <cmath>
#include <vector>
using namespace std;

typedef long long ll;

class Point{
public:
	ll x;
	ll y;
	Point(ll x, ll y){
		this->x = x;
		this->y = y;
	}
	ll dist(){
		return x*x+y*y;
	}
};

class Compare{
public:
	bool operator()(Point a, Point b){
		return a.dist() < b.dist();
	}
};

int main(){

	int q, k, type, count = 0; 
	ll x, y;
	priority_queue<Point, vector<Point>, Compare> pq;
	cin >> q >> k;

	while(q--){
		cin >> type;
		if (type == 1){
			if (count != k){
				count++;
				cin >> x >> y;
				Point p(x,y);
				pq.push(p);
			}
			else {
				cin >> x >> y;
				Point p(x,y);
				Point close = pq.top();
				if (p.dist() < close.dist()){
					pq.pop();
					pq.push(p);
				}
				count = k;
			}
		}
		else {
			Point close = pq.top();
			cout << close.dist() << "\n";
		}
	}
	return 0;
}