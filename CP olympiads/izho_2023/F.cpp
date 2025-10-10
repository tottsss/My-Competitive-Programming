#include <bits/stdc++.h>
using namespace std;

//#define int long long
#define ff first
#define ss second
#define all(a) a.begin(), a.end()
const int N = 77777;
int n, m, q;
vector<int> g[N];
int a[N], b[N], c[N], d[N];
int x[N], y[N], l[N], r[N];
int lg[N];
int MinD = INT_MAX;
int bambuk, equality;
/*
union_find_set
int par[N], sz[N];
void union_find_set(){
	for(int i = 0;i < N: i++){
		par[i] = i, sz[i] = 1;
	}
}

int find_set(int v){
	if(v == par[v]) return v;
	return par[v] = find_set(par[v]);
}

void union_set(int a, int b){
	a = find_set(a), b = find_set(b);
	if(a == b) return;
	if(sz[a] < sz[b]) swap(a, b);
	par[b] = a;
	sz[a]+= sz[b];
}
*/
void subtask12(){
	vector<vector<int> > par(3001, vector<int>(3001));
	vector<vector<int> > sz(3001, vector<int>(3001,1));
	for(int i = 1;i <= 3000; i++){
		for(int j = 0;j < n; j++){
			par[i][j] = j;
		}
	}
	
	function<int(int, int)> find_set_time=[&](int v, int T){
		if(v == par[T][v]) return v;
		return par[T][v] = find_set_time(par[T][v], T);	
	};
	function<void(int,int, int)> union_set_time=[&](int a, int b, int T){
		a = find_set_time(a, T);
		b = find_set_time(b, T);
		if(a == b) return;
		if(sz[T][a] < sz[T][b]) swap(a, b);
		sz[T][a]+= sz[T][b];
		par[T][b] = a; 
	};

	for(int i = 0;i < m; i++){
		for(int T = c[i]; T <= d[i]; T++){
			union_set_time(a[i], b[i], T);
		}
	}
	for(int i = 0;i < q; i++){
		int cnt = 0;
		for(int T = l[i]; T <= r[i]; T++){
			if(find_set_time(x[i], T) == find_set_time(y[i], T)) cnt++;
		}
		cout << cnt << '\n';
	}
}


struct Q{
	int x, y, l, r, idx;
};

void subtask4(){
//	assert(false);
	int par[n];
	vector<int> answer(q,-1);
	vector<int> list[n];
	for(int i = 0;i < n; i++){
		par[i] = i;
		list[i].push_back(i);
	}
	map<pair<int, int>,int> when;
	vector<Q> events;
	for(int i =0 ;i < m; i++){
		events.push_back({a[i], b[i], c[i], d[i], i});
	}
	sort(all(events), [](Q A, Q B){
		return A.l<B.l;	
	});
	vector<Q> query;
	for(int i = 0;i < q; i++){
		query.push_back({x[i], y[i], l[i], r[i], i});
	}
	sort(all(query), [](Q A, Q B){
		return A.r<B.r;	
	});
	function<int(int)> find_set=[&](int v){
		if(v == par[v]) return v;
		return par[v]=find_set(par[v]);	
	};
	function<void(int, int, int)> union_set=[&](int a, int b, int T){
		a = find_set(a);
		b = find_set(b);
		if(a == b) return;
		if(list[a].size() < list[b].size()){
			swap(a, b);
		} 
		while(list[b].empty()==false){
			list[a].push_back(list[b].back());
			if(when.count(make_pair(a, list[b].back())) == false){
				cout << a+1 << " " << list[b].back()+1 << ' ' << T << '\n';	
				when[make_pair(a,list[b].back())] = T;
			}
			list[b].pop_back();
		}
		par[b] = a;
	};
	int i = 0;
	for(int j = 0;j < q; j++){
		while(i < m && events[i].l <= query[j].r){
//			cout << events[i].x+1 << ' ' << events[i].y+1 << ' ' << events[i].l << " = ";
			union_set(events[i].x, events[i].y, events[i].l);
//			cout << '\n';	
			i++;
		}
		int X = query[j].x;
		int Y = query[j].y;
		if(find_set(X) != find_set(Y)){
			answer[query[j].idx] = 0;
			continue;
		}
		/*
6 5
1 4 5 100
2 1 5 100
2 3 1 100
3 4 1 100
4 5 5 100
1
1 4 1 100
		*/
		int W = INT_MAX;
		if(when.count(make_pair(X,Y)) ) W = min(W, when[make_pair(X,Y)]);
		else if(when.count(make_pair(Y,X))) W = min(W, when[make_pair(Y,X)]);
		else if(list[find_set(Y)].empty()){
			W = min(W, when[make_pair(find_set(X), Y)]);
		}else if(list[find_set(X)].empty()){
			W = min(W, when[make_pair(find_set(Y), X)]);
		}
//		else assert(false);
//		if(when.count(make_pair(find_set(X),Y)) ) W = min(W, when[make_pair(find_set(X),Y)]);
//		if(when.count(make_pair(X,find_set(Y))) ) W = min(W, when[make_pair(X,find_set(Y))]);
//		if(when.count(make_pair(find_set(Y),find_set(X))) ) W = min(W, when[make_pair(find_set(Y),find_set(X))]);
		if(W==0) assert(false);
		if(W > query[j].r){
			answer[query[j].idx] = 0;
		}else{
			answer[query[j].idx] = query[j].r - max(query[j].l, W)+1;
		}
	}
	for(int i = 0;i < q; i++){
		if(answer[i] == -1) assert(false); 
		cout << answer[i] << '\n';
	}
}

void subtask3(){
	vector<pair<int, int> > range;
	for(int i = 0;i < m; i++){
		range.push_back({c[i], d[i]});
	}
	for(int i = 0;i < q; i++){
		int left_most = l[i], right_most = r[i];
		for(int j = min(x[i], y[i]); j < max(x[i], y[i]); j++){
			left_most = max(left_most, range[j].ff);
			right_most = min(right_most, range[j].ss);
		}
		cout << max(0, right_most-left_most+1) << '\n';
	}
}

main(){
   ios::sync_with_stdio(0);
   cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for(int i = 2;i < N; i++){
		lg[i] = lg[i/2]+1;
	}
	for(int i = 0;i < m; i++){
		cin >> a[i] >> b[i] >> c[i] >> d[i];
		a[i]--, b[i]--;
		if(a[i] == i and b[i] == i+1){
			bambuk++;
		}
		MinD = min(MinD, d[i]);
	}
	cin >> q;
	for(int i = 0;i < q; i++){
		cin >> x[i] >> y[i] >> l[i] >> r[i];
		if(l[i] == r[i]) equality++;
		x[i]--, y[i]--;
	}
	if(MinD == (int)100){
		subtask4();
		return 0;
	}
	if(max({n, m, q}) <= 3000){
		subtask12();
		return 0;
	}
	if(m == n-1 and bambuk == m){
		subtask3();
		return 0;
	}
//	if(equality == q){
//		subtask5();
//		return 0;
//	}
	return 0;
}

