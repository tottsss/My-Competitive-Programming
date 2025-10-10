#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define int long long
typedef tree<int, null_type, less_equal<int>, rb_tree_tag,
	tree_order_statistics_node_update> ordered_set;

#define ff first
#define ss second
#define all(a) a.begin(), a.end()
const int M = 1e9 + 7;
const int N = 1e6 + 1;
int many_inversion(vector<int> p){
	ordered_set st;
	int ans = 0;
	reverse(all(p));
	for(int i = 0;i < p.size(); i++){
		int L = st.order_of_key(p[i]);
		if(L>0) ans++;
		st.insert(p[i]);
	}
	return ans;
}



// usaco 834
main(){
   ifstream cin("sort.in");
   ofstream cout("sort.out");
	int n; cin >> n;
	vector< pair<int, int> > p(n);
	for(int i = 0;i < n; i++){
		p[i].second = i;
		cin >> p[i].first;
	}
	sort(all(p));
//	sort(all(p), [&](pair<int, int> a, pair<int, int> b){
//			
//	});
	int answer = 0;
	for(int i = 0;i < n; i++){
		answer = max(answer, p[i].second - i);
	}
	cout << answer+1;
	return 0;
}
