#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ff first
#define ss second
#define all(a) a.begin(), a.end()
const int M = 1e9 + 7;
const int N = 1e6 + 1;

main(){
   ios::sync_with_stdio(0);
   cin.tie(0); cout.tie(0);
	int n; cin >> n;
	vector<int> answer(n);
	vector< pair<int, pair<int, int> > > A(n);
	set< pair<int, int> > rooms; 
	priority_queue<pair<int, int> > pq;
	for(int i = 0;i < n; i++){
		A[i].ss.ss = i; cin >> A[i].ff >> A[i].ss.ff;
	}
	sort(all(A));
	pq.push({-A[0].ss.ff,-A[0].ss.ss}); answer[A[0].ss.ss] = 1;
	int cur = 2;
	for(int i = 1;i < n; i++){
		pair<int, int> Top = pq.top(); Top.ff *= -1; Top.ss*= -1;
		if(Top.ff < A[i].ff){
			answer[A[i].ss.ss] = answer[Top.ss];
			pq.pop();
			pq.push({-A[i].ss.ff, -A[i].ss.ss});
		}else{
			answer[A[i].ss.ss] = cur;
			pq.push({-A[i].ss.ff, -A[i].ss.ss});
			cur++;
		}
	}

	set<int> st(all(answer));
	cout << st.size() << '\n';
	for(auto x : answer) cout << x << " ";
	return 0;
}

