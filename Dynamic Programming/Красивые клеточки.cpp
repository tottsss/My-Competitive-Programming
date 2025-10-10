#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ff first
#define ss second
#define all(a) a.begin(), a.end()
const int N = 2e5;
int sumA[25][N + 10], sumB[25][N + 10];
int a[N + 10], b[N + 10];
int n, m, k;

// https://codeforces.com/group/FFCe6fCoxI/contest/100805/problem/J
/*
Misha liked the gift very much, and he immediately decided to show it to Masha. 
Together they studied the field for a long time and discussed its beauty, 
and then Masha said that she wanted to take part of the field for herself.
 She hasn't decided which one yet, so she named Misha k rectangular areas and 
 offered to give her any one. Misha estimates the steepness of the area as the 
 sum of all the numbers inside it. Before deciding which area to give Masha, 
 Misha wants to calculate the steepness of all the proposed options.

The task would have been almost impossible if Misha had not read the 
instructions attached to the checkered field. It said 
that in fact the number ci, j equals ai&bj, where a and b are two 
sequences of numbers kindly indicated in the instructions, and the 
operation & means bitwise multiplication or bitwise "And" (for the 
definition of the operation, see the "Remark" section).

*/

int getA(int bit, int l, int r){
	return sumA[bit][r]-sumA[bit][l-1];
}

int getB(int bit, int l, int r){
	return sumB[bit][r]-sumB[bit][l-1];
}

main(){
   ios::sync_with_stdio(0);
   cin.tie(0); cout.tie(0);
	cin >> n >> m >> k;
	for(int i = 1;i <= n; i++){
		cin >> a[i];
	}
	for(int j = 1;j <= m; j++){
		cin >> b[j];
	}
	for(int bit = 0; bit < 20; bit++){
		for(int i = 1;i <= n; i++){
			int x = (a[i] & (1<<bit));
			sumA[bit][i]+= sumA[bit][i-1] + (x > 0 ? 1 : 0);
		}
		for(int j = 1;j <= m; j++){
			int x = (b[j] & (1<<bit));
			sumB[bit][j]+= sumB[bit][j-1] + (x > 0 ? 1 : 0);
		}
	}
	for(int i = 0;i < k; i++){
		int a, l, b, r; cin >> a >> l >> b >> r;
		int answer = 0;
		for(int bit = 0; bit < 20; bit++){
			answer+= (getA(bit, a, b) * getB(bit, l, r) * (1<<bit));
		}
		cout << answer << '\n';
	}
	return 0;
}

