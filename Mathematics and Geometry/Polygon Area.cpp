#include <bits/stdc++.h>
using namespace std;
#define int long long 
main(){
	int n;
	cin >> n;
	vector< pair<int, int> > a;
	int x, y;
	int s, e;
	cin >> x >> y;
	s = x, e = y;
	a.push_back({x, y});
	for(int i = 0;i < n - 1; i++){
		cin >> x >> y;
		a.push_back({x, y});
	}
	a.push_back({s, e});
	int sum = 0;
	int sum1 = 0;
	for(int i = 0;i < n; i++){
		sum+= a[i].first * a[i + 1].second;
		sum1+= a[i].second * a[i + 1].first;
	}
	
	cout << abs(sum - sum1);
	return 0;
}