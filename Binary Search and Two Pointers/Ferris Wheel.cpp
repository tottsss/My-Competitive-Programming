#include <bits/stdc++.h>
using namespace std;
 
int main(){
	int n, x;
	cin >> n >> x;
	vector<int> a(n);
	int cnt = n;
	int l, r;
	l = 0;
	r = n - 1;
	for(int i = 0;i < n; i++) cin >> a[i];
	sort(a.begin(), a.end());
	while(l < r){
		if(a[l] + a[r] <= x){
			l++;
			r--;
			cnt--;
		}else{
			r--;
		}
	}
	
	cout << cnt;
	return 0;
}
 