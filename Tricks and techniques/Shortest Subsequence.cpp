#include <bits/stdc++.h>
using namespace std;
 
#define int long long
#define ff first
#define ss second
#define all(a) (a.begin(), a.end())
const int M = 1e9 + 7;
const int N = 1e6 + 1;
 
main(){
   ios::sync_with_stdio(0);
   cin.tie(0); cout.tie(0);
	int n;
	string s; cin >> s;
	n = s.size();
	map<char,int> mp;
	string answer, sub;
	for(int i = 0;i < n; i++){
		sub.push_back(s[i]);
		mp[s[i]]++;
		if(mp['A'] > 0 and mp['G'] > 0 and mp['C'] > 0 and mp['T'] > 0){
//			cout << i << '\n';
			sub = "";
			answer.push_back(s[i]);
			mp['A'] = 0, mp['G'] = 0, mp['C'] = 0, mp['T'] = 0;
		}
	}
	if(mp['A'] == 0) answer.push_back('A');
	else if(mp['C'] == 0) answer.push_back('C');
	else if(mp['G'] == 0) answer.push_back('G');
	else if(mp['T'] == 0) answer.push_back('T');
	else  answer.push_back('A');
	cout << answer;
	return 0;
}