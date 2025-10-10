#include "bits/stdc++.h"
using namespace std;

typedef long long ll;
#define ar array
#define int ll

const int N = 5e5 + 5;
const int M = 26;
int tree[N][M], cnt[N], last;

void add(string& s){
	int r = 0; cnt[r]++;
	for(int i=0;i<(int)s.size();i++){
		int c = s[i] - 'a';
		if(tree[r][c]){
			r = tree[r][c];
		} else {
			r = tree[r][c] = ++last;
		}
		cnt[r]++;
	}
}

int get(string& s){
	int r = 0, pref = 0;
	for(int i=0;i<(int)s.size();i++){
		int c = s[i] - 'a';
		assert(tree[r][c]);
		r = tree[r][c];
		if(cnt[r] > 1) pref++;
	}
	return pref;
}
// Karuta (atcoder) https://atcoder.jp/contests/abc287/tasks/abc287_e
signed main(){
	ios::sync_with_stdio(0); cin.tie(0);
	
	int n; cin >> n;
	vector<string> s(n);
	for(int i=0;i<n;i++){
		cin >> s[i];
		add(s[i]);
	}
	
	for(int i=0;i<n;i++){
		cout<<get(s[i])<<"\n";
	} 
}
