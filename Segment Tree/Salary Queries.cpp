#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // ????? ????. 
#include <ext/pb_ds/tree_policy.hpp> // ???????? ????? tree_order_statistics_node_update
using namespace std;
using namespace __gnu_pbds;
const int INF = 1e9 + 7;
typedef tree<pair<int, int> ,null_type,less< pair<int, int> >,rb_tree_tag,
	tree_order_statistics_node_update> ordered_set;
 
main(){
	ordered_set st;
	int n, q; cin >> n >> q;
	vector<int> a(n);
	for(int i = 0;i < n; i++){
		cin >> a[i];
		st.insert({a[i], i});
	}
	// cout<<X.order_of_key(-5)<<endl; 
	// cout<<*X.find_by_order(1)<<endl; 
	// for(pair<int, int>  x : st){
		// cout << x.first << " " <<x.second << "\n";
	// }
	while(q--){
		char ch; cin >> ch;
		if(ch == '?'){
			int a, b; cin >> a >> b;
			int lw, pw;
			lw = st.order_of_key({a, -INF});
			pw = st.order_of_key({b+1, -INF});
			int key = pw - lw;
			key = max(0, key);
			cout << key<< "\n";
		}else{
			int k, x; cin >> k >> x;
			st.erase({a[k-1], k-1});
			a[k-1] = x;
			st.insert({a[k-1], k-1});
		}
	}
	return 0;
}