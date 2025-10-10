#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ff first
#define ss second
#define all(a) a.begin(), a.end()

const int N = 35000;
//const int N = 1e5;
int Divs[N + 10];
vector<int> prime;
void search(){
	for(int i = 2;i <= N; i++){
		if(Divs[i]==1) continue;
		for(int j = i+i; j <= N; j+= i){
			Divs[j] = 1;
		}
	}
	for(int i = 2;i <= N; i++){
		if(Divs[i]==0) prime.push_back(i);
	}
}

void solve(){
	int n; cin >> n;
	vector<int> factor, a(n);
	int cnt = 0;
	for(int i = 0;i < n; i++){
		cin >> a[i];
		cnt+= (a[i]%2==0);
	}
	if(cnt >= 2){
		cout << "YES";
		return;
	}
	cnt = 0;
	for(int i = 0;i < n; i++){
		for(int p : prime){
			if(a[i]%p==0){
				a[i]/= p;
				factor.push_back(p);
			}
			while(a[i]%p==0){
				a[i]/= p;
			}
		}
		if(a[i] > 1) factor.push_back(a[i]);
	}
	sort(all(factor));
	for(int i= 0;i < factor.size()-1; i++){
		if(factor[i]== factor[i+1]){
			cout << "YES";
			return;
		}
	}
	cout << "NO";
}

main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	search();
	int T = 1;
	 cin >> T;
	while(T--){
		solve();
		cout << '\n';
	}
	return 0;
}
