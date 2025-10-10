struct bipartite_matching{ // unnecessary, but I'm too lazy
	vector<int> gph[MAXN];
	bitset<MAXN> vis;
	int l[MAXN], r[MAXN];
	int dis[MAXN];
	void init(){
		memset(l, -1, sizeof(l));
		memset(r, -1, sizeof(r));
	}
	void add_edge(int s, int e){
		gph[s].push_back(e);
	}
	bool bfs(int k){
		queue<int> que;
		memset(dis, 0, sizeof(dis));
		for(int i=0; i<k; i++){
			if(l[i] == -1){
				dis[i] = 1;
				que.push(i);
			}
		}
		int ok = 0;
		while(!que.empty()){
			auto x = que.front();
			que.pop();
			for(auto &i : gph[x]){
				if(r[i] == -1) ok = 1;
				else if(!dis[r[i]]){
					dis[r[i]] = dis[x] + 1;
					que.push(r[i]);
				}
			}
		}
		return ok;
	}
	bool dfs(int x){
		if(vis[x]) return 0;
		vis[x] = 1;
		for(auto &i : gph[x]){
			if(r[i] == -1 || dfs(r[i])){
				r[i] = x;
				l[x] = i;
				return 1;
			}
		}
		return 0;
	}
	void match(int k){
		while(bfs(k)){
			vis = 0;
			for(int i=0; i<k; i++){
				if(l[i] == -1){
					dfs(i);
				}
			}
		}
	}
}bpm;