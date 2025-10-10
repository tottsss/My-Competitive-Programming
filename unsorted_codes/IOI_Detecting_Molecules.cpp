#include "molecules.h"
#include <bits/stdc++.h>

using namespace std;
#define ff first
#define ss second
/*
4
6 8 8 7
15 17
*/

/*
4
5 5 6 6
14 15
*/

/*
4
15 17 16 18
10 20
*/

/*
4
1 10 5 4
20 21
*/
vector<int> find_subset(int l, int u, vector<int> w){
	vector<int> ans;
	int n = w.size();
	vector<pair<int ,int>> a;
	long long sum = 0;
	for(int i = 0;i < n; i++){
		a.push_back({w[i], i});
	}
	sort(a.begin(), a.end());
	int j = 0;
	for(int i = 0;i < n; i++){
		auto [x, idx] = a[i];
		sum+= x;
		while(sum > u && j < n){
			sum-= a[j].ff;
			j++;
		}
		if(sum >= l and sum <= u){
			for(int k = j; k <= i; k++){
				ans.push_back(a[k].ss);
			}
			return ans;
		}
	}
	return ans;
}


//main(){
//	int n; cin >> n;
//	vector<int> w(n);
//	for(int i = 0;i < n; i++){
//		cin >> w[i];
//	}
//	int l, u; cin >> l >> u;
//	vector<int> index = find_subset(l, u, w);
//	for(auto j : index){
//		cout << j << ' ';
//	}
//}