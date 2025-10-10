#pragma GCC target("popcnt")
/*
bitset<200> b;
b[33] = true;
cout << b._Find_first() << endl;


*/
#include <bits/stdc++.h>
using namespace std;
#define int long long
main(){
   ios::sync_with_stdio(0);
   cin.tie(0); cout.tie(0);
	int n; cin >> n;
	vector< bitset<3005> > A(n);
	for(int i = 0;i < n; i++){
		string s; cin >> s;
		A[i] = bitset<3005>(s);
	}
	int cnt = 0;
	for(int r = 0; r < n; r++){
		for(int R = r+1; R < n; R++){
			int C = (A[r] & A[R]).count();
			cnt+= ( (C * (C-1)) / 2);
		}
	}
	cout << cnt;
	return 0;
}

