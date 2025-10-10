#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ff first
#define ss second
#define all(a) a.begin(), a.end()
const int M = 1e9 + 7;
const int N = 1e6 + 1;

main(){
   ios::sync_with_stdio(0);
   cin.tie(0); cout.tie(0);
	int n; cin >> n;
	int a[n];
	vector<int> neg(n, 0), pos(n, 0);
	for(int i = 0;i < n; i++){
		cin >> a[i];
		neg[i] = (i ? neg[i-1] : 0) + (a[i]<0);
		pos[i] = (i ? pos[i-1] : 0) + (a[i]<0);
	}
	int sum = 0;
	map<int, int> mp;
	mp[0] = 1;
	for(int i = 0;i < n; i++){
		if(neg[i]%2==1){
			sum+= mp[0];
		}else{
			sum+= mp[1];
		}
		mp[neg[i]%2]++;
	}
	mp.clear();
	cout << sum << " ";
	sum = 0;
	mp[0] = 1;
	for(int i = 0;i < n; i++){
		if(neg[i]%2==0){
			sum+= mp[0];
		}else{
			sum+= mp[1];
		}
		mp[neg[i]%2]++;
	}
	cout << sum;
	return 0;
}

