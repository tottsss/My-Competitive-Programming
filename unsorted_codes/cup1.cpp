/*
5
93 22 70 8 43
79 95 70 87 70

*/#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ff first
#define ss second
#define all(a) a.begin(), a.end()
const int M = 1e9 + 7;
const int N = 1e6 + 1;
void solve(){
	int n; cin >> n;
	int a[n], b[n];
	for(int i = 0;i < n; i++){
		cin >> a[i];
	}
	for(int i = 0;i < n; i++){
		cin >> b[i];
	}
	sort(a, a + n);
	sort(b, b + n);
	if(a[0] > b[n-1]){
		cout << n << '\n';
		return;
	}
	if(b[0] > a[n-1]){
		cout << -n << '\n';
		return;
	}
	multiset<int> st;
	for(int i = 0;i < n; i++){
		if(a[i] > b[i]) continue;
		st.insert({a[i], i});		
	}
	int ok = n - st.size();
	ok-= st.size();
	vector<int> used(n, 0);
	for(int i = 0;i < n; i++){
		if(a[i] < b[i]){
			auto it = st.upper_bound(make_pair(a[i], -1LL));
			if(it != st.end()){
				used[i] = 1;
				ok++;
				
			}
		}else{
			
		}
	}
	for(int i = 0;i < n; i++){
		if(used[i]) continue;
		if(a[i] == b[i]){
			
		}
	}
	for(int i = 0;i < n; i++){
		if(used[i]) continue;
		if(a[i] < b[i]){
			auto it = st.lower_bound(make_pair(a[i], i+1));
			if(it != st.end()){
				used[i] = 1;
				
			}
		}
	}	
	cout << ok;
}
main(){
   ios::sync_with_stdio(0);
   cin.tie(0); cout.tie(0);
	solve();

	return 0;
}

