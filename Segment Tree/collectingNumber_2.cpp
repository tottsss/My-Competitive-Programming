#include <bits/stdc++.h>
using namespace std;

//#define int long long
#define ff first
#define ss second
#define all(a) a.begin(), a.end()
const int N = 2e5;


int t[4*N+5], ans[4*N+5];

void update(int pos, int x, int v, int vl, int vr){
	if(vl == vr){
		t[v] = x;
		return;
	}
	int mid = (vl + vr)>>1;
	if(mid >= pos) update(pos, x, v<<1, vl, mid);
	else update(pos, x, v<<1|1, mid+1, vr);
	t[v] =t[v<<1] + t[v<<1|1];
}

main(){
   ios::sync_with_stdio(0);
   cin.tie(0); cout.tie(0);
	int n, q; cin >> n >> q;
	vector<int> pos(n+1), a(n+1);
	for(int i = 1;i <= n; i++){
		cin >> a[i];
		pos[a[i]] = i;
	}
	for(int i = 2;i <= n; i++){
		if(pos[i-1] > pos[i]){
			update(i-1, 1, 1, 1, n);
		}
	}
	while(q--){
		int A, B; cin >> A >> B;
		update(a[A], 0, 1, 1, n);
		update(a[B], 0, 1, 1, n);
		swap(pos[a[A]], pos[a[B]]);
		swap(a[A], a[B]);
		if(a[A] != 1){
			update(a[A]-1, 0, 1, 1, n);
		}
		if(a[B] != 1){
			update(a[B]-1, 0, 1, 1, n);
		}
		if(a[A] != n && pos[a[A]] > pos[a[A] + 1]){
			update(a[A], 1, 1, 1, n); 
		}
		if(a[A] != 1 && pos[a[A]] < pos[a[A]-1]){
			update(a[A]-1, 1, 1, 1, n);
		}
		if(a[B] != 1 && pos[a[B]] < pos[a[B]-1]){
			update(a[B]-1, 1, 1, 1, n);
		}
		if(a[B] != n && pos[a[B]] > pos[a[B] + 1]){
			update(a[B], 1, 1, 1, n);
		}
		cout << t[1]+1 << '\n';
	}
	return 0;
}

