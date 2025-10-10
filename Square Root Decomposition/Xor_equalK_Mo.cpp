#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ff first
#define ss second
#define all(a) a.begin(), a.end()
const int N = 3*1000000;
int LEN;
struct Q{
	int l, r, idx;	
};
vector<Q> query;
vector<int> a;
int n, q, k, curL, curR, segments;
int cnt[N+1];

void add(int i){
	segments+= (cnt[a[i]^k]);
	cnt[a[i]]++;
}

void del(int i){
	cnt[a[i]]--;
	segments-= (cnt[a[i]^k]);
}

main(){
   ios::sync_with_stdio(0);
   cin.tie(0); cout.tie(0);
	cin >> n >> q >> k;
	LEN = (int)sqrt(n);
	a.resize(n + 1); a[0] = 0;
	for(int i = 1;i <= n; i++){
		cin >> a[i];
		a[i] = (a[i]^a[i-1]);
	}
	query.resize(q);
	vector<int> answer(q,-1);
	for(int i = 0;i < q; i++){
		cin >> query[i].l >> query[i].r;
		query[i].idx = i;
	}
	sort(all(query), [&](Q A, Q B){
		if(A.l / LEN == B.l / LEN){
			return A.r <B.r;
		}	
		return A.l/LEN < B.l/LEN;
	});
	curL = 1, curR = 1, segments = 0;
	add(1);
	for(auto [l,r,idx] : query){
		while(curL < l){
			del(curL);
			curL++;
		}
		while(curR > r){
			del(curR);
			curR--;
		}
		while(curL > l){
			curL--;
			add(curL);
		} 
		while(curR < r){
			curR++;
			add(curR);
		}
		add(l-1);
		answer[idx] = segments;
		del(l-1);
	}
	for(int i = 0;i < q; i++){
		cout << answer[i] << '\n';
	}
	return 0;
}