#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ff first
#define ss second
#define all(a) a.begin(), a.end()




main(){
   ifstream cin("INPUT.TXT");
	ofstream cout("OUTPUT.TXT");
	int n; cin >> n;
	string s; cin >> s;
	int m = s.size();
	vector<int> B(500), g[500], left(500, 0), right(500, 0), used(500, 0);
	int c = 1;
	for(int j = m+1; j <= m + n; j++){
		B[j] = c;
		string t; cin >> t;
		for(int i = 0;i < m; i++){
			for(int k = 0; k < t.size(); k++){
				if(s[i] == t[k]){
					g[i+1].push_back(j);
					break;
				}
			}
		}
		c++;
	}
	int timer = 1;
	function<int(int)> try_kuhn=[&](int v){
		if(used[v] == timer) return 0;
		used[v] = timer;
		for(int to : g[v]){
			if(right[to] == 0){
				right[to] = v;
				left[v] = to;
				return 1;
			}
		}	
		for(int to : g[v]){
			if(try_kuhn(right[to])){
				right[to] = v;
				left[v] = to;
				return 1;
			}
		}
		
		return 0;
	};
	for(int i = 1;i <= n; i++){
		if(try_kuhn(i)){
			timer++;
		}
	}
	vector<int> ans;
	for(int i = 1;i <= n; i++){
		if(left[i] == 0){
			ans.clear();
			break;
		}
		ans.push_back(left[i]);
	}
	
	if(ans.size() != s.size()){
		cout << "NO";
	}else{
		cout << "YES" << '\n';
		for(int x : ans) cout << B[x] << ' ';
	}
	return 0;
}

