#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ff first
#define ss second
const int INF = 1e9 + 7;
 
main(){
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int n; cin >> n;
	int cnt = 0;
	while(n > 0){
		cnt+= (n / 5);
		n/= 5;
	}	
	cout << cnt;
	return 0;
}