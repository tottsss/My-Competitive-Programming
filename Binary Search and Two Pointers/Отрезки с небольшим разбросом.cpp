#include <bits/stdc++.h>
using namespace std;
#define int long long
 main(){
	int n;
	cin >> n;
	int k; cin >> k;
	vector<int> a(n);
	for(int i = 0;i < n; i++) cin >> a[i];
	multiset<int> st;
	int num;
	int num1;
	long long sum = 0;
	for(int l = 0, r = 0; r < n; r++){
		st.insert(a[r]);
		num = *st.begin();
		num1 = *st.rbegin();
		while(num1 - num > k and l < n){
			st.erase(st.find(a[l])); l++;
			if(st.empty()) assert(false);
			num = *st.begin();
			num1 = *st.rbegin();
		}
		if(st.empty()) assert(false);
		num = *st.begin();
		num1 = *st.rbegin();
		if(num1 - num <= k) sum+= (r - l + 1);
	}
	cout << sum;
	return 0;
}
