#include <bits/stdc++.h>
using namespace std;

#define ff first
#define ss second
#define all(a) a.begin(), a.end()
const int N = 2e6;

int a[N], cnt[N], mn;
int n, k;


main(){
   ios::sync_with_stdio(0);
   cin.tie(0); cout.tie(0);
	cin >> n >> k;
	for(int i = 0;i < n; i++){
		cin >> a[i];
	}
	for(int i = 0;i < k; i++){
		cnt[a[i]]++;
		while(cnt[mn]) mn++;
	}
	int ans = 5*N;
	for(int i = k;i < n; i++){
		
		ans = min(ans, mn);
		cnt[a[i-k]]--, cnt[a[i]]++;
		while(cnt[mn]) mn++;
		if(cnt[a[i-k]] > 0) continue;
		if(a[i-k] > mn) continue;
		mn = a[i-k];
		while(cnt[mn]) mn++;
	}
	ans = min(ans, mn);
	cout << ans;
	return 0;
}

