#include <bits/stdc++.h>
using namespace std;

#define ff first
#define ss second
#define all(a) a.begin(), a.end()
const int N = 1e6;
//https://codeforces.com/group/COtOPg5tbB/contest/454249/problem/C
int t[4*N];

int update(int pos, int val, int v, int vl, int vr){
	if(vl == vr) t[v] = val;
	else{
		int mid = (vl + vr)>>1;
		if(mid >= pos)update(pos, val, v<<1, vl, mid);
		else update(pos, val, v<<1|1, mid+1, vr);
		t[v] = t[v<<1] + t[v<<1|1];
	}
}
int sum(int l, int r, int v, int vl, int vr){
	if(l > r) return 0;
	if(l > vr or vl > r) return 0;
	if(l <= vl and r >= vr) return t[v];
	int mid = (vl + vr)>>1;
	return sum(l, r, v<<1, vl, mid) + sum(l, r, v<<1|1, mid+1, vr);
}
int n;

long long calc(vector<int> &A, vector<int> &B){
	vector< pair<int, int> > a;
	for(int i = 0;i < n; i++) a.push_back({A[i], B[i]});
	sort(a.begin(), a.end());
	long long Sum = 0;
	for(int i = 0;i < n; i++){
		Sum+= sum(1, a[i].ss, 1, 1, N); 
		update(a[i].ss, 1, 1, 1, N);
	}
	for(int v = 0; v < 4*N; v++) t[v] = 0;
	return Sum;
}


main(){
   ios::sync_with_stdio(0);
   cin.tie(0); cout.tie(0);
	 cin >> n;
	 vector<int> a(n), b(n), c(n);
	for(int i = 0;i < n; i++){
		cin >> a[i] >> b[i] >> c[i];
	}
	long long ans = 0;
	ans-= (1LL * (n-1) * 1LL *n) / 2LL;
//	cout << calc(a, b) << '\n';
	ans+= calc(a, b);
//	cout << calc(b, c) << '\n';
	ans+= calc(b, c);
//	cout << calc(a, c) << '\n';
	ans+= calc(a, c);
	cout << ans/2;
	return 0;
}

