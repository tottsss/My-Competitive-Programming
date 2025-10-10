#include <bits/stdc++.h>
using namespace std;
 
int main(){
	int ans = 0;
	int n;
	cin >> n;
	vector< pair<int, int> > a;
	int x, y;
	for(int i = 0;i < n; i++){
		cin >> x >> y;
		a.push_back({x, 1});
		a.push_back({y, -1});
	}
	sort(a.begin(), a.end());
	int sum = 0;
	for(int i = 0;i < a.size(); i++){
		sum+= a[i].second;
		ans = max(ans, sum);
	}
	cout << ans;
	return 0;
}