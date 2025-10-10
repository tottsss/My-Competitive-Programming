#include <bits/stdc++.h>
using namespace std;

//#define int long long
#define ff first
#define ss second
#define all(a) a.begin(), a.end()
const int M = 1e9 + 7;
const int N = 1e6 + 1;

bool isprime(int n){
	if(n == 1 or n == 2) return true;
	for(int i = 2; i * i <= n; i++){
		if(n %i==0) return false;
	}
	return true;
}

void solve(){
	int n; cin >> n;
	vector< int> g[n + 1], answer(n+1, -1);
	set<int> use; map<int, int> mask;
	vector<int> PR;
	for(int i = 1;i <= n; i++){
		use.insert(i);
		if(isprime(i) and i != 1){
			PR.push_back(i);
		}
	}
	for(int i = 1;i < n; i++){
		int a, b; cin >> a >> b;
		g[a].push_back(b); g[b].push_back(a);
	}
	if(n < 11){
		vector<int> per(n); iota(all(per), 1);
		do{
			int c = 0;
			for(int i =0 ;i < n; i++){
				int v = i + 1, u = per[i];
				for(auto to : g[v]){
					if(__gcd(u, per[to-1]) != 1){
						c = 1;
						break;
					}
				}
				if(c == 1) break;
			}
			if(c == 0) break;	
		}while(next_permutation(all(per)));
		for(auto x : per) cout << x << " ";
		return;
	}
	
	vector<int> order(n); 
	iota(all(order), 1);
	function<bool(int, int)> cmp=[&](int i, int j){
		return g[i].size()>g[j].size();
	};
	sort(all(order), cmp);
	answer[order[0]] = 1;
	use.erase(1);
	mask[1] = order[0];
	for(int i = 1;i < n; i++){
		int x = order[i];
		if(g[x].size() > 1){
			if(PR.empty() == false){
			int bc = PR.back();
			answer[x] = bc;  
			mask[bc] = x;
			use.erase(bc); 
			PR.pop_back();
			}else{
				int bc = *use.rbegin();
				answer[x] = bc;  
				mask[bc] = x;
				use.erase(bc); 	
			}
		}
	}
//	for(int i = 1;i <= n; i++){
//		cout << i << " = " << mask[i] << '\n';
//	}
	for(int i = n; i >= 2; i--){
		if(!isprime(i)){
			for(auto to : g[mask[i]]){
				if(answer[to] != -1) continue;
				int k = -1, sz = (int)use.size();
				for(auto x : use){
					if(__gcd(x, i) == 1 and isprime(x) == false){
						k = x;
						break;
					}
				}
				answer[to] = k;
				use.erase(k);
			}
		}
	}
	for(int i = 2;i <= n; i++){
		for(auto to : g[mask[i]]){
			if(answer[to] != -1) continue;
			int k = -1;
			for(auto x : use){
				if(__gcd(x, i) == 1){
					k = x;
					break;
				}
			}
			answer[to] = k;
			use.erase(k);
		}
	}
	for(auto to : g[mask[1]]){
		if(answer[to] != -1) continue;
		int k = *use.begin();
		answer[to] = k; use.erase(k);
	}
	for(int i = 1;i <= n; i++){
		if(answer[i] == -1){
			int k = *use.begin();
			answer[i] = k;
			use.erase(k);
		}
		cout << answer[i] << ' ';
		if(answer[i] == -1) assert(false);
	}
}

main(){
   ios::sync_with_stdio(0);
   cin.tie(0); cout.tie(0);
	int T; cin >> T;
	while(T--){
		solve();
		cout << '\n';
	}
	return 0;
}

