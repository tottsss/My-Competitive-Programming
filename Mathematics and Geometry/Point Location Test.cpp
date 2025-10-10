#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ff first
#define ss second
const int INF = 1e9 + 7;
const int N = 1e5 + 1;
 
pair<int, int> mnus(pair<int, int> a, pair<int, int> b){
	return {a.ff - b.ff, a.ss - b.ss};
}
 
int mltiple(pair<int, int> a, pair<int, int> b){
	pair<int, int> ans;
	ans = {a.ff * b.ss, a.ss * b.ff};
	return (ans.ff - ans.ss);
}
 
main(){
	
	pair<int, int> s, s1, p;
	cin >> s.ff >> s.ss >> s1.ff >> s1.ss >> p.ff >> p.ss;
	pair<int, int> ans = mnus(p, s);
	pair<int,int> ans1 = mnus(p, s1);
	int res = mltiple(ans, ans1) * 1LL;
	if(res == 0) cout << "TOUCH";
	
	return 0;
}