/*
5
93 22 70 8 43
79 95 70 87 70

*/#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ff first
#define ss second
#define all(a) a.begin(), a.end()
const int M = 1e9 + 7;
const int N = 1e6 + 1;
void solve(){
	int n; cin >> n;
	int A[n], B[n];
	for(int i = 0;i < n; i++){
		cin >> A[i];
	}
	for(int i = 0;i < n; i++){
		cin >> B[i];
	}
	sort(A, A + n);
	sort(B, B + n);
	if(A[0] > B[n-1]){
		cout << n << '\n';
		return;
	}
	if(B[0] > A[n-1]){
		cout << -n << '\n';
		return;
	}
	vector<int> a, b;
	int ok =0;
	for(int i = 0;i < n; i++){
		if(A[i] <= B[i]){
			a.push_back(A[i]);
			b.push_back(B[i]);
		}else ok++;
	}
//	cout << ok << " = " << '\n';
	for(int i = 0;i < a.size(); i++){
		if(a[i] == b[i]){
			int flag = 0;
			for(int j = 0;j < i; j++){
				if(a[i] > b[j] and b[j] > a[j]){
					swap(a[i], a[j]);
					flag = 1;
					break;
				}
			}
			if(flag) continue;
			for(int j = 0;j < i; j++){
				if(a[i] > b[j] and b[j] == a[j]){
					swap(a[i], a[j]);
					flag = 1;
					break;
				}
			}
		}else{
			int flag = 0;
			for(int j = 0;j < i; j++){
				if(a[i] > b[j] and b[j] > a[j]){
					swap(a[i], a[j]);
					flag = 1;
					break;
				}
			}
			if(flag) continue;
			for(int j = 0;j < i; j++){
				if(a[i] >b[j] and b[j] == a[j]){
					swap(a[i], a[j]);
					flag = 1;
					break;
				}
			}
			if(flag) continue;
			for(int j = 0;j < i; j++){
				if(a[i] >= b[j] and b[j] > a[j]){
					swap(a[i], a[j]);
					flag = 1;
					break;
				}
			}
		}
	}
	for(int i = 0;i < a.size(); i++){
//		cout << a[i] << ' ' << b[i] << '\n';
		if(a[i] > b[i]) ok++;
		else if(a[i] < b[i]) ok--;
	}
	cout << ok;
//	for(auto e : a) cout << e << " ";
//	cout << endl;
//	for(auto e : b) cout << e << " ";
//	cout << endl;
}
main(){
   ios::sync_with_stdio(0);
   cin.tie(0); cout.tie(0);
	solve();

	return 0;
}

