#include <bits/stdc++.h>
using namespace std;
 
int main(){
	int n;
	cin >> n;
	stack<pair<int, int> > st;
	st.push({0, 0});	
	for(int i = 0;i < n; i++){
		int x; cin >> x;
		while(!st.empty() and st.top().first >= x) st.pop();
		cout << st.top().second << " ";
		st.push({x, i+1});
	}
	return 0;
}