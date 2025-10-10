#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ff first
#define ss second
#define all(a) a.begin(), a.end()
const int M = 1000003;
const int N = 1e6;
int n, q;
vector<pair<int, int> > query;
int fc[3*N];
main(){
   	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n >> q;
	query.resize(q);
	for(int i = 0;i < q; i++){
		cin >> query[i].ff >> query[i].ss;
	}
	fc[0] = 1, fc[1] = 1;
	for(int i = 2;i <= 2*N; i++){
		fc[i] = (fc[i-1] * i)%M;
	}
	if(q == 1){
		int x = query[0].ff;
		int y = query[0].ss;
		int len = x-1;
		int len1 = y-x+1;
		int len3 = (n-y);
		int sum = (fc[len]*fc[len1 + len3])%M;
		
		for(int i = 1;i <= len3; i++){
			sum = (sum + (fc[len+i] * fc[len1+len3-i])%M)%M;
		}
		
		cout << sum%M << '\n';
//		return 0;
	}
	vector<int> a(n);
	iota(all(a), 1);
	int sum = 0;
	do{
		int ok = 1;
		for(int j = 0;j < q; j++){
			int x = query[j].ff, y = query[j].ss;
			int cnt = 0;
			for(int i = 0;i < n; i++){
				if(a[i] < x){
					cnt++;
				}
				if(a[i] >= x and a[i] <= y and cnt != x-1){
					ok = 0;
					break;
				}
			}
			if(ok==0)break;
		}
		if(ok and sum > 119){
			for(int x : a) cout << x << ' ';
			cout << '\n';
		}
		sum+= ok;
	}while(next_permutation(all(a)));
	cout << sum%M;
	return 0;
}

