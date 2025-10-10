#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define int long long
typedef tree<pair<int, int> , null_type, less<pair<int, int> >, rb_tree_tag,
	tree_order_statistics_node_update> ordered_set;

#define ff first
#define ss second
#define all(a) a.begin(), a.end()
const int M = 1e9 + 7;
const int N = 1e6 + 1;

vector<ordered_set> T((1<<20));
int a[(1<<20)], n, q;

void update(int pos, int x, int v, int vl, int vr){
	T[v].erase({a[pos], pos});
	T[v].insert({x, pos});
	if(vl == vr){
		a[pos] = x;
	}else{
		int mid = (vl + vr)>>1;
		if(mid >= pos)
			update(pos, x, v<<1|1, vl, mid);
		else 
			update(pos, x, (v<<1) + 2, mid+1, vr);
	}
}

int query(int l, int r, int x,  int v, int vl, int vr, bool bigger){
	if(l > vr or vl > r) return 0;
	if(l <= vl and r >= vr){
		if(T[v].empty()) return 0;
		if(bigger)
			return (int)T[v].size() - (int)T[v].order_of_key({x + 1, -N});
		else 
			return (int)T[v].order_of_key({x, -N}); 
	}
	int mid = (vl + vr)>>1;
	int A = query(l, r, x,  v<<1|1, vl, mid, bigger);
	int B = query(l, r, x , (v<<1) + 2, mid+1, vr, bigger);
	return A+B;
}

main(){
   ios::sync_with_stdio(0);
   cin.tie(0); cout.tie(0);
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	int inversion = 0;
	for(int i = 0;i < n; i++){
		int pos; cin >> pos; pos--;
		int elem = a[pos];
		
//		cout << elem << " = ";
		int lower = 0, upper = 0;
		 lower = query(0, pos, elem, 0, 0, n, true);
		 upper = query(pos, n-1, elem, 0, 0, n, false);
//		cout << lower << " " << upper << '\n';
		inversion+= lower+upper;
		update(pos, elem, 0, 0, n);
		cout << inversion << '\n';
	}
	return 0;
}

