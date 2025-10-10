#include <bits/stdc++.h>
using namespace std;
//#define int long long
#define ff first
#define ss second
 
void solve(){
	string s; cin >> s;
//	s = s+'#'+s;
	int n = s.size();
	vector<int> z(n, 0);
	for(int i = 1, l = 0, r = 0; i < n; i++){
		if(r>=i) z[i] = min(z[i-l], r-i+1);
		while(i + z[i] < n and s[z[i]] == s[z[i] + i]) z[i]++;
		if(i+z[i]-1>r){
			r = i + z[i]-1;
			l = i;
		}
	}
	for(int i = 0;i < n; i++){
		if(n-i == z[i]){
			cout << i << ' ';
		}
//		cout << i << "-> " << z[i] << '\n';
	}
	cout << n;
	
}
 
 
main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int T=1;
//	 cin >> T;
	while(T--){
		solve();
		cout << '\n';
	}
	return 0;
}