#include <bits/stdc++.h>
using namespace std;
#define int __int128
#define ff first
#define ss second
#define all(a) a.begin(), a.end()
const int M = 1e9 + 7;
const int N = 1e6 + 1;

__int128 read() {
    __int128 x = 0, f = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9') {
        if (ch == '-') f = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9') {
        x = x * 10 + ch - '0';
        ch = getchar();
    }
    return x * f;
}
void print(__int128 x) {
    if (x < 0) {
        putchar('-');
        x = -x;
    }
    if (x > 9) print(x / 10);
    putchar(x % 10 + '0');
}

int f(int N, int balls){
	vector< vector<int> > dp(N + 10, vector<int>(balls+10, 0));
	for(int j = 0;j <= balls; j++){
		dp[1][j] = 1;
	}
	for(int i = 2;i <= N + 1; i++){
		for(int j = 0; j <= balls; j++){
			for(int k = 0;k <= j; k++){
				dp[i][j]+= dp[i-1][j-k];
			}
		}
	}
	
	
	return dp[N][balls];
}


main(){
   ios::sync_with_stdio(0);
   cin.tie(0); cout.tie(0);
	
	int n = read(); int a = read(); int b = read();
	print( f(n+1, a) * f(n+1, b));
	return 0;
}

