#include <bits/stdc++.h>
using namespace std;
 
 
int main(){
	string s;
	cin >> s;
	int n = s.size();
	int l = 0;
	int r = 0;
	vector<int> z(n, 0);
	for(int i = 1;i < n; i++){
		if(i <= r){
			z[i] = min(r - i + 1, z[i - l]);
		}
		while(i + z[i] < n and s[z[i]] == s[i + z[i]]) z[i]++;
		if(i + z[i] - 1 > r){
			r = i + z[i] - 1;
			l = i;
		}
	}
	vector<int> ans;
	for(int i = 0; i < n; i++){
		if(i + z[i]  == n) ans.push_back(z[i]);
	}
	sort(ans.begin(), ans.end());
	for(int i = 0;i < ans.size(); i++){
		cout <<ans[i] << " ";
	}
	return 0;
}