#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ff first
#define ss second
#define all(a) a.begin(), a.end()
const int MOD = 1e9 + 7;
const int P = 31;
const int N = 2e5;
string s;
int n, q, pw[N+10];
struct node{
	int Hash = 0, revHash = 0;
	int len = 0;
};
node t[4*N];

node merge(node A, node B){
	if(A.len == -1) return B;
	if(B.len == -1) return A;
	node res = {(A.Hash + pw[A.len]*B.Hash) % MOD, (B.revHash + pw[B.len]*A.revHash) % MOD, A.len + B.len};
	return res;
};

void build(int v, int vl, int vr){
	if(vl == vr){
		t[v] = {(s[vl-1] - 'a' + 1), (s[vl-1] - 'a' + 1), 1};
		return;
	}
	int mid = (vl + vr)>>1;
	build(v<<1, vl, mid);
	build(v<<1|1, mid+1, vr);
	t[v] = merge(t[v<<1], t[v<<1|1]);
}

void update(int pos, char x, int v, int vl, int vr){
	if(vl == vr){
		t[v] = {(x - 'a' + 1), (x - 'a') + 1, 1};
		return;
	}
	int mid = (vl + vr)>>1;
	if(mid >= pos) update(pos, x, v<<1, vl, mid);
	else update(pos, x, v<<1|1, mid+1, vr);
	t[v] = merge(t[v<<1], t[v<<1|1]);
}

node get(int l, int r, int v, int vl, int vr){
	if(l > vr or vl > r) return {-1, -1, -1};
	if(l <= vl and r >=vr) return t[v];
	int mid =(vl + vr)>>1;
	return merge(get(l, r, v<<1, vl, mid), get(l, r, v<<1|1, mid+1,vr));
}
/*

abaabaaa
5
*/
main(){
   ios::sync_with_stdio(0);
   cin.tie(0); cout.tie(0);
   cin >> n >> q;
	cin >> s;
	pw[0] = 1;
	for(int i = 1;i <= N; i++){
		pw[i] = (pw[i-1] * P) % MOD;
	}
	build(1, 1, n);
	while(q--){
		int type; cin >> type;
		if(type == 1){
			int pos; cin >> pos;
			char c; cin >> c;
			update(pos, c, 1, 1, n);
		}else{
			int l, r; cin >> l >> r;
			node res = get(l, r, 1, 1, n);
			if(res.Hash == res.revHash){
				cout << "YES";
			}
			else cout << "NO";
			cout << '\n';
		}
	}
	return 0;
}

