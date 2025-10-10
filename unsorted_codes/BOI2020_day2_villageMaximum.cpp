#include <bits/stdc++.h>
using namespace std;
 #define int long long
#define ff first
#define ss second
#define all(a) a.begin(), a.end()
const int mod = 1e9 + 7;
const int N = 2e5;
 
int dp[N], dp1[N], in[N], sub[N];
int n, ans, ans1;
vector<int> g[N];
int timer = 1;

void dfs(int v, int par){
	in[v] = timer++;
	sub[v] = 1;
	for(int to : g[v]){
		if(to != par){
			dfs(to, v);
			sub[v]+= sub[to];
		}
	}
	ans1+= 2 * min(sub[v], n - sub[v]);
	if(par != v && dp[v] == -1 && dp[par] == -1){
		dp[v] = par, dp[par] = v;
		ans+= 2;
	}
}

int centroid(int v, int par){
	for(int to : g[v]){
		if(to == par) continue;
		if(2 * sub[to] > n){
			return centroid(to, v);
		}
	}
	return v;
}

 
main(){
   ios::sync_with_stdio(0);
   cin.tie(0); cout.tie(0);
	for(int i = 0;i < N; i++){
		dp[i] = -1;
		dp1[i] = i;
	}
	cin >> n;
	for(int i = 0;i < n-1; i++){
		int a, b; cin >> a >> b;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	int centre = centroid(1, 1);
	dfs(centre, centre);
	for(int i = 1;i <= n; i++){
		if(dp[i] == -1){
			int to = g[i][0];
			dp[i] = i;
			swap(dp[to], dp[i]);
			ans+= 2;
		}
	}
	vector<int> ord;
	vector<pair<int, int> > vec;
	for(int i = 1;i <= n; i++) vec.push_back({in[i], i});
	sort(all(vec));
	for(int i = 0;i < n; i++){
		ord.push_back(vec[i].ss);
	}
	for(int i = 0;i < n; i++){
		dp1[ord[i]] = ord[(i + n / 2) % n];
	}
	
	cout << ans << ' ' << ans1 << '\n';
	for(int i = 1;i <= n; i++) cout << dp[i] << ' ';
	cout << '\n';
	for(int  i= 1;i <= n; i++) cout << dp1[i] << ' ';
	return 0;
}