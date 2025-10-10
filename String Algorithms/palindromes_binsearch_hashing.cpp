#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ff first
#define ss second
#define all(a) a.begin(), a.end()

int P = 255;
int mod = 1e9 + 7;
int pw[(int)1e6 + 1];
int n;
string s;
int get(int l, int r, vector<int>&hash){
	if(l == 0){
		return hash[r];
	}else{
		int s = (((hash[r] - hash[l-1] * pw[r-l+1]) % mod) + mod) %mod;
		return s;
	}
}

int getr(int l, int r, vector<int>&hash){
	l = n-1-l, r = n - 1 - r;
	if(l > r) swap(l, r);
	if(l == 0){
		return hash[r];
	}else{
		int s = (((hash[r] - hash[l-1] * pw[r-l+1]) % mod) + mod) %mod;
		return s;
	}
}


main(){
   ios::sync_with_stdio(0);
   cin.tie(0); cout.tie(0);
	cin >> s;
	n = s.size();
	vector<int> hash(n, 0LL), rev_hash(n, 0LL);
	pw[0] = 1;
	for(int i = 1;i < n; i++){
		pw[i] = (pw[i-1] * P) % mod;
	}
	hash[0] = s[0];
	rev_hash[0] = s[n-1];
	for(int i = 1;i < n; i++){
		hash[i] = (hash[i-1] * P + s[i])%mod;
	}
	reverse(all(s));
	for(int i = 1; i < n; i++){
		rev_hash[i] = (rev_hash[i-1] * P + s[i])%mod;
	}
	reverse(all(s));
	int ans = 0;
	for(int centre = 0; centre < n; centre++){
		int l = 0, r = centre+2;
		while(l + 1 < r){
			int mid = (l + r)>>1;
			int left = centre- mid + 1;
			int right = centre + mid-1;
			
			if(left >= 0 and  right < n and right >= left and get(left, right, hash) == getr(left, right,rev_hash)){
				l = mid;
			}else r = mid;
		}
		ans+= l;
		if(centre == 0) continue;
		l = 0, r = centre+2;
		while(l + 1 < r){
			int mid = (l + r)>>1;
			int left = centre - mid;
			int right = centre + mid-1;
			if(left >= 0 and  right < n and right >= left and get(left, right, hash) == getr(left, right,rev_hash)){
				l = mid;
			}else r = mid;
		}
		ans+= l;
		
	}
	cout << ans;
	return 0;
}

