#include <bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
#define all(a) a.begin(), a.end()
const int N = 1e5;
const int SQ = 400;
int last[N + 1], cnt[N+1], a[N+1];
int n, q;


int sub[N + 1];
void decompose(int block){
	int r = min(n,(block+1) *SQ), l = max(1, block*SQ);
	for(int i = r;i >= l; i--){
		if(i + a[i] > r){
			last[i] = i, cnt[i] = 1;
		}else{
			last[i] = last[i+a[i]];
			cnt[i] = cnt[i+a[i]]+1;
		}
	}
}


void dfs(int v, int par){
	sub[v] = 1;
	for(int to : g[v]){
		if(to == par) continue;
		dfs(to, v);
	}
	
}


void push(int v, int vl, int vr){
	if(!lazy[v]) return;
	tree[v]+= lazy[v]*(vr-vl+1);
	if(vl != vr){
		lazy[v<<1|1]+= lazy[v];
		lazy[v<<1]+= lazy[v];
	}
	lazy[v] = 0;
}


void build(int v, int vl, int vr){
	if(vl == vr){
		tree[v] = a[vl];
	}else{
		int mid = (vl + vr)>>1;
		build(v<<1, vl, mid);
		build(v<<1|1, mid+1, vr);
	}
	tree[v] = tree[v<<1] + tree[v << 1|1];
}

void add(int l, int r, int v, int vl, int vr){
	if(l > vr or vl > r) return;
	if(l <= vl and r >= vr){
		
	} 
}


int gcd(int a, int b){
	if(a < b) swap(a, b);
	if(b == 0) return a;
	return (a, b  % a);
}

int lcm(int a, int b){
	return (a / __gcd(a, b)) * b;
}

int k(int v, int u){
	for(int to : g[v]){
		if(to == u) continue;
	}
}

main(){
   ios::sync_with_stdio(0);
   cin.tie(0); cout.tie(0);
	cin >> n >> q;
	for(int i = 1;i <=n; i++){
		cin >> a[i];
	}
	for(int i = 0; i * SQ <= n; i++){
		decompose(i);
	}
	// codeforces 13E
	while(q--){
		int type; cin >> type;
		int pos; cin >> pos;
		if(type == 0){
			cin >> a[pos];
			decompose(pos/SQ);
		}else{
			int sum = 0, pref = pos;
			while(pos <= n){
				sum+= cnt[pos];
				pos = last[pos];
				pref = pos;
				pos = pos+a[pos];
			}
			cout << pref << ' ' << sum << '\n';
		}
	}
	return 0;
}

