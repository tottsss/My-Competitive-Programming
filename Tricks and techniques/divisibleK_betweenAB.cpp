#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ff first
#define ss second
#define all(a) a.begin(), a.end()




main(){
   ios::sync_with_stdio(0);
   cin.tie(0); cout.tie(0);
	int k, a, b;
	cin >> k >> a >> b;
	if(a == b){
		if(a%k==0) cout << 1;
		else cout << 0;
		return 0;
	}
	int near;
	if(a >= 0){
		near = (a + k-1) / k; near*= k;
	}else{
		near = (a-k+1) / k; near*= k;
	}
	if(near > b){
		cout << 0;
		return 0;
	}
	while(near < a) near+= k;
//	cout << near << '\n';
	b-= near;
	if(b < 0) cout << 0;
	else
	cout << b / k + 1;
	return 0;
}

