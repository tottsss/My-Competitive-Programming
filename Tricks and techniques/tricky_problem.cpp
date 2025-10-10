#include <bits/stdc++.h>
using namespace std;

//#define int long long
#define ff first
#define ss second
#define all(a) a.begin(), a.end()
const int N = 100000;
vector<int> g[N+10];
int cnt[N+10], pref[510][N+10];
main(){
   ios::sync_with_stdio(0);
   cin.tie(0); cout.tie(0);
	int n, q; cin >> n >> q;
	int a[n];
	for(int i = 0;i < n; i++){
		cin >> a[i];
		if(a[i] <= n){
			cnt[a[i]]++;
		} 
	}
	vector<int> need;
	for(int i = 1;i <= n; i++){
		if(cnt[i] >= i){
			need.push_back(i);
		}
	}
	for(int i = 0;i < need.size(); i++){
		for(int j = 1;j <= n; j++){
			pref[i][j]+= pref[i][j-1] + (a[j-1] == need[i]);
		}
	}
	//https://codeforces.com/problemset/problem/220/B
	while(q--){
		int l, r; cin >> l >> r;
		int c = 0;
		for(int i = 0;i < need.size(); i++){
			c+= (pref[i][r]-pref[i][l-1]==need[i]);
		}
		cout << c << '\n';
	}
	return 0;
}

