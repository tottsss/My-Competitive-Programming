#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ff first
#define ss second
#define all(a) a.begin(), a.end()




main(){
   ios::sync_with_stdio(0);
   cin.tie(0); cout.tie(0);
	int n; cin >> n;
	int a[n];
	for(int i = 0;i < n; i++){
		cin >> a[i];
	}
	stack<pair<int, int> > st;
	st.push({INT_MIN, n});
	vector<int> left(n), right(n);
	for(int i = 0;i < n; i++){
		left[i] = i, right[i] = i;
	}
	int mx = 0;
	for(int i = n-1; i >= 0; i--){
		while(a[i] <= st.top().ff){
			st.pop();
		}
		right[i] = st.top().ss;
		st.push({a[i], i});
	}
	while(st.empty() == false) st.pop();
	st.push({INT_MIN, -1});
	for(int i = 0;i < n; i++){
		while(a[i] <= st.top().ff){
			st.pop();
		}
		left[i] = st.top().ss;
		st.push({a[i], i});
	}
	for(int i = 0;i < n; i++){
		mx = max(mx, (abs(left[i] - right[i])- 1) * a[i]);
	}
	cout << mx;
	return 0;
}

