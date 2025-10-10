#include <bits/stdc++.h>
using namespace std;

#define ff first
#define ss second
#define all(a) a.begin(), a.end()
const int N = 1e5;
const  double M = 1e9 + 7;
vector<pair<int, double> > g[N+1], G[N+1];
vector< double> dis1(N+1, M), disn(N+1, M);
vector<int> p1(N+1, -1), pn(N+1, -1);
//set<pair< double, int> > st;
priority_queue<pair<double,int> > st;
vector<int> ans;
int n, m;
int good( double average){
	for(int i = 1;i <= n; i++){
		p1[i] = -1, pn[i] = -1, dis1[i] = M, disn[i] = M;
	}
	st.push({0.0, 1});
	dis1[1] = 0.0;
	while(!st.empty()){
		int v = st.top().ss;
		double D = -st.top().ff;
		st.pop();
		if(dis1[v] < D) continue;
		for(auto [to, w] : g[v]){
			if(dis1[to] > dis1[v] + w - average){
//				st.erase({dis1[to], to});
				dis1[to] = dis1[v] + w - average;
				p1[to] = v;
				st.push({-dis1[to], to});
			}
		}
	}
	st.push({0.0, n});
	disn[n] = 0.0;
	while(!st.empty()){
		int v = st.top().ss;
		double D = -st.top().ff;
		st.pop();
		if(disn[v] < D) continue;
		for(auto [to, w] : G[v]){
			if(disn[to] > disn[v] + w - average){
//				st.erase({disn[to], to});
				disn[to] = disn[v] + w - average;
				pn[to] = v;
				if(dis1[to] + disn[to] <= 0) return 1;
				st.push({-disn[to], to});
			}
		}
	}
	for(int i = 1;i <= n; i++){
		if(dis1[i] + disn[i] <= 0){
			return 1;
		}
	}
	return 0;
}


main(){
   ios::sync_with_stdio(0);
   cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for(int i = 0;i < m; i++){
		int a, b;  double w; cin >> a >> b >> w;
		g[a].push_back({b, w});
		G[b].push_back({a, w});
	}
		
	 double l = 0, r = (n+1.0)*100.0;
	for(int round = 1; round <= 30 and r > l; round++){
		 double mid = (l + r) * 0.5;
		if(good(mid)){
			r = mid;
		}else{
			l = mid;
		}
	}
	good(r);
	for(int i = 1;i <= n; i++){
		if(dis1[i] + disn[i] <= 0){
			for(int par = i; par != -1; par = p1[par]){
				ans.push_back(par);
				
			if(ans.size() > n) assert(false);
			}
			reverse(all(ans));
			for(int par = pn[i]; par != -1; par = pn[par]){
			ans.push_back(par);
			if(ans.size() > n) assert(false);	
			} 
			break;
		}
	}
	cout << ans.size()-1 << '\n';
	for(int x : ans){
		cout << x << ' ';
	}
	return 0;
}

