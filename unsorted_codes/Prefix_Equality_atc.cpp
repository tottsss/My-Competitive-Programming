#include <bits/stdc++.h>
using namespace std;

//#define int long long
#define ff first
#define ss second
#define all(a) a.begin(), a.end()
const int M = 1e9 + 7;
const int N = 3e5 + 1;
int n, a[N], b[N], pa[N], pb[N];
int lg[N], table[25][N], table1[25][N];

void build(){
	lg[0] = lg[1] = 0;
	for(int i = 2;i <= n; i++){
		lg[i] = lg[i/2]+1;
	}
	for(int LOG = 0; LOG <= lg[n]; LOG++){
		for(int i = 0;i < n; i++){
			if(LOG == 0){
				table[LOG][i] = pa[i];
			}else{
				table[LOG][i] = max(table[LOG-1][i], table[LOG-1][i + (1<<(LOG-1))]);
			}
		}
	}
	for(int LOG = 0; LOG <= lg[n]; LOG++){
		for(int i = 0;i < n; i++){
			if(LOG == 0){
				table1[LOG][i] = pb[i];
			}else{
				table1[LOG][i] = max(table1[LOG-1][i], table1[LOG-1][i + (1<<(LOG-1))]);
			}
		}
	}
}



int get_max(int l, int r){
	int d = lg[r-l+1];
	return max(table[d][l], table[d][r-(1<<d)+1]);
}
int get_max2(int l, int r){
	int d = lg[r-l+1];
	return max(table1[d][l], table1[d][r-(1<<d)+1]);
}
main(){
   ios::sync_with_stdio(0);
   cin.tie(0); cout.tie(0);
	map<int, int> ma, mb;
	 cin >> n;
	 for(int i = 0;i < n; i++){
	 	cin >> a[i];
	 }
	 for(int i = 0;i < n; i++){
	 	cin >> b[i];
	 }
	for(int i = 0;i < n; i++){
		if(ma.count(a[i])==false) ma[a[i]] = i;
		if(mb.count(b[i]) == false) mb[b[i]] = i;
	} 
	for(int i = 0;i < n; i++){
		if(mb.count(a[i])) pa[i] = mb[a[i]];
		else pa[i] = n;
		
		if(ma.count(b[i])) pb[i] = ma[b[i]];
		else pb[i] = n;
	}
	
	build();
	int q; cin >> q;
	while(q--){
		int x, y; cin >> x >> y; x--, y--;
		
		if(y >= get_max(0, x) and x >= get_max2(0, y)) cout << "Yes";
		else cout << "No";
		
		cout << '\n';
	}
	return 0;
}

