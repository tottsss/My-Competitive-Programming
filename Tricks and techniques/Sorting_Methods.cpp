#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define int long long
#define ff first
#define ss second
#define all(a) a.begin(), a.end()

typedef tree<int, null_type, less<int>, rb_tree_tag,
	tree_order_statistics_node_update> ordered_set;


int inversions(vector<int> &a){
	ordered_set st;
	int inv = 0;
	for(int i = 0;i < a.size(); i++){
		int L = st.order_of_key(a[i]);
		inv+= st.size()-L;
		st.insert(a[i]);
	}
	return inv;
}

int NVP(vector<int> &a){
	set<int> st;
	for(int i = 0;i < a.size(); i++){
		if(st.empty() == false and st.lower_bound(a[i]) != st.end()){
			st.erase(st.lower_bound(a[i]));
		}
		st.insert(a[i]);
	}
	return (int)st.size();
}

int swap_any(vector<int> a){
	vector<int> idx(a.size() + 1);
	for(int i = 0;i < a.size(); i++){
		idx[a[i]] = i;
	}
	int oper = 0;
	for(int i = 0;i < a.size(); i++){
		if(i + 1 != a[i]){
			int x = idx[i+1];
			idx[a[x]] = i, idx[a[i]] = x;
			swap(a[i], a[x]);
			oper++;
		}
	}
	return oper;
}


int move_to_front(vector<int> &a){
	int idx = -1, last = a.size();
	for(int i = a.size()-1; i >= 0; i--){
		if(a[i] == last){
			idx = i;
			break;
		}
	}
	int ok = a.size();
	for(int i = idx; i >= 0; i--){
		if(a[i] == last){
			ok--, last--;
		}
	}
	return ok;
}

main(){
   ios::sync_with_stdio(0);
   cin.tie(0); cout.tie(0);
	int n; cin >> n;
	vector<int> a(n);
	for(int i = 0;i < n; i++){
		cin >> a[i];
	}
//	At each step, choose two adjacent elements and swap them.
//	At each step, choose any two elements and swap them.
//	At each step, choose any element and move it to another position.
//	At each step, choose any element and move it to the front of the array

//	for each step calculate minimum operations to sort the array(permutation array) in increasing order
	cout << inversions(a) << ' ';
	cout << swap_any(a) << ' ';
	cout << n - NVP(a) << ' ';
	cout << move_to_front(a);
	return 0;
}

