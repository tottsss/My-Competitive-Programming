#include <bits/stdc++.h>
using namespace std;

#define int  long long
#define ff first
#define ss second
#define all(a) a.begin(), a.end()

int donkey(int q){
	int c = (q + 199)/200;
	return c*5 + (c-1)*3;
}

int horse(int q){
	int c = (q + 19)/20;
	return c+(c-1);
}

main(){
	int Q; 
	cin >> Q; 
	if(Q==0){
		cout << 0;
		return 0;
	}
	int mn = min(horse(Q), donkey(Q));
	for(int i = 1;i < Q; i++){
		mn = min(mn, 3 + horse(i) + donkey(Q-i));
	}
	cout << mn;
	return 0;
}

