#include <bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
#define all(a) a.begin(), a.end()
const int N = 1e5;
const int mod = 1e9 + 7;
int par[N+10];
int dp[N+10];
int P[N+10];
pair<int, int> Divs[N+10];
pair<int, int> get_min(int a, int b, int c){
	if(a < b and a < c){
		return {a, min(b, c)};
	}else if(b < a and b < c){
		return {b, min(a, c)};
	}else{
		return {c, min(a, b)};
	}
}
int find_set(int v){
	if(v == par[v]) return v;
	return par[v] = find_set(par[v]);
}
void union_set(int a, int b){
	a = find_set(a);
	b = find_set(b);
	if(a ==b) return;
	par[b] = a;
}

void solve(){
	long long last, sum;
	for(int n = 1;n <= 5500; n++){
		
		if(n != 1 and !P[n]){
			sum = last+1;
		}else{
			for(int i = 1;i <= n; i++) par[i] = i;
			 sum = 0;
			for(int i = n/2;i >= 1; i--){
				for(int j = i+i;j <= n; j+= i){
					if(find_set(i) != find_set(j)){
						sum+= i;
						union_set(i, j);
					}
				}
			}
		}
		last = sum;
	}
	
}


main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	for(int i = 2;i <= N; i++){
		if(P[i]) continue;
		for(int j = i+i;j <= N; j+= i){
			P[j] = 1;
		}
	}
	ofstream cout("a.out");
	solve();
	return 0;
}
