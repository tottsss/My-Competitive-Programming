#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ff first
#define ss second
#define all(a) a.begin(), a.end()

main(){
   ios::sync_with_stdio(0);
   cin.tie(0); cout.tie(0);
	int n; cin >> n;
	if(n == 0){
		cout << "10";
		return 0;
	}
	if(n == 1){
		cout << "1";
		return 0;
	}
	vector<int> ans;
	for(int i = 9;i >= 2; i--){
		while(n > 1 and n%i==0){
			n/= i;
			ans.push_back(i);
		}
	}
	if(ans.empty() or n > 1){
		cout << "-1";
		return 0;
	}
	reverse(all(ans));
	for(int x : ans) cout << x; 
	return 0;
}

