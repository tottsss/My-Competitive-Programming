#include <bits/stdc++.h>

using namespace std;
#define ff first
#define ss second
const int N = 1e5+1;
int n, m, q, LEN, comp;

vector<int> answer(N), p(N), sz(N), X(N), y(N);
stack< array<int, 4> > st;
struct query{
	int l, r, idx; 
};
vector<query> MO[N];

int find_set(int v){
	while(v!= p[v]) v = p[v];
	return v;
}

void union_set(int a, int b, bool persist = false){
	a = find_set(a);
	b = find_set(b);
	if(a == b) return;
	if(sz[b] > sz[a]) swap(a,b);
	if(persist){
		st.push({b, p[b], a, sz[a]});
	}
	p[b] = a;
	sz[a]+= sz[b];
	comp--;
}



main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n >> m;
	LEN = sqrt(m)+1;
	//edges
	for(int i = 1;i <= m; i++){
		cin >> X[i] >> y[i];
	}
	// reset
	for(int i = 1;i <= n; i++){
		p[i] = i, sz[i] = 1;
	}
	
	// queries
	cin >> q;
	for(int i = 1;i <= q; i++){
		int l, r; cin >> l >> r;
		comp = n;
		if(l / LEN == r / LEN){
			for(int j = l;j <= r; j++){
				p[X[j]] = X[j], sz[X[j]] = 1;
				p[y[j]] = y[j], sz[y[j]] = 1;
			}
			for(int j = l;j <= r; j++){
				union_set(X[j], y[j]);
			}
			answer[i] = comp;
			continue;
		}
		MO[l / LEN].push_back({l, r, i});
	}

	
	// answering 
	for(int i = 0;i <= LEN; i++){
		sort(MO[i].begin(), MO[i].end(), [&](query a, query b){
			return a.r < b.r;
		});
		int r = i*LEN+LEN; 
		// reset
		comp = n;
		for(int j = 1;j <= n; j++){
			p[j] = j, sz[j] = 1;
		}
		
		for(query x : MO[i]){
			while(x.r >= r){
				union_set(X[r], y[r]);
				r++;
			}
			int l = i*LEN+LEN-1;
			while(l>= x.l){
				union_set(X[l], y[l], true);
				l--;
			}
			answer[x.idx] = comp;
			while(!st.empty()){
				int b = st.top()[0], Pb = st.top()[1], a = st.top()[2], szA = st.top()[3];
				p[b]=Pb;
				sz[a] = szA;
				st.pop();
				comp++; 
			}
		}
	}
	
	// printing answer
	for(int i = 1;i <= q; i++){
		cout << answer[i] << "\n";
	}
	return 0;
}