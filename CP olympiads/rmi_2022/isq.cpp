#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ff first
#define ss second
#define all(a) a.begin(), a.end()
const int M = 1e9 + 7;
const int N = 1e5;
int n, m, q, sz;
vector<int> a(6 * N, -1), b(6 * N, -1);

int maxi[4 * N];
vector<int> tree[6*N], tree1[6*N];

void build(int v, int vl, int vr){
	if(vl == vr){
		maxi[v] = b[vl];
		return;
	}
	int mid = (vl + vr)>>1;
	build(v<<1,  vl, mid);
	build(v<<1 | 1, mid+1, vr);
	maxi[v] = max(maxi[v<<1],maxi[v<<1|1]);
}

int get_max(int l, int r, int v, int vl, int vr){
	if(l > vr or vl > r) return INT_MIN;
	if(l <= vl and r >= vr) return maxi[v];
	int mid = (vl + vr) >>1;
	int L = get_max(l, r, v<<1, vl, mid);
	int R = get_max(l, r, v<<1|1, mid+1,vr);
	return max(L, R);
}

void update(int v, int vl, int vr){
	if(vl == vr){
		tree[v].push_back(a[vl]);
	}else{
		int mid = (vl + vr)>>1;
		update(v<<1, vl, mid);
		update(v<<1 | 1, mid+1, vr);
		merge(all(tree[v<<1]), all(tree[v << 1 | 1]), back_inserter(tree[v]));
		tree[v].erase(unique(tree[v].begin(), tree[v].end()), tree[v].end());
	}
	
}

void update1(int v, int vl, int vr){
	if(vl == vr){
		tree1[v].push_back(b[vl]);
	}else{
		int mid = (vl + vr)>>1;
		update1(v<<1, vl, mid);
		update1(v<<1 | 1, mid+1, vr);
		
		merge(all(tree1[v<<1]), all(tree1[v << 1 | 1]), back_inserter(tree1[v]));
		tree1[v].erase(unique(tree1[v].begin(), tree1[v].end()), tree1[v].end());
//		if(is_sorted(all(tree1[v])) == false) assert(false);
	}
}


int joop(int l, int r, int x,  int v, int vl, int vr){
	if(l > vr or vl > r) return -1;
	if(l <= vl and r >= vr){
		if(tree[v].back() < x) return tree[v].back();
		int it = lower_bound(all(tree[v]), x) - tree[v].begin();
		if(it == 0){
			if(tree[v][it] < x)
		 	return tree[v][it];
		 	return -1;
		}
		if(tree[v][it] < x) return tree[v][it];
		it--;
		
		return tree[v][it];
	}else{
		int mid = (vl + vr)>>1;
		int L = joop(l, r, x, v<<1, vl, mid);
		int R = joop(l, r, x, v<<1|1, mid+1, vr);
		return max(L, R);
	}
}


int joop1(int l, int r, int x, int v, int vl, int vr){
	if(l > vr or vl > r) return -1;
	if(l <= vl and r >= vr){
		if(tree1[v].back() < x) return tree1[v].back();
		int it = lower_bound(all(tree1[v]), x) - tree1[v].begin();
		if(it == 0){
			if(tree1[v][it] < x) 
			 return tree1[v][it];
			 return -1;
		}
		if(tree1[v][it] < x) return tree1[v][it];
		it--;
		return tree1[v][it];
	}else{
		int mid = (vl + vr)>>1;
		int L = joop1(l, r, x, v<<1, vl, mid);
		int R = joop1(l, r, x, v<<1|1, mid+1, vr);
		return max(L, R);
	}
}

/*
vector< vector<int> > table(25, vector<int>(N, -M));
vector< vector<int> > table1(25, vector<int>(N, -M));
int lg[N];
void build(){
	lg[0] = lg[1] = 0;
	for(int i = 2;i <= n; i++){
		lg[i] = lg[i / 2] + 1;
	}
	for(int LOG = 0; LOG <= lg[n]; LOG++){
		for(int i = 1;i <= n; i++){
			if(LOG==0){
				table[LOG][i] = a[i];
			}else{
				table[LOG][i] = max(table[LOG-1][i], table[LOG-1][i + (1<<(LOG-1))]);
			}
		}
	}
	for(int LOG = 0; LOG <= lg[n]; LOG++){
		for(int i = 1;i <= n; i++){
			if(LOG==0){
				table1[LOG][i] = b[i];
			}else{
				table1[LOG][i] = max(table1[LOG-1][i], table1[LOG-1][i + (1<<(LOG-1))]);
			}
		}
	}
}

int query(int l, int r){
	if(l == r) return a[l];
	int d = (r-l + 1);
	d = lg[d];
	return max(table[d][l], table[d][r-(1<<d) + 1]);
}

int query1(int l, int r){
	if(l == r) return b[l];
	int d = (r-l + 1);
	d = lg[d];
	return max(table1[d][l], table1[d][r-(1<<d) + 1]);
}
*/
main(){
   ios::sync_with_stdio(0);
   cin.tie(0); cout.tie(0);
	cin >> n >> m >> q;

	sz=n;
	for(int i = 1;i <= n; i++){
		cin >> a[i];
//		if(a[i] <= 0) assert(false);
	}
	for(int i = 1;i <= n; i++){
		cin >> b[i];
//		if(b[i] <= 0) assert(false);
	}
	update(1, 1, sz);
	update1(1, 1, sz);
	build(1, 1, sz);
	while(q--){
		int A, B, C, D, answer=0; cin >> A >> B >> C >> D;
		int mx1 = get_max(C, D, 1, 1, sz); 
		for(int i = A; i <= B; i++){
			int x = joop1(C, D, m-a[i], 1, 1, sz);
			if(x != -1 and x < m-a[i]){
				answer = max(answer, (x + a[i]) % m);
			}
			 x = joop1(C, D, m, 1, 1, sz);
			if(x != -1){
				answer = max(answer, (x + a[i]) % m);
			}
			x = joop1(C, D, a[i], 1, 1, sz);
			if(x != -1){
				answer = max(answer, (x + a[i]) % m);
			}
			answer = max(answer, (a[i] + mx1) % m);
		}
		cout << answer << '\n';
	}
	return 0;
}

