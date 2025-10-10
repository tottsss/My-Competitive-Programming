#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ff first
#define ss second
#define all(a) a.begin(), a.end()
const int N = 1e5;
string s;
vector<int> z;
void z_function(){
	z[0] =s.size();
	for(int i = 1, l = 0, r = 0;i < s.size(); i++){
		if(r >= i){
			z[i] = min(z[i-l], r-i+1);
		}
		while(i + z[i] < s.size() and s[z[i]] == s[i+z[i]]) z[i]++;
		if(i + z[i] - 1 > r){
			r = i + z[i]-1;
			l = i;
		}
	}
}

//Your task is, for any prefix of string s which matches a suffix of string s, 
//print the number of times it occurs in string s as a substring.
main(){
   ios::sync_with_stdio(0);
   cin.tie(0); cout.tie(0);
   cin >> s;
   int n = s.size();
   for(int i = 0;i < n; i++) z.push_back(0);
	z_function();
	vector<int> cnt;
	for(int i = 0;i < n; i++){
		cnt.push_back(z[i]);
	}
	sort(all(cnt));
	map<int, int> mp;
	for(int i = 0;i < n; i++){
		if(i + z[i] >= n){
			int L = lower_bound(all(cnt),z[i]) - cnt.begin();
			mp[z[i]]+=n-L;
		}
	}
	vector< pair<int, int> > answer;
	for(auto x : mp){
		answer.push_back({x.ff, x.ss});
	}
	cout << answer.size() << '\n';
	for(auto A : answer){
		cout << A.ff << ' ' << A.ss << '\n';
	}
	return 0;
}