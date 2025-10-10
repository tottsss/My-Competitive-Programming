#include <bits/stdc++.h>
 
using namespace std;
 
#define ff first
#define ss second
const int N = 2e5 + 1;
int len = 555;
int distinct;
vector<int> ans(N+1);
vector<int> mp(N+1);
struct query{
	int l, r, idx;
	bool operator<(query other) const
	{
        return make_pair(l / len, r) <
               make_pair(other.l / len, other.r);
    }
};
 
void add(int &elem){
	if(mp[elem] == 0) distinct++;
	mp[elem]++;
}
 
void remove(int &elem){
	mp[elem]--;
	if(mp[elem] == 0) distinct--;
}
 
vector< query > vec;
main(){
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int n, Q;
	cin >> n >> Q;
	vector<int> a(n);
	map<int, int> compress;
	int compress_cnt = 1;
	for(int i = 0;i < n; i++){
		cin >> a[i];
		if(compress[a[i]] != 0){
			a[i] = compress[a[i]];
		}else{
			compress[a[i]] = compress_cnt;
			a[i] = compress_cnt++;
		}
	}
	vec.resize(Q);
	for(int i = 0;i < Q; i++){
		cin >> vec[i].l >> vec[i].r;
		vec[i].l--;
		vec[i].r--;
		vec[i].idx = i;
	}
	sort(vec.begin(), vec.end());
	distinct++;
	int cur_l = vec[0].l;
    int cur_r = vec[0].l;
 
    mp[a[cur_l]]++;
	for(query q : vec){
		while(cur_l > q.l){
        cur_l--;
        add(a[cur_l]);
    }
    while(cur_r < q.r){
        cur_r++;
        add(a[cur_r]);
    }
	while(cur_l < q.l){
        remove(a[cur_l]);
        cur_l++;
    }
    while(cur_r > q.r){
        remove(a[cur_r]);
        cur_r--;
    }
		ans[q.idx] = distinct;
	}
 
 
	for(int i = 0;i < Q; i++){
		cout << ans[i] << "\n";
	}
	return 0;
}