#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ff first
#define ss second
#define all(a) a.begin(), a.end()
const int M = 1e9 + 7;
const int N = 1e6 + 1;

struct query{
	int l, r, idx;
};

int a[N], K[N], Len;
long long answer[N], power;
vector<query> Q;

int add(int x){
	power-= (K[x] * K[x] * x);
	K[x]++;
	power+= (K[x] * K[x] * x);
}
int sub(int x){
	power-= (K[x] * K[x] * x);
	K[x]--;
	power+= (K[x] * K[x] * x);
}

main(){
   ios::sync_with_stdio(0);
   cin.tie(0); cout.tie(0);
	int n, q; cin >> n >> q;
	Q.resize(q);
	Len = sqrt(n) + 1;
	for(int i = 0;i < n; i++){
		cin >> a[i];
	}
	for(int i = 0;i < q; i++){
		cin >> Q[i].l >> Q[i].r;
		Q[i].l--, Q[i].r--;
		Q[i].idx = i;
	}
	sort(all(Q), [&](query a, query b){
		if(a.l / Len == b.l / Len){
			return a.r < b.r;
		}	
		return (a.l / Len) < (b.l / Len);
	});
	int l = 0, r = 0;
	add(a[0]);
	for(int i = 0;i < q; i++){
		
		while(l < Q[i].l){
			sub(a[l]);
			l++;
		}
		while(r < Q[i].r){
			r++;
			add(a[r]);
		}
		while(r > Q[i].r){
			sub(a[r]);
			r--;
		}
		while(l > Q[i].l){
			l--;
			add(a[l]);
		}
		answer[Q[i].idx] = power;
	}
	for(int i = 0;i < q; i++){
		cout << answer[i] << '\n';
	}
	return 0;
}

