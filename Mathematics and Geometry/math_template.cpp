#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ff first
#define ss second
#define all(a) a.begin(), a.end()
int mod;
int add(int a, int b){
    a = a%mod+mod;
    b = b%mod+mod;
    return (a+b)%mod;
}
int subt(int a, int b){
    return ((a-b)%mod+mod)%mod;
}
int mult(int a, int b){
    return (a*b)%mod;
}
int binpow(int a, int b){
    if(!b) return 1;
    if(b&1) return mult(binpow(a, b-1), a);
    else{
        int c = binpow(a, b/2);
        return mult(c, c);
    }
}
int divi(int a, int b){
    return mult(a, binpow(b, mod-2));
}
int phi(int n){
	int coprime = n;
	for(int i = 2; i * i <= n; i++){
		if(n%i==0){
			while(n%i==0)n/=i;
			coprime-= (coprime / i);
		}
	}
	if(n > 1) coprime-= (coprime / n);
	return coprime;
}
// krsu 7471
main(){
   ios::sync_with_stdio(0);
   cin.tie(0); cout.tie(0);
	int n, m;
	cin >> m >> n >> mod;
	int First, Second, ans;
	if(m%2==0) First = mult(binpow(m, n-1), m / 2);
	else First = binpow(m,n);
	
	Second = (m*m + 23);
	if(m%2) Second/= 2;
	ans = mult(First, Second);
	cout << ans;
	return 0;
}

