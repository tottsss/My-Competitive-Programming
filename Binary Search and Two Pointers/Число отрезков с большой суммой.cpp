#include <bits/stdc++.h>
using namespace std;
#define int long long
main(){
	int n, x;
	cin >> n >> x;
	vector<int> a(n);
	for(int i = 0;i < n; i++) cin >> a[i];
	int Countsum = 0;
	int Cursum = 0;
	for(int l = 0, r = 0; r < n; r++){
		Cursum+= a[r];
		while(Cursum - a[l] >= x and l < a.size()){
			Cursum-= a[l];
			l++;
		}
		if(Cursum >= x)
			Countsum+= (l + 1);
	}
	cout << Countsum;
	
	return 0;
}