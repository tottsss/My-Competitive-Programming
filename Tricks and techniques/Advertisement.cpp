#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ff first
#define ss second
#define all(a) a.begin(), a.end()
const int M = 1e9 + 7;
main(){
   ios::sync_with_stdio(0);
   cin.tie(0); cout.tie(0);
	int n; cin >> n;
	int a[n];
	vector<int> left(n, -1), right(n, n);
	stack<pair<int, int> > st;
	for(int i = 0;i < n; i++){
		cin >> a[i];
		if(st.empty()){
			st.push({a[i], i});
		}else{
			while(st.empty() == false and a[i] <= st.top().ff){
				st.pop();
			}
			if(st.empty()){
				st.push({a[i], i});
				continue;
			}
			left[i] = st.top().ss;
			st.push({a[i], i});
		}
	}
	while(st.empty() == false) st.pop();
	
	for(int i = n-1;i >= 0; i--){
		if(st.empty()){
			st.push({a[i], i});
		}else{
			while(st.empty() == false and a[i] <= st.top().ff){
				st.pop();
			}
			if(st.empty()){
				st.push({a[i], i});
				continue;
			}
			right[i] = st.top().ss;
			st.push({a[i], i});
		}
	}
	int answer = 0;
	for(int i = 0;i < n; i++){
		int len = (i - left[i]);
		len+= (right[i] - i);
		len--;
		answer = max(answer, len * a[i]);
	}
	
	cout << answer;
	
	return 0;
}

