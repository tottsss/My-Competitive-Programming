#include <bits/stdc++.h>
using namespace std;
#define int __int128
int mod, p_mod;
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
bool cmp(__int128 x, __int128 y) { return x > y; }
int norm(int a){
	return (((a % mod) +mod)%mod);
}
 
int mult(int a, int b){
	return (a*b) % mod;
}
 int binpow(int a, int n, int M){
	if(n == 0) return 1;
	else if(n % 2 == 1){
		return (binpow(a, n-1, M) * a) % M;
	}else{
		int b = binpow(a, n / 2, M);
		return (b*b)%M;
	}
}
//int divide(int a, int b){
//	return mult(a, binpow(b, p_mod-1));
//}
 
 

 // 1 * (a_x - 1)
 
 // divide (a-1)
int phi(int n){
	if(n == 0) return 0;
    int c = n;
    for(int x = 2;x * x <= n + 1; x++){
        if(n % x==0){
            c = c - (c / x);
            while(n > 0 and n%x == 0){
                n/= x;
            }
        }
    }
    if(n > 1) c -= (c / n);
    return c;
} 
 
main(){
   ios::sync_with_stdio(0);
   cin.tie(0); cout.tie(0);
	int a, x; 
	a = read();
	x = read();
	mod = read();
	p_mod = phi(mod);
	if(a == 1){
		print( (a * x)%mod);
		return 0;
	}
	int s = binpow(a, x, (mod * (a-1))) - 1;
	if(s < 0) s+= (mod * (a-1));
	s /= (a - 1);
	print(s);
	return 0;
}