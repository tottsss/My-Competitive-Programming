#include <bits/stdc++.h>
using namespace std;
 
#define int long long
#define ff first
#define ss second
#define all(a) (a.begin(), a.end())
const int M = 1e9 + 7;
const int N = 1e6 + 1;
 
vector<int> prefix_function(string s){
	int n = s.size();
	vector<int> p(n,0);
	for(int i = 1;i < n; i++){
		int j = p[i-1];
		while(j > 0 && s[i] != s[j]) j = p[j-1];
		if(s[i] == s[j]) j++;
		p[i] = j;
	}
	return p;
}
 
vector<int> z_function(string s){
	int n = (int)s.size();
	vector<int> z (n);
	for(int i=1, l=0, r=0; i<n; ++i){
		if(i <= r)
			z[i] = min (r-i+1, z[i-l]);
		while(i+z[i] < n && s[z[i]] == s[i+z[i]])
			++z[i];
		if(i+z[i]-1 > r)
			l = i,  r = i+z[i]-1;
	}
	return z;
}
 
 
 
 
main(){
   ios::sync_with_stdio(0);
   cin.tie(0); cout.tie(0);
	string s; cin >> s;
	vector<int> z = z_function(s);
	vector<int> p = prefix_function(s);
	for(auto x : z) cout << x << ' ';
	cout << '\n';
	for(auto x : p) cout << x << " "; 
	return 0;
}