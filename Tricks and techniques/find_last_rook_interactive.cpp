#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ff first
#define ss second
#define all(a) a.begin(), a.end()
const int M = 1e9 + 7;
const int N = 1e6 + 1;
int n;
int x;
void ask(int a, int b, int c, int d){
	cout << "? " << a << ' ' << b << ' ' << c << ' ' << d << endl;
	cin >> x;
}

void print(int X, int Y){
	cout << "! " << X << ' ' << Y << endl;
}

int check(int a, int b, int c, int d){
	if(x == min(b-a+1, d-c+1)) return 0;
	return 1;
}


main(){
   ios::sync_with_stdio(0);
   cin.tie(0); cout.tie(0);
	cin >> n;
	int rowL = 1, rowR = n;
	int colL = 1, colR = n;
	while(colL+1 <= colR){
		int mid = (colR + colL) / 2;
		ask(1, n, colL, mid);
		if(check(1, n, colL, mid)){
			colR = mid;
		}else{
			colL = mid+1;
		}
			
		
	}
	// https://atcoder.jp/contests/abc269/tasks/abc269_e
	while(rowL+1 <= rowR){
		int mid = (rowR + rowL) / 2;
		ask(rowL, mid, 1, n);
		if(check(rowL, mid, 1, n)){
			rowR = mid;
		}else{
			rowL = mid+1;
		}
	}

	print(rowL, colL);
	return 0;
}

