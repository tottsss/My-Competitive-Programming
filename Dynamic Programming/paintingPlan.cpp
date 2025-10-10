#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ff first
#define ss second
const int INF = 1e9 + 7;
 
main(){
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int n, k; cin >> n >> k;
	vector<int> a(2*n);
	for(int i = 0;i < 2*n; i++){
		cin >> a[i];
	}
	vector< pair<int, int> > W;
	for(int i = 0;i < n; i++){
		if(2*i+2 < 2*n)
		W.push_back(make_pair(a[2*i+2] - a[2*i+1], i));
		k-= (a[2*i+1] - a[2*i]);
	}
	if(k < 0){
		cout << "No";
		return 0;
	}
	vector<int> dp(k + 10, 0);
	vector< pair<int, int> > parent(k + 10, {-1, -1});
	dp[0] = 1;
	for(auto w : W){
		for(int j = k; j >= w.ff; j--){
			if(dp[j-w.ff]==1 and dp[j]==0){
				parent[j] = w;
				dp[j] = 1;
			}
		}
	}
	if(dp[k]==0){
		cout << "No";
		return 0;
	}
	cout << "Yes" << '\n';
	vector<int> ans, ans1;
	int cur = k;
	for(pair<int, int> par = parent[cur]; par.ff != -1;cur-= par.ff, par = parent[cur]){
		ans.push_back(2*par.ss+1);
		ans.push_back(2*par.ss+2);
	}
	vector< pair<int, int> > answer;
	sort(ans.begin(), ans.end());
	int id = 0;
	for(int i = 0;i < 2*n; i++){
		while(id < ans.size() and ans[id] < i){
			id++;
		}
		if(id >= ans.size() || i != ans[id]){
			ans1.push_back(i);
		}
	}
	for(int i = 0;i < ans.size(); i+= 2){
		answer.push_back({ans[i], ans[i+1]});
	}
	for(int i = 0;i < ans1.size(); i+= 2){
		answer.push_back({ans1[i], ans1[i+1]});
	}
	for(auto x : answer){
		if(x.ff > x.ss) swap(x.ff, x.ss);
		cout << x.ff+1 << ' ' << x.ss+1 << '\n';
	}
	return 0;
}