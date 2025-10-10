#include <bits/stdc++.h>
using namespace std;
// https://oj.uz/problem/view/BOI17_politicaldevelopment
#define ff first
#define ss second
#define all(a) a.begin(), a.end()
const int N = 50000;
int n, k;
int deg[N];
vector<int> g[N];
bitset<N> yes[N];
main(){
   ios::sync_with_stdio(0);
   cin.tie(0); cout.tie(0);
	cin >> n >> k;
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int> > > pq;
	for(int i = 0;i < n; i++){
		int sz; cin >> sz;
		deg[i] = sz;
		pq.push({deg[i], i});
		yes[i][i] = 1;
		for(int j = 0;j < sz; j++){
			int x; cin >> x;
			yes[i][x] = 1;
			g[i].push_back(x);
		}
	}	
	int ans = 1;
	vector<int> used(n, 0);
	while(true){
		while(!pq.empty() && (used[pq.top().ss] || pq.top().ff != deg[pq.top().ss])) pq.pop();
		if(pq.empty()) break;
		int v = pq.top().ss;
		pq.pop();
		used[v] = 1;
		vector<int> vert = {v};
		for(int to : g[v]){
			if(used[to]) continue;
			deg[to]--;
			pq.push({deg[to], to});
			vert.push_back(to);
		}
		for(int mask = 1; mask < (1<<vert.size()); mask++){
			int ok = 1, cnt = 0;
			for(int i = 0;i < vert.size() && ok; i++){
				if(!(mask & (1<<i))) continue;
				cnt++;
				for(int j = 0;j < vert.size(); j++){
					if(mask & (1<<j)){
						if(yes[vert[i]][vert[j]] == 0){
							ok = 0;
							break;
						}
					}
				}
			}
			if(ok){
				if(cnt > k) assert(false);
				ans = max(ans, cnt);
			}
		}
	}
	cout << ans;
	return 0;
}