#include <bits/stdc++.h>
using namespace std;

#define ff first
#define ss second
#define all(a) a.begin(), a.end()
const int M = 1e9 + 7;
const int N = 1e6 + 1;

int A, B, C;
set<pair<int, pair<int, int>>> ans;
void equation(int a, int b, int c, int d){
	A = d-b;
	B = a-c;
	C = -1 * (A*a + B*b);
}

int OnLine(int x, int y){
	return (A*x+B*y+C==0);
}


main(){
   ios::sync_with_stdio(0);
   cin.tie(0); cout.tie(0);
	int n, K; cin >> n >> K;
	vector< pair<int, int> > a(n);
	for(int i = 0;i < n; i++){
		cin >> a[i].ff >> a[i].ss;
	}
	if(K == 1){
		cout << "Infinity";
		return 0;
	}
	for(int i = 0;i < n; i++){
		for(int j = i+1; j < n; j++){
			equation(a[i].ff, a[i].ss, a[j].ff, a[j].ss);
			int cnt = 0, i1 = -1, j1 = -1;
			for(int k = 0;k < n; k++){
				if(OnLine(a[k].ff, a[k].ss)){
					if(i1 == -1){
						i1 = k;
					}else if(j1 == -1) j1 = k;
					cnt++;
				}
			}
			if(cnt >= K){
				equation(a[i1].ff, a[i1].ss, a[j1].ff, a[j1].ss);
				ans.insert({A, {B, C}});
			}
		}
	}
	cout << (int)ans.size();
	return 0;
}

