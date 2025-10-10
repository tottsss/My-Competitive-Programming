#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ff first
#define ss second
#define all(a) a.begin(), a.end()


int subtrings(int k){
	return (k * (k+1)) / 2;
}
/*
20 3
aggccdaloaxgnakfivqd
ckjdfgdnsczhpdmilxrh
2 9
8 10
2 11
*/

main(){
   ios::sync_with_stdio(0);
   cin.tie(0); cout.tie(0);
	int n, q; cin >> n >> q;
	string a, b; cin >> a >> b;
	vector<int> p;
	for(int i = 0;i < n; i++){
		int x = a[i]-'a';
		int y = b[i]-'a';
		if(y >= x){
			p.push_back(y-x);
		}else{
			int z = 'z'-'a';
			p.push_back(z-x+1+y);
		}
	}
	while(q--){
		int left, right; cin >> left >> right;
		int last = p[left], c = 1, sum = 0;
		for(int i = left+1; i <= right; i++){
			if(last == p[i]){
				c++;
			}else{
				sum+= subtrings(c);
				c = 1;
				last = p[i];
			}
		}
		sum+= subtrings(c);
		cout << sum << '\n';
	}
	return 0;
}

