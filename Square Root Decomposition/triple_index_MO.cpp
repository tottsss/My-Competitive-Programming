#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ff first
#define ss second
#define all(a) a.begin(), a.end()
const int N = 2e5;
int LEN;
int n, q, a[N];
int cnt[N+5], sum;
struct query{
	int l, r, idx;
};
void del(int x){
	cnt[x]--;
	sum-= cnt[x] * (cnt[x]-1) / 2;
}
void add(int x){
	sum+= cnt[x] * (cnt[x]-1) / 2;
	cnt[x]++;
}
main(){
   ios::sync_with_stdio(0);
   cin.tie(0); cout.tie(0);
	cin >> n >> q;
	for(int i = 0;i < n; i++) cin >> a[i];
	LEN = (int)sqrt(n) + 5;
	vector<query> Q;
	vector<int> ans(q);
	for(int i = 0;i < q; i++){
		int l, r; cin >> l >> r;
		Q.push_back({l-1, r-1, i});
	}
	sort(all(Q), [&](query a, query b){
		if(a.l / LEN == b.l / LEN){
			return a.r<b.r;
		}	
		return a.l/LEN < b.l/LEN;
	});
	int left = 0, right = 0;
	add(a[0]);
	for(auto [l, r, idx] : Q){
		while(left > l){
			left--;
			add(a[left]);
		}
		while(right > r){
			del(a[right]);
			right--;
		}
		while(left < l){
			del(a[left]);
			left++;
		}
		while(r > right){
			right++;
			add(a[right]);
		}
		ans[idx] = sum;
	}
	for(int i = 0;i < q; i++){
		cout << ans[i] << '\n';
	}
	return 0;
}

