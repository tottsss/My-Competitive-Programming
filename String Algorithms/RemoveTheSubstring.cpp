#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ff first
#define ss second
#define all(a) a.begin(), a.end()
main(){
   ios::sync_with_stdio(0);
   cin.tie(0); cout.tie(0);
	string s, t; cin >> s >> t;
	vector<int> left, right;
	int n = s.size(), m= t.size();
	for(int i = 0, j = 0; i < n and j < m; i++){
		if(s[i] == t[j]){
			j++;
			left.push_back(i);
		}
	}
	for(int i = n-1, j = m-1; i >= 0 and j >= 0; i--){
		if(s[i] == t[j]){
			j--;
			right.push_back(i);
		}
	}
//	You want to remove some substring (contiguous subsequence) from s of maximum possible 
//	length such that after removing this substring t will remain a subsequence of s.
	reverse(all(right));
	int answer =max(right[0], n-1-left[m-1]);
	
	for(int i = 0;i < m-1; i++){
		answer = max(answer, abs(left[i] - left[i+1])-1);
		answer = max(answer, abs(right[i] - right[i+1])-1);
		answer = max(answer, abs(left[i] - right[i+1])-1);
	}
	cout << answer;
	return 0;
}

