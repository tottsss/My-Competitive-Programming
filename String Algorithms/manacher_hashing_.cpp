#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ff first
#define ss second
#define all(a) a.begin(), a.end()

const int P = 31;
const int mod = 1e9 + 7;



void solve(){
	string s; cin >> s;
	int n = s.size();
	vector<int> odd(n, 1), even(n, 0);
	vector<int> hash(n, 0LL), rev_hash(n, 0LL), pw(n, 0);
	hash[0] = (s[0] - 'a' + 1);
	pw[0] = 1;
	for(int i = 1;i < n; i++){
		hash[i] = (hash[i-1]*P + (s[i] - 'a' + 1)) % mod;
		pw[i] = (pw[i-1] * P) % mod;
	}
	reverse(all(s));
	rev_hash[0] = (s[0] - 'a' + 1);
	for(int i = 1;i < n; i++){
		rev_hash[i] = (rev_hash[i-1] * P + (s[i] - 'a' + 1)) % mod;
	}
	reverse(all(s));
	int left = -1, right = n;
	function<int(int, int)> get = [&](int l, int r){
		
		if(l > r) return -1LL;
		if(l == 0){
			return hash[r]%mod;
		}else{
			int s = 1LL * hash[r] - hash[l-1] * pw[r-l+1];
			if(s < 0) s+= mod;
			return s%mod;
		}
	};
	
	function<int(int, int)> getr = [&](int l, int r){
		l = n - 1 - l;
		r = n - 1 - r;
		if(l > r) swap(l, r);
		if(l == 0){
			return rev_hash[r]%mod;
		}else{
			int s = 1LL * rev_hash[r] - rev_hash[l-1] * pw[r-l+1];
			if(s < 0) s+= mod;
			return s%mod;
		}
	};
	int answer = 1;
	function<void(int, int)> check=[&](int l, int r){
		if(l == 0 or r== n-1){
			if(answer < r-l+1){
				answer = r-l+1;
				if(l == 0){
					left = r, right = n;
				}else{
					right = l, left = -1;
				}
			}
		}
	};
	
	
	for(int i = 0;i < n; i++){
		int l = i, r = i;
		while(l >= 0 and r < n and s[l] == s[r]){
			check(l, r);
			if(n-r-1 == 0 or l == 0){
				l--, r++;
				odd[i]++;
				continue;
			}
			if(n-r-1 == l){
				if(get(0, l-1) == getr(r+1, n-1) and answer < l*2 + r-l+1){
					answer =  l * 2 + r - l + 1;
					left = r;
					right = r+1;
				}
			}else if(l > n-r-1){
				if(get(0, n-r-2) == getr(r+1, n-1) and answer < (n-r-1)*2 + r-l+1){
					answer = (n-r-1)*2 + r-l+1;
					left = n-r-2;
					right = l;
				}
			}else{
				if(get(0, l-1) == getr(n-l, n-1) and answer < l*2 + r-l+1){
					answer = l*2 + r-l+1;
					left = r;
					right = n-l;
				}
			}
			l--, r++;
			odd[i]++;
			
		}
		l = i, r = i+1;
		while(l >= 0 and r < n and s[l] == s[r]){
			check(l, r);
			if(n-r-1 == 0 or l == 0){
				l--, r++;
				even[i]++;
				continue;
			}
			if(n-r-1 == l){
				if(get(0, l-1) == getr(r+1, n-1) and answer < l*2 + r-l+1){
					answer =  l * 2 + r - l + 1;
					left = r;
					right = r+1;
				}
			}else if(l > n-r-1){
				if(get(0, n-r-2) == getr(r+1, n-1) and answer < (n-r-1)*2 + r-l+1){
					answer = (n-r-1)*2 + r-l+1;
					left = n-r-2;
					right = l;
				}
			}else{
				if(get(0, l-1) == getr(n-l, n-1) and answer < l*2 + r-l+1){
					answer = l*2 + r-l+1;
					left = r;
					right = n-l;
				}
			}
			l--, r++;
			even[i]++;
		}
	}
	if(answer == 1){
		cout << s[0];
	}else{
		if(left >= right) right = left+1;
		for(int i = 0;i <= left; i++) cout << s[i];
		for(int i = right; i < n; i++) cout << s[i];
	}
}


main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int T = 1;
	 cin >> T;
	while(T--){
		solve();
		cout << '\n';
	}
	return 0;
}
