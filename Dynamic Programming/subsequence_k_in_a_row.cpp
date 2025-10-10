#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ff first
#define ss second
#define all(a) a.begin(), a.end()
const int M = 1e9 + 7;
const int N = 1e6 + 1;

main(){
   ios::sync_with_stdio(0);
   cin.tie(0); cout.tie(0);
   // find the number of subsequence that has no ones in a row of size k
   // https://informatics.msk.ru/mod/statements/view.php?id=2499&chapterid=2996#1
	int n; cin >> n;
	int k; cin >> k;
	vector<int> one(n+1,0), two(n+1,0);
	one[1] = 1, two[1] = 1;
	for(int i = 2;i < k; i++){
		one[i] = one[i-1] + two[i-1];
		two[i] = one[i-1] + two[i-1];
	}
	for(int i = k;i <= n; i++){
		for(int j = 1;j < k; j++){
			one[i] += two[i-j];
//			two[i]+= one[i-j];
		}
		two[i] = one[i-1] + two[i-1];
	}
	cout << one[n]+two[n];
	return 0;
}

