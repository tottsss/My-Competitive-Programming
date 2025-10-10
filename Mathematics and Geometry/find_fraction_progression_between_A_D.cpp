#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ff first
#define ss second
#define all(a) a.begin(), a.end()
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
fraction pilus(fraction A, fraction B){
	common(A,B);
	fraction C = {A.a + B.a, A.b};
	least(C);
	return C;
} 


fraction mnus(fraction A, fraction B){
	common(A,B);
	fraction C = {A.a - B.a, A.b};
	least(C);
	return C;
} 

int in_range(fraction a, fraction c, fraction b){
	common(a, b);
	common(b,c);
	common(a,c);
	if(a.a < b.a and c.a > b.a) return 1;
	return 0;
}

void umax(fraction &a, fraction b){
	common(a,b);
	if(b.a > a.a) a = b;
}


main(){
	int a, b, c, d; cin >> a >> b >> c >> d;
	fraction First = {a, 1LL}, Last = {d, 1LL};
	fraction MAX = {a+d, 1LL}, m = {d-a, 1LL};
	fraction left = {b, 1LL}, right = {c, 1LL};
	for(int len = 2; len <= d-a; len++){
		fraction D = {d-a, len};
		vector<fraction> prg;
		fraction cur = First;
		while(true){
			if(in_range(left, right, cur)){
				prg.clear();
				break;
			}
			prg.push_back(cur);
			cur = pilus(cur, D);
			if(cur.a == Last.a and cur.b == Last.b) break;
		}
		prg.push_back(Last);
		if(prg.size() == 1) continue;
		fraction sum = {1, 1};
		for(fraction x : prg){
			sum = pilus(sum, x);
		}
		sum = mnus(sum, {1, 1});
		umax(MAX, sum);
	}
	least(MAX);
	cout << MAX.a << '/' << MAX.b;
	return 0;
}

