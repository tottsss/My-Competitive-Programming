#include "kdag.h"
#include <bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
const int N = 12345;


vector<int> partition(int n, int m, int k, vector<int> u, vector<int> v) {
	vector<int> g[n + 1], subset(m + 1);
	map<pair<int, int>, int> mp; 
	vector< pair<int, int> > edge;

	vector<int> answer;
	int one = 0, two = 0;
	vector<set<int>> parents(n + 1);
	for(int i = 0;i < m; i++){
		subset[i] = 0;
		edge.push_back({u[i], v[i]});
		g[u[i]].push_back(v[i]);
	}
	subset[0] = 1; mp[edge[0]] = 1; one++;
	parents[edge[0].ss].insert(edge[0].ff);
	int round = 1000;
	while(round--){
		if(one + two >= m) break;
		for(int i = 1;i < m; i++){
			if(subset[i] != 0) continue;
			int ok = 0;
			if(one > two){
				int v = edge[i].ff, to = edge[i].ss; ok = 0;
				if(parents[to].count(v)) ok = 1;
				for(int j = 0;j < m; j++){
					pair<int, int> E = edge[j];
					if(subset[j] == 2 and E.ff == to){
						if(parents[v].count(E.ss)){
							ok=1;
							break;
						}
					}
				}
				if(ok == 0){
					subset[i] = 2;
					mp[edge[i]] = 2;
					parents[to].insert(v);
					two++;
				}
			}
			if(subset[i] != 0) continue;
			int v = edge[i].ff, to = edge[i].ss; ok = 0;
			if(parents[to].count(v)) ok = 1;
			for(int j = 0;j < m; j++){
				pair<int,int> E = edge[j];
				if(subset[j] == 1 and E.ff == to){
					if(parents[v].count(E.ss)){
						ok=1;
						break;
					}
				}
			}
			if(ok == 0){
				subset[i] = 1;
				mp[edge[i]] = 1;
				parents[to].insert(v);
				one++;
			}
			if(subset[i] == 0){
				int v = edge[i].ff, to = edge[i].ss; ok = 0;
				if(parents[to].count(v)) ok = 1;
				for(int j = 0;j < m; j++){
					pair<int, int> E = edge[j];
					if(subset[j] == 2 and E.ff == to){
						if(parents[v].count(E.ss)){
							ok=1;
							break;
						}
					}
				}
				if(ok == 0){
					subset[i] = 2;
					mp[edge[i]] = 2;
					parents[to].insert(v);
					two++;
				}
			}
			if(subset[i] == 0){
				two = m + 1;
				break;
			}
		}
		if(one + two >= m) break;
	}
	for(int i = 0;i < m; i++){
		if(subset[i] == 0){
			answer.clear();
			break;
		}
		answer.push_back(subset[i]);
	}

  	return answer;
}
