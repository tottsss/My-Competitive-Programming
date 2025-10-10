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
   cin >> n;
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
	for(int centre = 0; centre < n; centre++){
		// problem : https://acmp.ru/index.asp?main=task&id_task=259
		int l = 0, r = n+2;
		while(l + 1 < r){
			int mid = (l + r)>>1;
			int left = centre - mid + 1;
			int right = centre;
			
			if(mid <= n and left >= 0 and right < n and right >= left and get(0, mid-1, hash) == getr(left, right,rev_hash)){
				l = mid;
			}else r = mid;
		}
		cout<< l << " ";
	}
	return 0;
}

