#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ff first
#define ss second
#define all(a) a.begin(), a.end()
const int M = 1e9 + 7;
const int N = 1e6 + 1;


int square(pair<int, int> a, pair<int, int> b, pair<int, int> c){
	int S = 0, S1 = 0;
	S+= (a.ff*b.ss);
	S+= (b.ff*c.ss);
	S+= (c.ff*a.ss);
	S1+= (a.ss*b.ff);
	S1+= (b.ss*c.ff);
	S1+= (c.ss*a.ff);
	return abs(S-S1);
}

main(){
   ios::sync_with_stdio(0);
   cin.tie(0); cout.tie(0);
	int T; cin >>T;
	vector<int> answer;
	for(int round = 1; round <= T; round++){
		pair<int, int> p;
		cin >> p.ff >> p.ss;
		pair<int, int> a[4];
		for(int i =0;i < 4; i++){
			cin >> a[i].ff >> a[i].ss;
		}
		int all = 0;
		int triangle = square(a[0], a[1], a[2]);
		triangle+= square(a[1], a[2], a[3]);
		
		all+= square(p, a[0], a[1]);
		all+= square(p, a[1], a[2]);
		all+= square(p, a[2], a[3]);
		all+= square(p, a[3], a[0]);
		if(all == triangle){
			answer.push_back(round);
		}
	}
	cout << answer.size() << '\n';
	return 0;
}

