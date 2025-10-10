#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ff first
#define ss second
#define all(a) a.begin(), a.end()
const int M = 1e9 + 7;
const int N = 1e6 + 1;

main(){
   ios::sync_with_stdio(0);
   cin.tie(0); cout.tie(0);
	int n; cin >> n;
	string s; cin >> s;
	vector<int> odd(n), even(n), cnt(30, 0);
	for(int i = 0;i < n; i++){
		cnt[s[i] - 'a']++;
	}
	int left = 0, right = -1;
	for(int i = 0;i < n; i++){
		int k;
		if(right >= i){
			k = min(odd[left + right-i], right-i) + 1;
		}else{
			k = 1;
		}
		while(i + k < n and i - k >= 0 and s[i+k] == s[i-k]){
			k++;
		}
		odd[i] = k--;

		if(i + k > right){
			right = i + k, left = i - k;
		}
	}
	left = 0, right = -1;
	for(int i = 0;i < n; i++){
		int k;
		if(right >= i){
			k = min(even[left + right-i + 1], right-i + 1) + 1;
		}else{
			k = 1;
		}
		while(i + k-1 < n and i - k >= 0 and s[i+k-1] == s[i-k]){
			k++;
		}
		even[i] = --k;
		if(i + k-1 > right){
			right = i + k-1, left = i - k;
		}
	}
	long long all = (n * (n + 1)) / 2;
	long long S = accumulate(all(odd), 0LL);
	long long S1 = accumulate(all(even), 0LL), pairs = 0;
	long long answer = 1 + (all - (S + S1)), revs = (S + S1) - n;
	for(int i = 0;i < 26; i++){
		int x = cnt[i];
		pairs+= ((x * (x-1)) / 2);
	}

	answer-= max(0LL, (pairs-revs));
	answer = min(answer, all - n);
	answer = max(1LL, answer);
	cout << answer % M;
	return 0;
}

