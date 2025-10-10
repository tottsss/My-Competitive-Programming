/*
ID: tazhiba1
LANG: C++
TASK: palsquare
*/


#include <bits/stdc++.h>
using namespace std;

//#define int long long0
#define ff first
#define ss second
#define all(a) a.begin(), a.end()

int ispal(string s){
	string rev = s;
	reverse(all(rev));
	return (rev == s);
}
pair<string, string> toBase(int x, int base){
	if(base == 10) return make_pair(to_string(x), to_string(x));
	string s = "", s1 = "";
	while(x > 0){
		int t = (x % base);
		if(t < 10)
			s.push_back(char(t+'0'));
		else s.push_back(char('A' + (t-10)));
		string t1 = to_string(t);
//		reverse(all(t1));
		for(auto ch : t1){
			s1.push_back(ch);
		}
		x/= base;
	}
	reverse(all(s));
	return make_pair(s, s);
}

main(){
   ios::sync_with_stdio(0);
   cin.tie(0); cout.tie(0);
	ifstream cin("palsquare.in");
	ofstream cout("palsquare.out");
	int B; cin >> B;
	
	for(int i = 1;i <= 300; i++){
		
		pair<string, string> ans = toBase(i * i, B);
		pair<string, string> ans1 = toBase(i, B);
		if(ispal(ans.ss)){
			cout << ans1.ff << ' ' << ans.ff << '\n';
		}
	}
	
	return 0;
}

