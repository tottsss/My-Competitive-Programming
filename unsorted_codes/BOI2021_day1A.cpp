#include <bits/stdc++.h>
#include "books.h"
 
 
using namespace std;
 
void solve(int N, int K, long long A, int S){
	vector<long long> a(N + 2, -1);
	set<int> st;
	for(int i = 1;i <= K; i++){
		a[i] = skim(i);
		st.insert(i);
	}
	int l = 0, r = N+1;
	while(l + 1 < r){
		int mid = (l + r)>>1;
		if(a[mid] == -1) a[mid] = skim(mid);	
		if(a[mid] >= A) r = mid;
		else l = mid;
	}
	if(r > N) r--;
	for(int i = r; i >= 1 && st.size() <= 2*K; i--){
		if(a[i] == -1) a[i] = skim(i);
		st.insert(i);
	}
	vector<int> all;
	for(int x : st) all.push_back(x);	
	for(int mask = 1; mask < (1<<(int)all.size()); mask++){
		if(__builtin_popcount(mask) != K) continue;
		long long sum = 0;
		vector<int> v;
		for(int i = 0;i < all.size(); i++){
			if(mask & (1LL<<i)){
				sum+= a[all[i]];
				v.push_back(all[i]);
			}
		}
		if(sum >= A && sum <= 2*A && v.size() == K){
			answer(v);
		}
	}
	impossible();
}

//https://cses.fi/360/task/A
 