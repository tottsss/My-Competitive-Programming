#include <bits/stdc++.h>
using namespace std;

//#define int long long
#define ff first
#define ss second
#define all(a) a.begin(), a.end()
const int M = 1e9 + 7;
const int N = 1e6 + 1;


long double square(pair<int, int> a, pair<int, int> b, pair<int, int> c){
	int S = 0, S1 = 0;
	S+= (a.ff*b.ss);
	S+= (b.ff*c.ss);
	S+= (c.ff*a.ss);
	S1+= (a.ss*b.ff);
	S1+= (b.ss*c.ff);
	S1+= (c.ss*a.ff);
	S-= S1;
	if(S<0) S*= -1;
	return (S*1.0);
}

main(){
   ios::sync_with_stdio(0);
   cin.tie(0); cout.tie(0);
   
	pair<int, int> p;
	cin >> p.ff >> p.ss;
	int T; cin >>T;
	vector<int> answer;
	for(int round = 1; round <= T; round++){
		pair<int, int> a[3];
		for(int i =0;i < 3; i++){
			cin >> a[i].ff >> a[i].ss;
		}
		long double all = 0;
		long double triangle = square(a[0], a[1], a[2]);
		vector<pair<int, int> > points; points.push_back(p);
		
		for(int i = 0;i < 3; i++){
			if(a[i].ff == p.ff and a[i].ss == p.ss){
				all = INT_MIN;
			}
			for(int j =  0;j < 3; j++){
				if(i == j) continue;
				points.push_back(a[j]);
			}
			int s = square(points[0], points[1], points[2]);
			if(s == 0) all = INT_MIN;
			all+= s;
			points.pop_back();
			points.pop_back();
		}
		
		if(all == triangle){
			answer.push_back(round);
		}
	}
	cout << answer.size() << '\n';
	for(auto x : answer){
		cout << x << ' ';
	}
	return 0;
}

