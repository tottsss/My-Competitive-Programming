#include <bits/stdc++.h>
using namespace std;

#define ff first
#define ss second
#define all(a) a.begin(), a.end()
const int N = 5e5;
const int LOG = 20;
int n, m, Right[N+1];
vector< pair<int, int> > a;
int up[N + 1][LOG + 1];
int go_k(int x, int k){
	for(int i = 0;i <= 20; i++){
		if(k&(1<<i)){
			x = up[x][i];
		}
	}
	return x;
}
main(){
   ios::sync_with_stdio(0);
   cin.tie(0); cout.tie(0);
	cin >> n >> m;
	a.resize(n);
	for(int i = 0;i < n; i++){
		cin >> a[i].ff >> a[i].ss;
	}
	sort(all(a));
	int Right_most = -1, i = 0;
	for(int x = 0; x <= N; x++){
		while(i < n and a[i].ff <= x){
			Right_most = max(Right_most, a[i].ss);
			i++;
		}
		if(Right_most <= x) Right[x] = x;
		else
		Right[x] = Right_most;
	}
	for(int j = 0;j <= LOG; j++){
		for(int i = 0;i <= N; i++){
			if(j == 0) up[i][j] = Right[i];
			else up[i][j] = up[up[i][j-1]][j-1];
		}
	}
	while(m--){
		int x, y; cin >> x >> y;
		int l = 0, r = N;
		if(go_k(x, N) < y){
			cout << -1 << '\n';
			continue;
		}
		for(int round = 1; round <= 64 and l < r; round++){
			int mid = (l + r)>>1;
			if(go_k(x, mid) >= y) r = mid;
			else l = mid;
		}
		if(go_k(x, r) >= y) cout << r;
		else cout << -1;
		cout << '\n';
	}
	return 0;
}

