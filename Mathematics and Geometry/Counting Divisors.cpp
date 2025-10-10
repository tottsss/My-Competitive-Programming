#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ff first
#define ss second
const int INF = 1e9 + 7;
 
main(){
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	vector<int> D(1e6 + 1, 1);
	for(int i = 2; i <= 1000000; i++){
		for(int j = i; j <= 1000000; j += i){
			D[j]++;
		}
	}	
	int n; cin >> n;
	while(n--){
		int x; cin >> x;
		cout << D[x] << "\n";
	}
	return 0;
}