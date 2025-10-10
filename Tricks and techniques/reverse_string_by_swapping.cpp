#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define int long long
typedef tree<int, null_type, less<int>, rb_tree_tag,
	tree_order_statistics_node_update> ordered_set;

#define ff first
#define ss second
#define all(a) a.begin(), a.end()
const int M = 1e9 + 7;
const int N = 1e6 + 1;
//

int many_inversion(vector<int> p){
	ordered_set st;
	int ans = 0;
	for(int i = 0;i < p.size(); i++){
		int L = st.order_of_key(p[i]);
		ans+= (int)st.size()-L;
		st.insert(p[i]);
	}
	return ans;
}


main(){
   ios::sync_with_stdio(0);
   cin.tie(0); cout.tie(0);
	int n; cin >> n;
	string s; cin >> s;
	map<char, vector<int> > mp;
	reverse(all(s));
	for(int i = 0;i < n; i++){
		mp[s[i]].push_back(i);
	}
	for(char ch = 'a'; ch <= 'z'; ch++){
		 reverse(all(mp[ch]));
	}
	vector<int> p;
	reverse(all(s));
	for(int i = 0;i < n; i++){
		p.push_back(mp[s[i]].back());
		mp[s[i]].pop_back();
	}
	cout << many_inversion(p);
	return 0;
}
