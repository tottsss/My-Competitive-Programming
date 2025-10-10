#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ff first
#define ss second
#define all(a) a.begin(), a.end()
const int M = 1e9 + 7;
const int N = 1e6 + 1;

bool IN(pair<int,int> A, pair<int, int> B, int r){
	int s = (A.ff - B.ff); s*= s;
	int s1 = (B.ss - A.ss); s1*= s1;
	return (s + s1 <= r);
}

int manhettan(pair<int, int> A, pair<int, int> B){
	return abs(A.ff - B.ff) +abs(A.ss - B.ss);
}


main(){
   int n, l; cin >> n >> l;
	pair<int, int> A, B; cin >> A.ff>> A.ss >> B.ff >> B.ss;
	if(n == 0) assert(false);
	vector<pair<int, int> > a(n), points;
	for(int i = 0;i < n; i++){
		cin >> a[i].ff >> a[i].ss;
	}
	sort(all(a));
	int Mx = 0;
	int Mn = INT_MAX;
	for(int i = 0;i < n; i++){
		Mn = min(Mn, manhettan(A, a[i]));
		Mn = min(Mn, manhettan(B, a[i]));
		if(a[i].ff >= A.ff and a[i].ff <= B.ff){
			points.push_back(a[i]);
		}
	}
	
	if(points.empty()){
		Mx+= Mn;
		cout << fixed << setprecision(4);
		cout << (long double)Mx * 1.0 / 2.0;
		return 0;
	}
	
	Mx =manhettan(A, points[0]);
	for(int i = 1;i < points.size(); i++){
		Mx = max(Mx, manhettan(points[i], points[i-1]));
	}
	if(points.empty() == false)
	Mx = max(Mx, manhettan(B, points.back()));
	
	
	cout << fixed << setprecision(4);
	cout << (long double)Mx * 1.0 / 2.0;
	
	return 0;
}

