#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ff first
#define ss second
#define all(a) a.begin(), a.end()

map<int, int> mp;
struct node{
	int l, r, w;
};

main(){
   ios::sync_with_stdio(0);
   cin.tie(0); cout.tie(0);
	int n; cin >> n;
	vector<node> a(n + 1);
	vector<int> cor;
	for(int i = 1;i <= n; i++){
		cin >> a[i].l >> a[i].r >> a[i].w;
		cor.push_back(a[i].l);
		cor.push_back(a[i].r);
	}	
	sort(all(cor));
	cor.erase(unique(all(cor)), cor.end());
	int compr = 1;
	for(int i = 0;i < cor.size(); i++){
		if(mp.count(cor[i])) continue;
		mp[cor[i]] = compr++;
	}
	vector<int> g[3*n];
	for(int i = 1;i <= n; i++){
		a[i].l = mp[a[i].l];
		a[i].r = mp[a[i].r];
		g[a[i].r].push_back(i);
	}
	vector<int> dp(2*n + 1, INT_MIN);
	dp[0] = 0;
	for(int j = 1;j <= 2*n; j++){
		dp[j] = dp[j-1];
		for(int from : g[j]){
			dp[j] = max(dp[j], dp[a[from].l-1] + a[from].w);
		}
	}
	int mx = 0;
	for(int i = 0;i <= 2*n; i++){
		mx = max(mx, dp[i]);
	}
	cout << mx;
	return 0;
}

