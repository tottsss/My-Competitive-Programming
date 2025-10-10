#include <bits/stdc++.h>
using namespace std;

#define ff first
#define ss second
#define all(a) a.begin(), a.end()
const int N = 1e5;

int tree[4*N][27], lazy[4*N][27];
int n, q, sz[27];
string s;


void push(int base, int v, int vl, int vr){
	if(lazy[v][base] == -1) return;
	tree[v][base] = (vr-vl+1) * lazy[v][base];
	if(vl != vr){
		lazy[v<<1][base] = lazy[v][base];
		lazy[v<<1|1][base] = lazy[v][base];
	}
	lazy[v][base] = -1;
}


void update(int base, int l, int r, int x, int v, int vl, int vr){
	push(base, v, vl, vr);
	if(l > vr or vl > r) return;
	if(l <= vl and r >= vr){
		lazy[v][base] = x;
		push(base, v, vl, vr);
		return;
	}
	int mid = (vl + vr)>>1;
	update(base, l, r, x, v<<1, vl, mid);
	update(base, l, r, x, v<<1|1, mid+1, vr);
	tree[v][base] = tree[v<<1][base] + tree[v<<1|1][base];
}

int get(int base, int l, int r, int v, int vl, int vr){
	push(base, v, vl, vr);
	if(l > vr or vl > r) return 0;
	if(l <= vl and r >= vr) return tree[v][base];
	int mid = (vl + vr)>>1;
	int L = get(base, l, r, v<<1, vl, mid);
	int R = get(base, l, r, v<<1|1, mid+1, vr);
	return L+R;
}



main(){
   ios::sync_with_stdio(0);
   cin.tie(0); cout.tie(0);
	cin >> n >> q >> s;
	s = '#' + s;
	memset(lazy, -1, sizeof(lazy));
	for(int i = 1;i <= n; i++){
		update(s[i]-'a', i, i, 1, 1, 1, n);
	}
	while(q--){
		int l, r, k; cin >> l >> r >> k;
		for(char c = 'a'; c <= 'z'; c++){
			sz[c-'a'] = get(c-'a', l, r, 1, 1, n);
			update(c-'a', l, r, 0, 1, 1, n);
		}
		if(k == 0){
			int cur = l;
			for(char c = 'z'; c >='a'; c--){
				if(sz[c-'a'] > 0){
					update(c-'a', cur, cur+sz[c-'a']-1, 1,  1, 1, n);
					cur+= sz[c-'a'];	
				}
			}
		}else{
			int cur = l;
			for(char c = 'a'; c <= 'z'; c++){
				if(sz[c-'a'] > 0){
					update(c-'a', cur, cur+sz[c-'a']-1, 1,  1, 1, n);
					cur+= sz[c-'a'];	
				}
			}
		}
	}
	for(int i = 1;i <= n; i++){
		for(char c = 'a'; c <= 'z'; c++){
			if(get(c-'a', i, i, 1, 1, n) > 0){
				cout << c;
				break;
			}
		}
	}
	return 0;
}

