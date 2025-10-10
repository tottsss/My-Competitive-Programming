#include <bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
#define all(a) a.begin(), a.end()

/*

* */

void move(int &i, int &j, char ch){
	if(ch == 'L') j--;
	else if(ch == 'R') j++;
	else if(ch == 'U') i--;
	else i++;
}
void solve(){
	int n, q; cin >> n >> q;
	char rw[n+1], cl[n+1];
	for(int i = 1; i <= n; i++) cin >> rw[i];
	for(int i = 1;i <= n; i++) cin >> cl[i];
	
	auto in=[&](int i, int j){
		return (i <= n && j <= n && i >= 1 && j >= 1);
	};
	set<int> left, right, up, down;
	for(int i = 1;i <= n; i++){
		if(rw[i] == 'L') left.insert(i);
		else right.insert(i);
		if(cl[i] == 'U') up.insert(i);
		else down.insert(i);
	}
	int lefts = 0;
	for(int i = 1;i <= n; i++) lefts+= (rw[i] == 'L');
	if(n <= 80){
		int bfs[n+1][n+1][n+1][n+1];
		memset(bfs, -1, sizeof(bfs));
		for(int i = 1;i <= n; i++){
			for(int j = 1;j <= n; j++){
				bfs[i][j][i][j] = 0;
				queue<pair<int, int>> q;
				q.push({i, j});
				while(!q.empty()){
					int v = q.front().ff, u = q.front().ss;
					q.pop();
					int ni = v, nj = u;
					move(ni, nj, rw[v]);
					if(in(ni, nj) && bfs[i][j][ni][nj] == -1){
						q.push({ni, nj});
						bfs[i][j][ni][nj] = bfs[i][j][v][u]+1;
					}
					ni = v, nj = u;
					move(ni, nj, cl[u]);
					if(in(ni, nj) && bfs[i][j][ni][nj] == -1){
						q.push({ni, nj});
						bfs[i][j][ni][nj] = bfs[i][j][v][u]+1;
						
					}
				}
			}
		}
		
		
		while(q--){
			int type; cin >> type;
			int r, c, r1, c1; cin >> r >> c >> r1 >> c1;
			cout << (bfs[r][c][r1][c1] == -1  ? "NO" : "YES") << '\n';
			
		}
	}else{
		
		
		auto same_row=[&](int r, int c, int r1, int c1){
			if(c < c1){
				if(right.count(r)){
					return 1;
				}else{
					if(up.empty() == false && *up.begin() <= c){
						if(right.empty() == false && *right.begin() <= r){
							if(!down.empty() && *down.rbegin() >= c1){
								return 1;
							}
						}
					}
					
					if(down.empty() == false && *down.begin() <= c){
						if(right.empty() == false && *right.rbegin() >= r){
							if(!up.empty() && *up.rbegin() >= c1){
								return 1;
							}
						}
					} 
					
					
					return 0;
				}
			}else{
				if(left.count(r)){
					return 1;
				}else{
					if(up.empty() == false && *up.rbegin() >= c){
						if(left.empty() == false && *left.begin() <= r){
							if(!down.empty() && *down.begin() <= c1){
								return 1;
							}
						}
					}
					
					if(down.empty() == false && *down.rbegin() <= c){
						if(left.empty() == false && *left.rbegin() >= r){
							if(!up.empty() && *up.begin() <= c1){
								return 1;
							}
						}
					}
					return 0; 
				}
			}
		};
		
		
		auto same_col=[&](int r, int c, int r1, int c1){
			if(r < r1){
				if(down.count(c)){
					return 1;
				}else{
					if(left.empty() == false && *left.begin() <= r){
						if(down.empty() == false && *down.begin() <= c){
							if(!right.empty() && *right.rbegin() >= r1){
								return 1;
							}
						}
					}
					
					if(right.empty() == false && *right.begin() <= r){
						if(down.empty() == false && *down.rbegin() >= c){
							if(!left.empty() && *left.rbegin() >= r1){
								return 1;
							}
						}
					} 
					
					
					return 0;
				}
			}else{
				if(up.count(c)){
					return 1;
				}else{
					if(left.empty() == false && *left.rbegin() >= r){
						if(up.empty() == false && *up.begin() <= c){
							if(!right.empty() && *right.begin() <= r1){
								return 1;
							}
						}
					}
					
					if(right.empty() == false && *right.rbegin() <= r){
						if(up.empty() == false && *up.rbegin() >= c){
							if(!left.empty() && *left.begin() <= r1){
								return 1;
							}
						}
					}
					return 0; 
				}
			}
		};
		
		auto LR=[&](int r, int c, int r1, int c1){
			if(lefts == n){
					if(c < c1){
						return 0;
					}else{
						if(r == r1){
							return 1;
						}else if(r > r1){
							auto it = up.lower_bound(c1);
							if(it != up.end() && *it <= c){
							return 1;
							}else return 0;
						}else{
							auto it = down.lower_bound(c1);
							if(it != down.end() && *it <= c){
								return 1;
							}else return 0;
						}
					}
				}else{
					if(c > c1){
						return 0;
					}else{
						if(r == r1){
							return 1;
						}else if(r > r1){
							auto it = up.lower_bound(c);
							if(it != up.end() && *it <= c1){
							return 1;
							}else return 0;
						}else{
							auto it = down.lower_bound(c);
							if(it != down.end() && *it <= c1){
								return 1;
							}else return 0;
						}
					}
				}
		};	
		
		
		auto can_row=[&](int r, int c, int r1, int c1){
			
			
			
			
			if(r < r1){
				if(rw[r] == 'L' && down.empty() == false && *down.begin() <= c) return 1;
				if(rw[r] == 'R' && down.empty() == false && *down.rbegin() >= c) return 1;	
				return 0;
			}else{
				if(rw[r] == 'L' && up.empty() == false && *up.begin() <= c) return 1;
				if(rw[r] == 'R' && up.empty() == false && *up.rbegin() >= c) return 1;
				return 0;
			}
		};
		
		auto can_col=[&](int r, int c, int r1, int c1){
			if(c < c1){
				if(cl[c] == 'U' && right.empty() == false && *right.begin() <= r) return 1;
				if(cl[c] == 'D' && right.empty() == false && *right.rbegin() >= r) return 1;	
				return 0;
			}else{
				if(cl[c] == 'U' && left.empty() == false && *left.begin() <= r) return 1;
				if(cl[c] == 'D' && left.empty() == false && *left.rbegin() >= r) return 1;
				return 0;
			}
		};
		
		while(q--){
			int type; cin >> type;
			if(type == 1){
				int r, c, r1, c1; cin >> r >> c >> r1 >> c1;
				if(r == r1 && c == c1){
					cout << "YES\n";
					continue;
				}
				if(c == c1){
					int ok = same_col(r, c, r1, c1);
					cout << (ok ? "YES" : "NO") << '\n';
				}else if(r == r1){
					int ok = same_row(r, c, r1, c1);
					cout << (ok ? "YES" : "NO") << '\n';
				}else if(!lefts || lefts == n){
					int ok = LR(r, c, r1, c1);
					cout << (ok ? "YES" : "NO") << '\n';
				}else{
					int ok = 0;
					
					for(int where = 1; where <= n; where++){
						if(where > r && cl[c] == 'U') continue;
						if(where < r && cl[c] == 'D') continue;
						if(c < c1){
							if(rw[where] == 'R'){
								ok = max(ok, same_col(where, c1, r1, c1));
							}
						}else{
							if(rw[where] == 'L'){
								ok = max(ok, same_col(where, c1, r1, c1));
							}
						}
					}
					for(int where = 1; where <= n; where++){
						if(where > c && rw[r] == 'L') continue;
						if(where < c && rw[r] == 'R') continue;
						if(c < c1){
							if(rw[where] == 'R'){
								ok = max(ok, same_col(where, c1, r1, c1));
							}
						}else{
							if(rw[where] == 'L'){
								ok = max(ok, same_col(where, c1, r1, c1));
							}
						}
					}
					
					cout << (ok ? "YES" : "NO") << '\n';
				}
			}else if(type == 3){
				int col; cin >> col;
				if(cl[col] == 'U'){
					up.erase(col);
					down.insert(col);
					cl[col] = 'D';
				}else{
					up.insert(col);
					down.erase(col);
					cl[col] = 'U';
				}
				
			}else{
				int row; cin >> row;
				if(rw[row] == 'L'){
					left.erase(row);
					right.insert(row);
					rw[row] = 'R';
				}else{
					rw[row] = 'L';
					left.insert(row);
					right.erase(row);
				}
				
			}
		}
		
	}
}


signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while(t--){
		solve();
		cout << '\n';
	}
	
	return 0;
}