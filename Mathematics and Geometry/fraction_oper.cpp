#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ff first
#define ss second
#define all(a) a.begin(), a.end()
const int M = 1e9 + 7;
const int N = 1e6 + 1;
struct fraction{
	int a, b;
};
void common(fraction &A, fraction &B){
	int lcm = A.b * (B.b / __gcd(A.b, B.b));
	int k = lcm / A.b; 
	int k1 = lcm / B.b;
	A.b = lcm, B.b = lcm;
	A.a *= k, B.a*= k1;
}
void least(fraction &A){
	int g = __gcd(A.a, A.b);
	A.a/= g, A.b/= g;
}
fraction mult(fraction A, fraction B){
	fraction C = {A.a * B.a, A.b * B.b};
	least(C);
	return C;
}
fraction divide(fraction A, fraction B){
	swap(B.a, B.b);
	return mult(A, B);
}
fraction mnus(fraction A, fraction B){
	common(A,B);
	fraction C = {A.a - B.a, A.b};
	least(C);
	return C;
} 
int isProgression(int a, int b, int c){
	if(a <= b and b <= c) return 1;
	if(a >= b and b >= c) return 2;
	return 0;
}
main(){
   ios::sync_with_stdio(0);
   cin.tie(0); cout.tie(0);
	
	return 0;
}