#include <bits/stdc++.h>
using namespace std;

#define ff first
#define ss second
#define all(a) a.begin(), a.end()
 
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
/*

 Дана матрица N×N, заполненная положительными числами.
  Путь по матрице начинается в левом 
  верхнем углу. За один ход можно пройти в соседнюю по 
  вертикали или горизонтали клетку (если она существует). 
  Нельзя ходить по диагонали, нельзя оставаться на месте.

Требуется найти максимальную сумму чисел, 
стоящих в клетках по пути длиной K 
(клетку можно посещать несколько раз). 


*/
main(){
	ios::sync_with_stdio(0);
	cin.tie(0);  cout.tie(0);
	int n, k; cin >> n >> k;
	vector< vector<int> > dp(n + 2, vector<int>(n + 2,0));
	vector< vector<int> > pref(n + 2, vector<int>(n +2,INT_MIN));
	vector< vector<int> > a(n + 2, vector<int>(n +2,0));
	vector< vector<int> > used(n + 2, vector<int>(n +2,0));
	for(int i = 1;i <= n; i++){
		for(int j = 1;j <= n; j++){
			cin >> a[i][j];
		}
	}
	if(k == 1){
		cout << a[1][1];
		return 0;
	}
	pref[1][1] = a[1][1];
	used[1][1] = 1;
	for(int round = 2; round <= k; round++){
		for(int i = 1;i <= n; i++){
			for(int j = 1;j <= n; j++){
				for(int go = 0; go < 4; go++){
					int ni = i + dx[go];
					int nj = j + dy[go];
					dp[i][j] = max(dp[i][j], 
							pref[ni][nj] + a[i][j]);
				}		
			}
		}
		for(int i = 1;i <= n; i++){
			for(int j = 1;j <= n; j++){
				if(dp[i][j]==0) pref[i][j] = INT_MIN;
				else
				pref[i][j] = dp[i][j];
				dp[i][j]=0;
			}
		}
	}
	int Mx = INT_MIN;
	for(int i = 1;i <= n; i++){
		for(int j = 1;j <= n; j++){
			Mx = max(Mx, pref[i][j]);
		}
	}
	cout << Mx;
	return 0;
}