#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ff first
#define ss second
#define all(a) a.begin(), a.end()
map<int, int> mem;
int m; 
vector<int> a;
int calc(int x){
	if(mem.count(x)) return mem[x];
	int res = 0;
	for(auto d : a){
		if(x % d == 0){
			if(d % 2 == 0){
				res = 1;
			}else{
				if(!calc(x / d)) res = 1;
			}
		}
		if(res) break;
	}
	return mem[x] = res;
}


main(){
   ios::sync_with_stdio(0);
   cin.tie(0); cout.tie(0);
	int n; cin >> n;
	cin >> m;
	a.resize(m);
	for(auto &e : a) cin >> e;
	cout << (calc(n) == 1 ? "First" : "Second");

	return 0;
}

