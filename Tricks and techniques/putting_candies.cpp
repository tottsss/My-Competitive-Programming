#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ff first
#define ss second
#define all(a) a.begin(), a.end()


main(){
   ios::sync_with_stdio(0);
   cin.tie(0); cout.tie(0);
	int n, k;
	cin >> n >> k;
	int x = 0;
	int a[n];
	for(int i = 0;i < n; i++){
		cin >> a[i];
	}
	function<int(int)> next=[&](int cur){
		return (cur + a[cur%n]);	
	};
	int s0 = 0, s1 = 0;
	while(true){
		s0 = next(s0);
		s1 = next(next(s1));
		k--;
		if(k == 0){
			cout << s0;
			return 0;
		}
		if(s0%n == s1%n) break;
	}
//	https://atcoder.jp/contests/abc241/tasks/abc241_e
//	cout << k << '\n';
	int cycle_sum = 0, cycle_siz = 0;
	for(s1 = next(s0); ; s1 = next(s1)){
		cycle_siz++;
		cycle_sum+= a[s1%n];
		if(s0%n == s1%n) break; 
	}
//	cout << cycle_siz << ' ' << cycle_sum << '\n';
	s0+= (k / cycle_siz)*cycle_sum;
	k%= cycle_siz;
	while(k > 0){
		s0 = next(s0);
		k--;
		if(k == 0){
			cout << s0;
			return 0;
		}
	}
	cout << s0;
	
	return 0;
}

