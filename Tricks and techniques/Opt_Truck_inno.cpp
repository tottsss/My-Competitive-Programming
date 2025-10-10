#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ff first
#define ss second
#define all(a) a.begin(), a.end()
const int M = 1e9 + 7;
const int N = 1e6 + 1;

struct data{
	int w, c, idx;
};

main(){
   ios::sync_with_stdio(0);
   cin.tie(0); cout.tie(0);
	int n; cin >> n;
	vector<data> weight;
	for(int i = 0;i < n; i++){
		int m; cin >> m;
		for(int j = 0;j < m; j++){
			int x; cin >> x;
			int c; cin >> c;
			weight.push_back({x, c, i});
		}
	}
	sort(all(weight), [&](data a, data b){
		if(a.w == b.w) return a.c > b.c;
		return a.w < b.w;
	});
//	for(auto x : weight){
//		cout << x.w << ' ' << x.c << '\n';
//	}
	int q; cin >> q;
	vector<int> answer(q), mx(n, 0);
	vector< pair<int, int> > Q(q);
	for(int i = 0;i < q; i++){
		cin >> Q[i].ff;
		Q[i].ss = i;
	}
	sort(all(Q));
	int j = 0, all = 0;
	for(int i = 0;i < q; i++){
//		cout << Q[i].ff << ' ';
		while(j < weight.size() and all < Q[i].ff){
			int idx = weight[j].idx;
			all-= mx[idx];
			mx[idx] = max(mx[idx], weight[j].c);
			all+= mx[idx];
			j++;		
		}
		if(all >= Q[i].ff){
			answer[Q[i].ss] = weight[j-1].w;
		}else answer[Q[i].ss] = -1;
	}
//	cout << endl;
	for(int i = 0;i < q; i++){
		cout << answer[i] << " ";
	}
	return 0;
}

