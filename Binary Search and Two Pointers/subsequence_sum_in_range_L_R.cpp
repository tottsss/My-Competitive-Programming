#include <bits/stdc++.h>
#include "grader.cpp"
using namespace std;



#define ff first
#define ss second
#define all(a) a.begin(), a.end()
std::vector<int> find_subset(int L, int U, std::vector<int> w){
	int n = w.size();
//	vector< vector<int> > dp(U+1, vector<int>(n+1));
//	dp[0][0] = 1;
//	for(int i = 1;i <= n; i++){
//		for(int sum = )
//	}
	vector< pair<int, int> > a;
	for(int i = 0;i < n; i++) a.push_back({w[i], i});
	sort(all(a));
	set<pair<long long, int> > mp;
	mp.insert({0LL, -1});
	long long cursum = 0;
	vector<int> ans;
	for(int i = 0;i < n; i++){
		cursum+= a[i].ff;
		if(cursum >= L and cursum <= U){
			for(int j = 0;j <= i; j++){
				ans.push_back(a[j].ss);
			}
			return ans;
		}else if(cursum > U){
			long long Left = abs(cursum - U);
			long long Right = abs(cursum - L);
			auto it = mp.lower_bound(make_pair(min(Left, Right), -1000));
			if(it != mp.end() and it->ff <= max(Left, Right)){
				for(int j = it->ss+1; j <= i; j++){
					ans.push_back(a[j].ss);
				}
				return ans;
			}
			
		}
		mp.insert({cursum, i});
	}
	return ans;
}



//main(){
//   ios::sync_with_stdio(0);
//   cin.tie(0); cout.tie(0);
//	int L, U, N; cin >> L >> U >> N;
//	vector<int> s(N);
//	for(int i = 0;i < N; i++) cin >> s[i];
//	vector<int> ans = find_subset(L, U, s);
//	for(int x : ans) cout << x << ' ';
//	return 0;
//}

