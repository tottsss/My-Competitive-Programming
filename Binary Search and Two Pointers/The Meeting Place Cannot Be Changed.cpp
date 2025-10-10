#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ff first
#define ss second
#define all(a) a.begin(), a.end()
const int N = 612345;
const double eps = 0.000001;
int n;
long double x[N], v[N];

long double f(long double meet){
	long double answer = 0.0;
	for(int i = 0;i < n; i++){
		
		answer = max(answer, abs(meet-x[i]) / (v[i] * 1.0));
	}
	return answer;
}


main(){
   ios::sync_with_stdio(0);
   cin.tie(0); cout.tie(0);
   cin >> n;
   for(int i = 0;i < n; i++){
   		cin >> x[i];
   }
   for(int i = 0;i < n; i++) cin >> v[i];
   long double l =0, r = *max_element(x, x + n) + 1;
   while(r-l > eps){
   		long double m1 = (l + (r-l) / 3.0);
		long double m2 = (r - (r-l) / 3.0);
//		cout << m1 << " " << m2 << '\n';
		if(f(m1) >= f(m2)){
			l = m1;
		}else{
			r = m2;
		}
   }
	cout << fixed << setprecision(6) << min(f(l), f(r));
}

