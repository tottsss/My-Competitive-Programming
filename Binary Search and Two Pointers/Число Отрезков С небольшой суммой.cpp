#include <bits/stdc++.h>
using namespace std;
#define int long long
 main(){
	int n, tarsum;
	cin >> n >> tarsum;
	vector<int> a(n);
	for(int i = 0;i < n; i++) cin >> a[i];
	int Countsum = 0;
	int Cursum = 0;
	for(int l = 0, r = 0; r < n; r++){
		Cursum+= a[r];
		while(l < a.size() and Cursum > tarsum){
			Cursum-= a[l];
			l++;
		}
		 Countsum+= (r - l) + 1;
	}
	cout << Countsum;
	return 0;
}