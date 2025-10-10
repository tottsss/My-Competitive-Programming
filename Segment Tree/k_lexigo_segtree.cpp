#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ff first
#define ss second
#define all(a) a.begin(), a.end()
const int N = 2e5;

int t[4*N][5], sz[4*N];
int n;
vector<pair<string, int>> Q;
vector<int> Xses;
map<int, int> compress;
int id;


void merge(int v){
	int vl = v<<1, vr = v<<1|1;
	sz[v] = sz[vl] + sz[vr];
	for(int i = 0;i < 5; i++){
		t[v][i] = t[vl][i];
	}
	for(int i = 0;i < 5; i++){
		t[v][(i + sz[vl]) % 5] += t[vr][i];
	}
}

void update(int pos, int val, int v, int vl, int vr){
	if(vl == vr){
		sz[v] = (val == 0 ? 0 : 1);
		t[v][0] = val;
		return;
	}
	int mid = (vl +vr)>>1;
	if(mid >= pos) update(pos, val, v<<1, vl, mid);
	else update(pos, val, v<<1|1, mid+1, vr);
	merge(v);
}



main(){
   ios::sync_with_stdio(0);
   cin.tie(0); cout.tie(0);
   id = 1;
	cin >> n;
	for(int i = 0;i < n; i++){
		string s; cin >> s;
		if(s[0] == 's') Q.push_back({s, 0});
		else{
			int x; cin >> x;
			Q.push_back({s, x});
			Xses.push_back(x);
		}
	}
	sort(all(Xses));
	Xses.erase(unique(all(Xses)), Xses.end());
	for(int x : Xses){
		compress[x] = id++;
	}
	for(auto [s, x] : Q){
		if(s[0] == 'a'){
			update(compress[x], x, 1, 1, N);
		}else if(s[0] == 'd'){
			update(compress[x], 0, 1, 1, N);
		}else{
			cout << t[1][2] << '\n';
		}
	}
	return 0;
}

