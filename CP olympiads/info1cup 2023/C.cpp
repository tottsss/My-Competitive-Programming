#include <bits/stdc++.h>
using namespace std;

#define ff first
#define ss second
#define all(a) a.begin(), a.end()
const int N = 3e5;
set<int> st;
int n, k;
vector<int> a, p;
void f(int idx){
	if(idx >= n){
		cout << k << " = ";
		for(int x : p){
			cout << x << ' ';
		}
		cout << '\n';
		if(k==1)	exit(0);
		k--;
		return;
	}
	vector<int> can;
	for(auto it = st.lower_bound(a[idx]); it != st.end(); it++){
		can.push_back(*it);
	}
	for(int x : can){
		p.push_back(x);
		st.erase(x);
		f(idx+1);
		st.insert(x);
		p.pop_back();
	}
}

main(){
   ios::sync_with_stdio(0);
   cin.tie(0); cout.tie(0);
	cin >> n >> k;
	a.resize(n);
	for(int i = 0;i < n; i++){
		cin >> a[i];
	}
	for(int i = 1;i <= n; i++){
		st.insert(i);
	}
	f(0);
//	for(int i = 0;i < n; i++){
//		auto it = st.lower_bound(a[i]);
//		p.push_back(*it);
//		st.erase(it);
//	}
//	do{
//		k--;
////		if(k == 0){
//			for(int i= 0;i < n; i++){
//				cout << p[i] << " ";
//			}
//			cout << '\n';
//			if(k == 0)
//			return 0;
////		}
//	}while(next_permutation(all(p)));
	return 0;
}

