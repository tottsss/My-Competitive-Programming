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
	for(int  i = 0;i < n; i++){
		cin >> a[i];
	}
	stack<int> st;
	int ans = 0;
	for(int i = n-1; i >= 0; i--){
		while(st.empty() == false and a[i] > a[st.top()]) st.pop();
		if(st.empty() == false) ans+= st.top() - i + 1;
		st.push(i);
	}
	reverse(a, a + n);
	while(st.empty() == false ) st.pop();
	for(int i = n-1; i >= 0; i--){
		while(st.empty() == false and a[i] > a[st.top()]) st.pop();
		if(st.empty() == false) ans+= st.top() - i + 1;
		st.push(i);
	}
	cout << ans;
	return 0;
}

