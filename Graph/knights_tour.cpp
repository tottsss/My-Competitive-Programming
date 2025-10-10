#include <bits/stdc++.h>
using namespace std;
#define ff first
#define ss second


int used[9][9], T = 1;
int dx[] = {1, 1, 2, 2, -1, -1, -2, -2};
int dy[] = {2, -2, 1, -1, 2, -2, 1, -1};
int in(int i, int j){
    return i >= 1 && i <= 8 && j >= 1 && j <= 8;
}

int calc(int i, int j){
	int c=0;
	for(int k = 0; k < 8; k++) {
    	int ni = i + dx[k], nj = j + dy[k];
        if(in(ni,nj) && !used[ni][nj]){
        	c++;
        }
    }
    return c;
}

void dfs(int i, int j){
    used[i][j] = T++;
    if(T == 65){
    	for (int i = 1; i <= 8; i++) {
	        for (int j = 1; j <= 8; j++) {
	            cout << used[i][j] << ' ';
	        }
	        cout << '\n';
    	}
    	exit(0);
	}
	vector<pair<int, pair<int, int> > > v;
    for(int k = 0; k < 8; k++) {
    	int ni = i + dx[k], nj = j + dy[k];
        if(in(ni,nj) && !used[ni][nj]){
        	v.push_back({calc(ni, nj), {ni, nj}});
        }
    }
    sort(v.begin(), v.end());
    for(auto to : v){
    	dfs(to.ss.ff, to.ss.ss);
	}
    T = used[i][j];
    used[i][j] = 0;
}
main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int x, y;
    cin >> x >> y;
    dfs(y, x);
    return 0;
}