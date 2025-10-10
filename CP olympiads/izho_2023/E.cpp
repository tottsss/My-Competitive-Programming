#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ff first
#define ss second
#define all(a) a.begin(), a.end()
const int N = 1e5;
int n, q;
vector<int> g[N+10];
int bambuk, mx_deg; 


void points(int a, int b){
	cout << a << ':' << b << '\n';
}

void subtask1(){
	for(int i = 0;i < q; i++){
		int sz; cin >> sz;
		int r; cin >> r;
		int sz1; cin >> sz1;
		int b; cin >> b;
		r--, b--;
		if(r == 0){
			points(n-1, 1);
			
		}else if(b == 0){
			points(1, n-1);
		}else{
			points(n, 0);
		}
	}
}



void subtask2(){
	for(int i = 0;i < q; i++){
		int sz; cin >> sz;
		int r; cin >> r;
		int sz1; cin >> sz1;
		int b; cin >> b;
		if(r > b){
			int A = n-r+1, B = b;
			int orto = abs(r-b)-1;
			int AA = orto - (orto/2);
			int BB = orto/2;
			if(A+B+BB+AA !=n) assert(false);
			if(orto ==0){
				points(A, B);
				continue;
			}
			if(orto == 1){
				points(n,0);
				continue;
			}
			if(B >= A and orto%2==0){
				AA--, BB++;
			}else if(orto %2==1 and A >= B){
				AA++, BB--;
			}else{
				if(orto%2==0 and A>B) AA++, BB--;
				else AA--,BB++;
			}
			if(AA+A+BB+B!=n) assert(false);
			points(AA+A, BB+B);
		}else{
			int A = r, B = n-b+1;
			int orto = abs(r-b)-1;
			int AA = orto - (orto/2);
			int BB = orto/2;
			if(A+B+BB+AA !=n) assert(false);
			if(orto ==0){
				points(A, B);
				continue;
			}
			if(orto == 1){
				points(n,0);
				continue;
			}
			if(B >= A and orto%2==0){
				AA--, BB++;
			}else if(orto %2==1 and A >= B){
				AA++, BB--;
			}else{
				if(orto%2==0 and A>B) AA++, BB--;
				else AA--,BB++;
			}
			if(AA+A+BB+B!=n) assert(false);
			points(AA+A, BB+B);
		}
	}
}

main(){
   ios::sync_with_stdio(0);
   cin.tie(0); cout.tie(0);
	cin >> n;
	for(int i = 0;i < n-1; i++){
		int a, b; cin >> a >> b;
		a--, b--;
		if(min(a, b) == 0) mx_deg++;
		if(min(a, b) == i and max(a, b) == i+1) bambuk++;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	cin >> q;
	if(mx_deg == n-1){
		subtask1();
		return 0;
	}
	if(bambuk == n-1){
		subtask2();
		return 0;
	}
	return 0;
}

