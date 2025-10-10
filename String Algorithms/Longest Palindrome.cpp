#include <bits/stdc++.h>
using namespace std;
 
//#define int long long
#define ff first
#define ss second
#define all(a) a.begin(), a.end()
const int M = 1e9 + 7;
const int N = 1e6 + 1;
 
main(){
   ios::sync_with_stdio(0);
   cin.tie(0); cout.tie(0);
	string s; cin >> s;
	int n = s.size();
	vector<int> odd(n), even(n);
	int left = 0, right = -1;
	for(int i = 0;i < n; i++){
		int k;
		if(right >= i){
			k = min(odd[left + right-i], right-i + 1);
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
	
	deque<char> s1; int mx = 0, idx = 0;
	for(int i = 0;i < n; i++){
		if(odd[i] > mx){
			mx = odd[i];
			idx= i;
		}
	}
	left = idx-1, right = idx+1;
	s1.push_back(s[idx]); mx--;
	while(mx > 0 and left >= 0 and right < n){
		s1.push_front(s[left]);
		s1.push_back(s[right]);
		left--, right++, mx--;
	}
	mx = 0, idx = 0;
	deque<char> s2;
	for(int i = 0;i < n; i++){
		if(even[i] > mx){
			mx = even[i];
			idx = i;
		}
	}
	left = idx-2, right = idx+1;
	if(mx > 0){
		s2.push_back(s[idx-1]);
		s2.push_back(s[idx]);
		mx--;
	}
	while(mx > 0 and left >= 0 and right < n){
		s2.push_front(s[left]);
		s2.push_back(s[right]);
		left--, right++, mx--;
	}
	if(s1.size() > s2.size()){
		for(auto ch : s1) cout <<ch;
	}else{
		for(auto ch : s2) cout << ch;
	}
	return 0;
}