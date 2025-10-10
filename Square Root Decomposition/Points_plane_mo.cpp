#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ff first
#define ss second
#define all(a) a.begin(), a.end()
int SQ, n;

struct node{
	int x, y, id;
};
vector<node> a;

bool cmp(node a, node b){
	if(a.x / SQ != b.x / SQ){
		return a.x/SQ<b.x/SQ;
	}
	return a.y<b.y;
}

// codeforces (576C) Points On plane
main(){
   ios::sync_with_stdio(0);
   cin.tie(0); cout.tie(0);
   cin >> n;
   SQ = (int)sqrt(n+n);
	for(int i = 0;i < n; i++){
		int x, y; cin >> x >> y;
		a.push_back({x, y, i});
	}
	sort(all(a), cmp);
	for(int i = 0;i < n; i++){
		cout << a[i].id+1 << ' ';
	}
	return 0;
}

