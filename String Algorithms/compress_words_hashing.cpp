#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ff first
#define ss second
#define all(a) a.begin(), a.end()
const int N = 1e6;
int P = 424243;
int mod = 1000000007;
int pw[N+5];
vector<int> str_hash(N+5, 0LL), all_hash;
int n;
void Hash(string &s){
	str_hash[0] = s[0];
	for(int i = 1;i < s.size(); i++){
		str_hash[i] = (str_hash[i-1] * P + s[i]) % mod;
	}
}
int get(int l, int r){
	if(l == 0){
		return str_hash[r];
	}else{
		int s = (((str_hash[r] - str_hash[l-1] * pw[r-l+1]) % mod) + mod) %mod;
		return s;
	}
}

int getr(int l, int r){
	if(l == 0){
		return all_hash[r];
	}else{
		int s = (((all_hash[r] - all_hash[l-1] * pw[r-l+1]) % mod) + mod) %mod;
		return s;
	}
}


main(){
   ios::sync_with_stdio(0);
   cin.tie(0); cout.tie(0);
   cin >> n;
	pw[0] = 1;
	for(int i = 1;i <= N; i++){
		pw[i] = (pw[i-1] * P) % mod;
	}
	vector<string> a(n);
	for(auto &e : a) cin >> e;
	string ans = "";
	
	all_hash.push_back(a[0][0]);
	for(int i = 1;i < a[0].size(); i++){
		all_hash.push_back((all_hash.back() * P + a[0][i]) % mod);
	}
	ans+= a[0];
	for(int i = 0;i+1 < n; i++){
		Hash(a[i+1]);
		int l = 0;
		for(int mid = 1; mid <= min(all_hash.size(), a[i+1].size()); mid++){
			if(getr(all_hash.size()-mid, all_hash.size()-1) == get(0, mid-1)){
				l = mid;
			}
		}
		for(int j = l; j < a[i+1].size(); j++){
			all_hash.push_back((all_hash.back() * P + a[i+1][j]) % mod);
			ans.push_back(a[i+1][j]);
		}
	}
	cout << ans;
	return 0;
}

