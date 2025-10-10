#include <bits/stdc++.h>
using namespace std;
 
int main(){
	int n;
	cin >> n;
	int k; cin >> k;
	vector<int> a(n);
	for(int i = 0;i < n; i++) cin >> a[i];
	map<int, int> mp;
	int num = 0;
	long long sum = 0;
	for(int l = 0, r = 0;r < n; r++){
		mp[a[r]]++;
		if(mp[a[r]] == 1) num++;
		while(num > k and l < n){
			mp[a[l]]--;
			if(mp[a[l]] == 0) num--;
			l++;
		}
		if(num <= k){
			sum+= (r - l + 1);
		}
	}
	cout << sum;
	return 0;
}