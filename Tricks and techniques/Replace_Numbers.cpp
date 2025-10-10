#include <bits/stdc++.h>
using namespace std;

#define ff first
#define ss second
#define all(a) a.begin(), a.end()
const int N = 5e5;
vector<int> List[N+1];
vector< pair<int, int> > arr;



/*
1620E. Replace the Numbers
You have an array of integers (initially empty).

You have to perform q

queries. Each query is of one of two types:

    "1

x" — add the element x
to the end of the array;
"2
x y" — replace all occurrences of x in the array with y

    . 

Find the resulting array after performing all the queries.

*/
main(){
   ios::sync_with_stdio(0);
   cin.tie(0); cout.tie(0);
	int q; cin >> q;
	int id = 0;
	for(int i = 0;i < q; i++){
		int type; cin >> type;
		if(type == 1){
			int x; cin >> x;
			List[x].push_back(id++);
		}else{
			int x, y; cin >> x >> y;
			if(x == y) continue;
			if(List[x].size() > List[y].size()) swap(List[y], List[x]);
			while(!List[x].empty()){
				List[y].push_back(List[x].back());
				List[x].pop_back();
			}
		}
	}
	for(int i = 1;i <= N; i++){
		for(int x : List[i]){
			arr.push_back({x, i});
		}
	}
	sort(all(arr));
	for(auto x : arr) cout << x.ss << ' ';
	return 0;
}

