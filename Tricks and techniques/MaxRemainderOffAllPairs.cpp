#include <bits/stdc++.h>
using namespace std;

//#define int long long
#define ff first
#define ss second
#define all(a) a.begin(), a.end()
const int N = 1e6;

int pref[2*N+10];



main(){
   ios::sync_with_stdio(0);
   cin.tie(0); cout.tie(0);
	int n; cin >> n;
	int a[n];
	for(int i = 0;i < n; i++){
		cin >> a[i];
		pref[a[i]] = a[i];
	}
	set<int> st(a, a + n);
	for(int i = 2;i <=2* N; i++){
		if(pref[i] == 0) pref[i] = pref[i-1];
	}
	int MaxRemainder = 0;
	for(int i : st){
		for(int j = i;j <= 2*N; j+= i){
			int x = pref[j-1];
			MaxRemainder = max(MaxRemainder, x%i);
		}
	}
	cout << MaxRemainder;
	return 0;
}

