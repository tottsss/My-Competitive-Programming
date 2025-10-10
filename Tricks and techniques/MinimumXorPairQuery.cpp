#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ff first
#define ss second
#define all(a) a.begin(), a.end()
const int mod = 1e9 + 7;
const int N = 1e5;

main(){
   ios::sync_with_stdio(0);
   cin.tie(0); cout.tie(0);
	int q; cin >> q;
	multiset<int> xors;
	multiset<int> st;
	while(q--){
		int type; cin >> type;
		if(type == 1){
			int x; cin >> x;
			if(st.empty()){
				st.insert(x);
				continue;
			}
			auto it = st.upper_bound(x);
			auto it1 = it;
			it1--;
			if(it == st.begin()){
				xors.insert(x ^ *it);
			}else if(it == st.end()){
				xors.insert(x ^ *it1);
			}else{
				xors.insert(x ^ *it);
				xors.insert(x ^ *it1);
				xors.erase(xors.find(*it ^ *it1));
			}
			st.insert(x);
		}else if(type == 2){
			int x; cin >> x;
			if(st.size() == 1){
				st.erase(x);
				continue;
			}
			st.erase(st.find(x));
			auto it = st.upper_bound(x);
			auto it1 = it;
			it1--;
			if(it == st.begin()){
				xors.erase(xors.find(x ^ *it));
			}else if(it == st.end()){
				xors.erase(xors.find(x ^ *it1));
			}else{
				xors.erase(xors.find(x ^ *it1));
				xors.erase(xors.find(x ^ *it));
				xors.insert(*it ^ *it1);
			}
			
		}else{
			cout << *xors.begin() << '\n';
		}
	}
	return 0;
}

