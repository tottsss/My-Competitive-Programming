#include <bits/stdc++.h>
using namespace std;
 
#define ff first
#define ss second
#define all(a) a.begin(), a.end()
const int N = 1e6;
int n, Q, M, cnt = 0, emp = 1;
int version[300010];
long long tree[N], lazy[N]; 
int Left[N], Right[N];
//map<int, int> Left, Right;
//#define int long long

void build(int v, int vl, int vr){
	if(vl == vr){
		tree[v] = 0LL, lazy[v] = 0LL;
		return;
	}
	Left[v] = emp++; 
	Right[v] = emp++;
	int mid = (vl + vr)>>1;
	build(Left[v], vl, mid);
	build(Right[v], mid+1, vr);
//	tree[v] = (tree[Left[v]] + tree[Right[v]]);
}
int push(int v, int vl, int vr, long long x){
	int NEW = emp++;
	Left[NEW] = Left[v], Right[NEW] = Right[v];
	lazy[NEW] = lazy[v] + x;
	tree[NEW] = tree[v] + (long long)((vr-vl+1)*x*1LL);
	return NEW;
}
int add(int l, int r, long long x, int v, int vl, int vr){
	if(lazy[v]){
		if(vl != vr){
			int smid = (vl +vr)>>1;
			Left[v] = push(Left[v], vl, smid, lazy[v]);
			Right[v] = push(Right[v], smid+1, vr, lazy[v]);
		}
		lazy[v] = 0LL;
	}
	if(l > vr or vl > r) return v;
	int NEW = emp++;
	if(l <= vl and r >= vr){
		tree[NEW] = tree[v] + (long long)((vr-vl+1)*x*1LL);
		lazy[NEW] = x;
		Left[NEW] = Left[v], Right[NEW] = Right[v];
		return NEW;
	}
	int mid = (vl + vr)>>1;
	Left[NEW] = add(l, r, x, Left[v], vl, mid);
	Right[NEW] = add(l, r, x, Right[v], mid+1, vr);
	tree[NEW] = (tree[Left[NEW]] + tree[Right[NEW]]);
	return NEW;
}
long long get_sum(int l, int r, int v, int vl, int vr){
	if(lazy[v]){
		if(vl != vr){
			int smid = (vl +vr)>>1;
			Left[v] = push(Left[v], vl, smid, lazy[v]);
			Right[v] = push(Right[v], smid+1, vr, lazy[v]);
		}
		lazy[v] = 0LL;
	}	
	if(l > vr or vl > r) return 0LL;
	if(l <= vl and r >= vr){
		return tree[v];
	}
	int mid = (vl + vr)>>1;
	tree[v] = (tree[Left[v]] + tree[Right[v]]);
	return get_sum(l, r, Left[v], vl, mid) + get_sum(l, r, Right[v], mid+1, vr);
} 
// 
main(){
   ios::sync_with_stdio(0);
   cin.tie(0); cout.tie(0);
	cin >> n >> Q >> M;
	version[cnt] = emp++;
	build(version[0], 1, n);
	cnt++;
	while(Q--){
		int l, r, x; cin >> l >> r >> x;
		version[cnt] = add(l, r, x,version[cnt-1], 1, n); 
		cnt++;
	}
	while(M--){
		int pos; long long x; cin >> pos >> x;
		if(get_sum(pos, pos,version[cnt-1], 1, n) >= x){
			int l = 1, r = cnt;			
			if(get_sum(pos, pos,version[1], 1, n) >= x){
				cout << 1 << '\n';
				continue;
			}
			for(int round = 1; round <= 23 and l < r; round++){
				int mid = (l + r)>>1;
				if(get_sum(pos, pos,version[mid], 1, n) >= x){
					r = mid;
				}else l = mid;
				
			}
			r = min(r, cnt-1);
			cout << r << '\n';
		}else cout << "-1" << '\n';
	}
	return 0;
}