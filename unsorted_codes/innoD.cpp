#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ff first
#define ss second
#define all(a) a.begin(), a.end()

main(){
   ios::sync_with_stdio(0);
   cin.tie(0); cout.tie(0);
	int push; cin >> push;
	// 0 - AB
	// 1 - BC
	
	// 0 - AB
	// 1 - CD
	if(push == 1){
		int t, n, m, k; cin >> t >> n >> m >> k;
		if(k == 3){
			
		}else if(k == 4){
			while(t--){
				string s; cin >> s;
				for(int i = 0;i < s.size(); i++){
					if(s[i] == '0'){
						cout << "AB";
					}else{
						cout << "CD";
					}
				}
				cout << '\n';
			}
		}
	}else{
		int t, n, m, k; 
		cin >> t >> n >> m >> k;
		if(k == 3){
			
		}else{
			while(t--){
				string s; cin >> s;
				
			}
		}
	}
	return 0;
}

