#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ff first
#define ss second
#define all(a) a.begin(), a.end()
const int N = 500;
long long M = 1e18;
int weight[N+1][N+1];
set<int> has;
vector< vector<long long> > dis(N+1, vector<long long>(N+1, M));
vector<int> vertex;
int n; 

long long calc_dist(){
	long long sum = 0;
	for(int i : has){
		for(int j : has){
			sum+= dis[i][j];
		}
	}
	return sum;
}

main(){
   ios::sync_with_stdio(0);
   cin.tie(0); cout.tie(0);
	cin >> n;
	for(int i = 1;i <= n; i++){
		for(int j = 1;j <= n; j++){
			int w; cin >> w;
			weight[i][j] = w;
			dis[i][j] = w;
		}
	}
	for(int i = 0;i < n; i++){
		int x; cin >> x;
		vertex.push_back(x);
	}
//	https://codeforces.com/contest/296/problem/D
	reverse(all(vertex));
	vector<int> answer;
	for(int k = 0;k < n; k++){
		has.insert(vertex[k]);
		for(int i = 1;i <= n; i++){
			for(int j = 1;j <= n; j++){
				dis[i][j] = min(dis[i][j], dis[i][vertex[k]] + dis[vertex[k]][j]);
			}
		}
		answer.push_back(calc_dist());
	}
	reverse(all(answer));
	for(int x : answer) cout << x << " ";
	return 0;
}

