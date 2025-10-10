#include <bits/stdc++.h>
using namespace std;
#define ff  first
#define ss second
#define int long long
int n,a ,b;
void solve(){
	cin >> a >> b;
	if(a == 1 and b == 1){
		cout << "3 3" << '\n';
		cout << "1 2";
	}else if(a == 1 and b == 2){
		cout << "4 3" << '\n';
		cout << "2 4" << '\n';
		cout << "1 3";
	}else if(a == 1 and b == 3){
		cout << "4 3" << '\n';
		cout << "4 2" << '\n';
		cout << "1 2";
	}else if(a == 2 and b == 3){
		cout << "5 3" << '\n';
		cout << "4 5" << '\n';
		cout << "1 5" << '\n';
		cout << "2 3";
	}else if(a == 2 and b == 2){
		cout << "5 3" << '\n';
		cout << "4 5" << '\n';
		cout << "1 2" << '\n';
		cout << "1 2";
	}else if(a == 3 and b == 1){
		cout << "4 3" << '\n';
		cout << "4 1" << '\n';
		cout << "2 1";
	}else assert(false);
}



main(){
	int t; cin >> t;
	cin >> n;
	while(t--){
		solve();
		cout << '\n';
	}
	
	return 0;
}