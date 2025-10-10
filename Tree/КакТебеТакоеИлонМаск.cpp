#include "bits/stdc++.h"

using namespace std;

#define N (int)1e5
int n, q;
int up1[52][N], up2[52][N], Left[N], Right[N];

int jmp1(long long k, int v) {
	for(long long i = 51; i >= 0; i --) {
		if(k-(1LL<<i)>=0) {
			v = up1[i][v];
			k -= (1LL << i);
		}
	}
	return v;
}

int jmp2(long long k, int v) {
	for(long long i = 51; i >= 0; i --) {
		if(k-(1LL<<i)>=0) {
			v = up2[i][v];
			k -= (1LL << i);
		}
	}
	return v;
}

main () {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n >> q;
	// Left.resize(n); Right.resize(n);
	for(int i = 0;i < n; i++) cin >> Left[i];
	for(int i = 0; i < 52; i ++) {
		for(int j = 0; j < n; j ++) {
			if(i==0) {
				up1[i][j] = Left[j]-1; 
			}else {
				up1[i][j] = up1[i-1][up1[i-1][j]];
			}
		}
	}
	for(int i = 0;i < n; i++) cin >> Right[i];
	for(int i = 0; i < 52; i ++) {
		for(int j = 0; j < n; j ++) {
			if(i==0) {
				up2[i][j] = Right[j]-1; 
			}else {
				up2[i][j] = up2[i-1][up2[i-1][j]];
			}
		}
	}
	while(q--){
		int x;
		long long a, b;
		int c; cin >> x >> a >> b >> c;
		if(c == 0){
			x --;
			int temp = jmp1(a,x);
			cout << jmp2(b,temp)+1 << "\n";
		}else{
			
			x --;
			int temp = jmp2(b,x);
			cout << jmp1(a,temp)+1 << "\n";
		}
	}
	return 0;
}
