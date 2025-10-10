#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ff first
#define ss second
#define all(a) a.begin(), a.end()




main(){
   ios::sync_with_stdio(0);
   cin.tie(0); cout.tie(0);
	int n, k; cin >> n >> k;
	vector<int> a(n), g[k];
	for(int i = 0;i < n; i++){
		cin >> a[i];
		g[i%k].push_back(a[i]);
	}
	for(int i = 0;i < k; i++){
		sort(g[i].rbegin(), g[i].rend());
	}
	sort(all(a));
	vector<int> srt;
	for(int i = 0;i < n; i++){
		srt.push_back(g[i%k].back());
		g[i%k].pop_back();
	}
	if(srt == a) cout << "Yes";
	else cout << "No";
	return 0;
}

