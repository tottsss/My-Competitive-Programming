#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ff first
#define ss second
#define all(a) a.begin(), a.end()
const int M = 1e9 + 7;
const int N = 1e6 + 1;

main(){
   ios::sync_with_stdio(0);
   cin.tie(0); cout.tie(0);
	int n, k; cin >> n >> k;
	string s; cin >> s;
	vector<int> odd(n), even(n);
	for(int i = 0;i < n; i++){
		int possible = k;
		odd[i] = 1;
		while(i-odd[i] >= 0 and i + odd[i] < n){
			if(s[i + odd[i]] != s[i-odd[i]]){
				if(possible <= 0) break;
				possible--;
			}
			odd[i]++;
		}

		even[i] = 0, possible = k;
		while(i - even[i] - 1 >= 0 and i + even[i] < n){
			if(s[i-even[i] - 1] != s[i + even[i]]){
				if(possible <= 0) break;
				possible--;
			}
			even[i]++;
		}

	}
	int S = accumulate(all(odd), 0LL);
	int S1 = accumulate(all(even), 0LL);
	cout << S + S1;
	return 0;
}

