#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ff first
#define ss second
#define all(a) a.begin(), a.end()
const int INF = 2e18;

main(){
   ios::sync_with_stdio(0);
   cin.tie(0); cout.tie(0);

	int n, k;
	cin >> n >> k;
	int p[k];
	for(int i = 0;i < k; i++){
		cin >> p[i];
	}
	int all = 0;
	for(int mask = 1; mask < (1<<k); mask++){
		int gc = 1;
		for(int i = 0;i < k; i++){
			if(mask & (1<<i)){
				if(1. * gc * p[i] >= INF){
					gc = INF;
					break;
				}else{
					gc = gc * p[i];
				}
			}
		}
		if(gc > n) continue;
		if(__builtin_popcount(mask) % 2 == 1){
			all+= n / gc;
		}else{
			all-= (n / gc);
		}
	}
	cout << all;
	return 0;
}

