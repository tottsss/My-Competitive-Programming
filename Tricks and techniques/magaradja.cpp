#include <bits/stdc++.h>
using namespace std;

#define ff first
#define ss second
#define all(a) a.begin(), a.end()




int used[11][11], row[11], col[11];
int n, k;
long long ans;
int dx[8] = {2,2,-2,-2, 1, 1, -1, -1};
int dy[8] = {1,-1, -1,1, 2, -2, -2, 2};

int in(int i, int j){
	if(min(i, j) < 0 or max(i, j) >= n) return 0;
	return 1;
}

int Plus(int i, int j){
	used[i][j]++, row[i]++, col[j]++;
	for(int x = 0; x < 8; x++){
		if(in(i+dx[x], j+dy[x])){
			used[i+dx[x]][j+dy[x]]++;
		}
	}
	int N = i, M = j;
	while(in(N, M)){
		used[N][M]++;
		N--, M--;
	}
	N = i, M = j;
	while(in(N, M)){
		used[N][M]++;
		N--, M++;
	}
	N = i, M = j;
	while(in(N, M)){
		used[N][M]++;
		N++, M--;
	}
	N = i, M = j;
	while(in(N, M)){
		used[N][M]++;
		N++, M++;
	}
}

int Minus(int i, int j){
	used[i][j]--, row[i]--, col[j]--;
	for(int x = 0; x < 8; x++){
		if(in(i+dx[x], j+dy[x])){
			used[i+dx[x]][j+dy[x]]--;
		}
	}
	int N = i, M = j;
	while(in(N, M)){
		used[N][M]--;
		N--, M--;
	}
	N = i, M = j;
	while(in(N, M)){
		used[N][M]--;
		N--, M++;
	}
	N = i, M = j;
	while(in(N, M)){
		used[N][M]--;
		N++, M--;
	}
	N = i, M = j;
	while(in(N, M)){
		used[N][M]--;
		N++, M++;
	}
}
//vector<pair<int, int> > p;
void f(int i, int j, int need){
	if(need == 0){
		ans++;
		return;
	}
	
	for(int ni = i; ni < n; ni++){
		if(row[ni]) continue;
		int nj = 0;
		for( ; nj < n; nj++){
			
			if(used[ni][nj] or col[nj]) continue;
			Plus(ni, nj);
//			p.push_back({ni, nj});
			f(ni, nj, need - 1);
//			p.pop_back();
			Minus(ni, nj);
		}
	}
}

int A[11][11] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0,
0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0,
0, 9, 0, 0, 0, 0, 0, 0, 0, 0, 0,
0, 16, 20, 0, 0, 0, 0, 0, 0, 0, 0,
0, 25, 92, 48, 2, 0, 0, 0, 0, 0, 0,
0, 36, 260, 424, 112, 0, 0, 0, 0, 0, 0,
0, 49, 580, 1976, 1754, 248, 0, 0, 0, 0, 0,
0, 64, 1120, 6616, 13074, 7320, 728, 0, 0, 0, 0,
0, 81, 1960, 17852, 63400, 82758, 34344, 3588, 72, 0, 0,
0, 100, 3192, 41544, 234014, 562384, 541324, 188440, 20084, 488, 4};

main(){
   ios::sync_with_stdio(0);
   cin.tie(0); cout.tie(0);
	cin >> n >> k;
	cout << A[n][k];
//	for(int i = 1;i <= 10; i++){
//		for(int j = 1;j <= 10; j++){
//			if(j > i){
//				A[i][j] = 0;
//				continue;
//			}
//			ans = 0;
//			n = i, k = j;
//			f(0, 0, k);
//			A[i][j] = ans;
//		}
//	}
//	for(int i = 0;i <= 10; i++){
//		for(int j = 0;j <= 10; j++){
//			cout << A[i][j] << ", ";
//		}
//		cout << '\n';
//	}
	return 0;
}

