#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ff first
#define ss second
#define all(a) a.begin(), a.end()
const int M = 1e9 + 7;
const int N = 1e6;


int Div[N + 10];

main(){
   ios::sync_with_stdio(0);
   cin.tie(0); cout.tie(0);
	int n; cin >> n;
	for(int i = 2;i <= N; i++){
		if(Div[i] != 0) continue;
		for(int j = i; j <= N; j+= i){
			Div[j] = i;
		}
	}
	map<int, int> mp;
	int answer = 1;
	for(int i = 2;i <= n; i++){
		int x = i;
		while(x > 1){
			int D = Div[x];
			x/= D;
			mp[D]++;
		}
	}
	for(auto x : mp){
		answer*= (x.ss+1);
		answer%= M;
	}
	cout << answer;
	return 0;
}