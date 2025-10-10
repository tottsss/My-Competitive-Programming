#include <bits/stdc++.h>
using namespace std;

#define ff first
#define ss second
#define all(a) a.begin(), a.end()
const int N = 3e5;

int trie[N][2], Index[N];


int bit(int x, int i){
	if(x&(1<<i)) return 1;
	return 0;
}
int vertex;
void add(int x, int p){
	int cur = 0;
	for(int i = 29; i >= 0; i--){
		if(trie[cur][bit(x, i)] == -1){
			trie[cur][bit(x, i)] = ++vertex;	
		}
		cur = trie[cur][bit(x, i)];
	}
	if(Index[cur] == -1 or Index[cur] > p) Index[cur] = p;
}


int max_xor(int x){
	int cur = 0;
	for(int i = 29; i >= 0; i--){
		if(trie[cur][bit(x, i)^1] == -1){
			cur = trie[cur][bit(x, i)];
		}else{
			cur = trie[cur][bit(x, i)^1];
		}
	}
	if(Index[cur] == -1) assert(false);
	return Index[cur];
}

main(){
   ios::sync_with_stdio(0);
   cin.tie(0); cout.tie(0);
   int n;
	cin >> n;
	vector<int> a(n + 1, 0), s(n+1);
	for(int i = 1;i <= n; i++){
		cin >> a[i];
		s[i] = a[i];
	}
	for(int i = 0;i < N; i++){
		Index[i] = trie[i][0] = trie[i][1] = -1;
	}
	for(int i = 1;i <= n; i++){
		a[i]^= a[i-1];
	}
	int mx = a[1], left = 1, right = 1;
	add(0, 0);
	for(int i = 1;i <= n; i++){
		int j = max_xor(a[i]);
		if(mx < (a[i] ^ a[j])){
			mx = (a[i] ^ a[j]);
			left = j+1, right = i;
		}else if(mx == (a[i] ^ a[j])){
			if(left == j+1){
				right = min(right, i);
			}else if(left > j+1){
				left = j+1, right = i;
			}
		}
		add(a[i], i);
	}
	cout << mx << '\n';
	cout << left << ' ' << right << '\n';
	return 0;
}

