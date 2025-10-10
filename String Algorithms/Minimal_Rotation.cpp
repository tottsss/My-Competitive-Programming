#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ff first
#define ss second
#define all(a) a.begin(), a.end()
const int M = 1e9 + 7;
const int N = 1e6 + 1;

int MinRotation(string s){
	int a = 0, N = s.size();
	s+= s;
	for(int b = 0; b < N; b++){
		for(int k = 0;k < N; k++){
			if(a + k == b || s[a + k] < s[b + k]){
				b+= max(0LL, k-1);
				break;
			}
			if(s[a + k] > s[b + k]){
				a = b;
				break;
			}
		}
	}
	return a;
}


main(){
   ios::sync_with_stdio(0);
   cin.tie(0); cout.tie(0);
	string s; cin >> s;
	rotate(s.begin(), s.begin() + MinRotation(s), s.end());
	cout << s;
	return 0;
}

