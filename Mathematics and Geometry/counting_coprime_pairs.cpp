#include <bits/stdc++.h>
using namespace std;

#define ff first
#define ss second
#define all(a) a.begin(), a.end()
int N;
long long cnt[(int)1e6 + 1];
int mp[(int)1e6 + 1];
main(){
   ios::sync_with_stdio(0);
   cin.tie(0); cout.tie(0);
	int n; cin >> n;
	int a[n];
	for(int i = 0;i < n; i++){
		cin >> a[i];
		mp[a[i]]++;
	}
	N = *max_element(a, a + n);
	for(int i = 1; i <= N; i++){
		for(int j = i; j <= N; j+= i){
			cnt[i]+= mp[j];
		}
		if(cnt[i] > 0)
		cnt[i] = cnt[i]*(cnt[i]-1) / 2;
	}
	for(int i = N; i >= 1; i--){
		if(cnt[i] == 0) continue;
		for(int j = i+i;j <= N; j+= i){
			cnt[i]-= cnt[j];
		}
	}
	cout << cnt[1];
	return 0;
}

