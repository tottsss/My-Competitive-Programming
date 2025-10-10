#include <bits/stdc++.h>
using namespace std;

#define ff first
#define ss second
#define all(a) a.begin(), a.end()

int g[20][20], vis[20], n, color[20];
struct Node{
	int id;
	int RemCol;
	int UnVertex;
	int used[4]; 
};
vector<Node> cur;
void dfs(int i){
	cur.push_back(Node{i});
	vis[i] = 1;
	for(int j = 0;j < n; j++){
		if(g[i][j] and !vis[j]) dfs(j);
	}
}

int succes, can;
void paint(int index){
	if(index == cur.size()){
		succes = 1;
		return;
	}
	for(int idx = index; idx < cur.size(); idx++){
		cur[idx].RemCol = can;
		cur[idx].UnVertex = 0;
		for(int j = index+1; j < cur.size(); j++){
			if(g[cur[idx].id][cur[j].id]) cur[idx].UnVertex++;
		}
		for(int j = 0;j < can; j++) cur[idx].used[j] = 0;
		for(int j = 0;j < index; j++){
			if(g[cur[idx].id][cur[j].id]){
				if(cur[idx].used[color[cur[j].id]] == 0){
					cur[idx].RemCol--;
					cur[idx].used[color[cur[j].id]] = 1;
				}
			}
		}
	}
//	nth_element(cur.begin() + index, cur.begin() + index, cur.end(), [](Node A, Node B){
//		if(A.RemCol != B.RemCol) return A.RemCol < B.RemCol;
//		return A.UnVertex > B.UnVertex;
//	});
	sort(cur.begin() + index, cur.end(), [](Node A, Node B){
		if(A.RemCol != B.RemCol) return A.RemCol < B.RemCol;
		return A.UnVertex > B.UnVertex;
	});
	if(index == 0){
		color[cur[index].id] = 0;
		paint(index+1);
	}else if(index == 1){
		color[cur[index].id] = 1;
		paint(index+1);
	}else{
		for(int col = 0; col < can; col++){
			if(cur[index].used[col] == 0){
				color[cur[index].id] = col;
				paint(index+1);
				if(succes) return;
			}
		}
	}
}

main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	 cin >> n;
	 int all = 0;
	 for(int i = 0;i < n; i++){
	 	color[i] = -1;
		 for(int j = 0;j < n; j++){
	 		cin >> g[i][j];
	 		all+= g[i][j];
		 }
	 }
	 if(all == n*(n-1)) assert(false);
	for(int i = 0;i < n; i++){
		if(vis[i]) continue;
		cur.clear();
		succes = 0;
		dfs(i);
		for(can = 1; can <= 4; can++){
			paint(0);
			if(succes) break;
		}
	}
	for(int i = 0;i < n; i++) cout << color[i]+1 << ' ';
	return 0;
}

