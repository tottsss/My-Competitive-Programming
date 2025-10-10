#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ff first
#define ss second
#define all(a) a.begin(), a.end()
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
__int128 one = 1;

__int128 binpow(__int128 a, __int128 n, __int128 mod){
	if(a == 0) return 0;
	if(n == 0) return one;
	if(n%2==0){
		__int128 b = binpow(a, n / 2, mod);
		return (b*b)%mod;
	}else{
		return (a * binpow(a, n-1, mod))%mod;
	}
}


__int128 phi(__int128 n){
	__int128 coprime = n;
	for(__int128 i = 2; i * i <= n; i++){
		if(n%i==0){
			while(n%i==0)n/=i;
			coprime-= (coprime / i);
		}
	}
	if(n > one) coprime-= (coprime / n);
	return coprime;
}

main(){
	__int128 a;
	__int128 b;
	__int128 c;
	a = read();
	b = read();
	c = read();
	__int128 mod;
	mod = read();
	__int128 Prime = phi(mod);
	__int128 pw = binpow(b%Prime, c, Prime);
	__int128 ans = binpow(a%mod, pw, mod);
	print(ans);
	return 0;
}

