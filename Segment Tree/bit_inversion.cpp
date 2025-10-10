#include <bits/stdc++.h>
using namespace std;
 
//#define int long long
#define ff first
#define ss second
#define all(a) a.begin(), a.end()
const int N = 2e5;
struct node{
	int sum, seg, pref, suff;
	int len;
};
node one[4 * N], zero[4*N];
int n,  A[N+1];
 
node combine(node a, node b){
	node res;
	res.sum = a.sum+b.sum;
	res.pref = a.pref, res.suff = b.suff;
	res.seg = max(a.seg, b.seg);
	res.len = a.len+b.len;
	if(a.pref == a.len){
		res.pref = a.pref + b.pref;
	}
	if(b.suff == b.len){
		res.suff = a.suff + b.suff;
	}
	res.seg = max({a.seg, b.seg, a.suff + b.pref});
	return res;
}
 
node new_node(int x){
	return {x, x, x, x, 1};
}
 
void update1(int pos, int x, int v, int vl, int vr){
	if(vl == vr){
		one[v] = new_node(x);
	}else{
		int mid =(vl + vr)>>1;	
		if(mid >= pos) 
			update1(pos, x, v<<1, vl, mid);
		else 
			update1(pos, x, v<<1|1, mid+1, vr);
		one[v] = combine(one[v<<1], one[v<<1|1]);
	}
}
 
void update0(int pos, int x, int v, int vl, int vr){
	if(vl == vr){
		zero[v] = new_node(x);
	}else{
		int mid = (vl + vr)>>1;
		if(mid >= pos)
			 update0(pos, x, v<<1, vl, mid);
		else 
		update0(pos, x, v<<1|1, mid+1, vr);
		zero[v] = combine(zero[v<<1], zero[v<<1|1]);
	}
}
main(){
   ios::sync_with_stdio(0);
   cin.tie(0); cout.tie(0);
	string s; cin >> s;
	n = s.size();
	for(int i = 1;i <= n; i++){
		A[i] = s[i-1]-'0';
		update1(i, A[i], 1, 1, n);
		update0(i, (A[i]^1), 1, 1, n);
	}
	int m; cin >> m;
	while(m--){
		int pos; cin >> pos;
		A[pos]^= 1;
		update1(pos, A[pos], 1, 1, n);
		update0(pos, (A[pos]^1), 1, 1, n);
		cout << max(zero[1].seg, one[1].seg) << '\n';
	}
	return 0;
}