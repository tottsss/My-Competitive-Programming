#include <bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
#define all(a) a.begin(), a.end()
#define int long long
const int M = 1e9+7;
const int P = 29;
const int N = 1e5;

int pw[N+10], A[N+10],B[N+10];

int get_A(int l, int r){
	return (((A[r]-A[l-1]*pw[r-l+1])%M)+M)%M;
}

int get_B(int l, int r){
	return (((B[r]-B[l-1]*pw[r-l+1])%M)+M)%M;
}

main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	string a, b; cin >> a >> b;
	pw[0] = 1;
	for(int i = 1;i <=N; i++){
		pw[i] = (pw[i-1]*P)%M;
	}
	if(a.size() > b.size()) swap(a,b);
	for(int i = 1;i <= a.size(); i++){
		A[i] = A[i-1] + pw[i] * (a[i-1]-'a');
		A[i]%= M;
	}
	for(int i = 1;i <= b.size(); i++){
		B[i] = B[i-1] + pw[i] * (b[i-1] - 'a');
		B[i]%=M;
	}
	string sub = "";
	int divisor = 0;
	for(int i = 0;i < a.size(); i++){
		sub.push_back(a[i]);
		if((int)a.size()%(int)sub.size() != 0 or (int)b.size()%(int)sub.size() != 0){
			continue;
		}
//		cout << sub << endl;
		int l = i+1, ok = 1;
		while(l + sub.size()-1 < a.size()){
//			cout << l << ' ' << l + sub.size()-1 << '\n';
//			cout << get_A(1, i+1) << " = " << get_A(l+1, l + sub.size()) << '\n';
			if(get_A(1, i+1) != get_A(l+1, l + sub.size())){
				ok = 0;
				break;
			}
			l+= sub.size();
		}
		if(ok==0)continue;
		l = 0;
		while(l + sub.size()-1 < b.size()){
			if(get_A(1, i+1) != get_B(l + 1,l+sub.size())){
				ok = 0;
				break;
			}
			l+= sub.size();
		}
		if(ok) divisor++;
	}
	cout << divisor;
	return 0;
}

