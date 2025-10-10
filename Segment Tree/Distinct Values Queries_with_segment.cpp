
#include <bits/stdc++.h>
 
#define Kanimet signed main(){
 
#define int long long
#define vi vector <int>
#define vii vector <pair<int, int>>;
#define mapi map<int, int >
#define pb push_back
#define sz size()
#define faster ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define all(x) x.begin(), x.end()
 
 
using namespace std;
 
const int N = 4e5+4;
 
int a[N], p[N];
vi t[4*N];
vi vec;
map <int, int> mp;
 
void build( int v, int tl, int tr) {
    if (tl == tr) {
        t[v].pb(p[tl]);
    } else {
        int tm = (tl + tr) / 2;
        build(v*2, tl, tm);
        build(v*2+1, tm+1, tr);
        merge(all(t[v+v]), all(t[v+v+1]), back_inserter(t[v]));
    }
}
 
int get(int v, int tl, int tr, int l, int r) {
    if(tr < l || tl > r)return 0;
    if(tr<= r && tl >= l){
    	return lower_bound(all(t[v]), l) - t[v].begin();
	}
	int mid = (tl + tr) / 2;
	return get(v+v, tl, mid, l, r) + get(v+v+1, mid+1, tr, l, r);
	
}
 
Kanimet
	faster;
	int n, q;
	cin >> n >> q;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	for(int i = 1; i <= n; i ++){
		if(mp[a[i]] == 0)p[i] = -1; 
		else p[i] = mp[a[i]];
		mp[a[i]] = i;
	}
	build( 1, 1, n);
	while(q--){
		int l, r;
		cin >> l >> r;
		cout << get (1, 1, n, l, r)<< '\n';
	}
}