#include "closing.h"
#include <bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
const int MAXN = 2e5;
vector<int> parent;
long long dp[3005][6005];
void dfs(int v, int par, long long deep, vector<long long> &dist, 
	vector< vector<pair<int, int> > >& g){
	dist[v] = deep;
	parent[v] = par;
	for(auto [to, w] : g[v]){
		if(to == par) continue;
		dfs(to, v, deep + w, dist, g);
	}
}


int max_score(int N, int X, int Y, long long K,
              vector<int> U, vector<int> V, vector<int> W){
    vector< vector<pair<int, int> > > g(N);
    parent.clear();
    parent.resize(N);
    vector<long long> dist(N), dist1(N);
    int ans = 0;         
	for(int i = 0;i < N-1; i++){
    	g[U[i]].push_back({V[i], W[i]});
		g[V[i]].push_back({U[i], W[i]});
	}
	if(X > Y) swap(X,Y);
    dfs(X, X, 0LL, dist, g);
    dfs(Y, Y, 0LL, dist1, g);
    if(dist[Y] > 2*K){
    	vector<long long> times;
    	for(int i = 0;i < N; i++) times.push_back(dist[i]);
    	
    	for(int i = 0;i < N; i++) times.push_back(dist1[i]);
    	long long s = 0;
		sort(times.begin(), times.end());
		for(long long cost : times){
			if(s > K-cost) break;
			s+= cost;
			ans++;
		}
		return ans;
	}
	vector<long long> comp;
	for(int i = 1; i <= N; i++)comp.push_back(min(dist[i-1], dist1[i-1]));
    sort(comp.begin(), comp.end());
    long long curr = 0;
    for(int i = 0; i < N; i++){
        if(curr + comp[i] <= K){
            curr += comp[i];
			 ans++;
        }
    }
	int node = X;
	vector<int> in(N + 10, 0);
	do{
		in[node + 1] = 1;
		node = parent[node];
	}while(node != Y);
	in[Y + 1] = 1;
	for(int i = 0;i <= N; i++){
		for(int j = 0;j <= N*2; j++) dp[i][j] = K+5;
	}
	dp[0][0] = 0;
	for(int i = 0;i < N; i++){
		for(int j = 0;j <= 2*N; j++){
			if(dp[i][j] > K) continue;
			if(in[i+1]){
				dp[i+1][j+1] = min(dp[i+1][j+1], dp[i][j] + min(dist[i+1], dist1[i+1]));
				dp[i+1][j+2] = min(dp[i+1][j+2], dp[i][j] + max(dist[i+1], dist1[i+1]));
			}else{
				dp[i+1][j] = min(dp[i+1][j], dp[i][j]);
				dp[i+1][j+1] = min(dp[i+1][j+1], dp[i][j] + min(dist[i+1], dist1[i+1]));
				dp[i+1][j+2] = min(dp[i+1][j+2], dp[i][j] + max(dist[i+1], dist1[i+1]));
			}
		}
	}
	for(int j = 0;j <= 2*N; j++){
		if(dp[N][j] <= K) ans = max(ans, j);
	}
	return ans;
}


//main(){
//	int N, X, Y; cin >> N >> X >> Y;
//	long long K; cin >> K;
//	vector<int> U, V, W;
//	for(int i = 0;i < N-1; i++){
//		int a, b, w; cin >> a >> b >> w;
//		U.push_back(a);
//		V.push_back(b);
//		W.push_back(w);
//	}
//	cout << max_score(N, X, Y, K, U, V, W) << '\n';
//	return 0;
//}