#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ff first
#define ss second
#define all(a) a.begin(), a.end()

main(){
   ios::sync_with_stdio(0);
   cin.tie(0); cout.tie(0);
	int n, k; cin >> n >> k;
	int a[n];
	for(int i = 0;i < n; i++){
		cin >> a[i];
	}
	set<int> q, used;
	q.insert(0);
	used.insert(0);
	while(!q.empty()){
		int sum = *q.begin();
		q.erase(q.begin());
		if(sum != 0) k--;
		if (k==0){
			cout << sum;
			return 0;
		}
		for(int i = 0;i < n; i++){
			if(!used.count(sum + a[i])){
				q.insert(sum + a[i]);
				used.insert(sum + a[i]);
			}
		}
	}
	return 0;
}

