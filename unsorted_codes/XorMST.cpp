#include <bits/stdc++.h>
using namespace std;

#define ff first
#define ss second
#define all(a) a.begin(), a.end()
const int N = 2e5;
int n, a[N], par[N];
vector<int> List[N];
int find_set(int v){
	if(v == par[v]) return v;
	return par[v] = find_set(par[v]);
}
void merge(int a, int b){
	a = find_set(a);
	b = find_set(b);
	if(a == b) return;
	if(List[b].size() > List[a].size()) swap(a, b);
	par[b] = a;
	while(List[b].size()){
		List[a].push_back(List[b].back());
		List[b].pop_back();
	}
}
struct node{
	int next[2] = {0, 0};
	int flag = 0;
};
node trie[N*31];
int vert = 1;
int get(int &x, int &i){
	return (x & (1<<i) ? 1 : 0);
}
map<int, vector<int> > mp;
void add(int x){
	int cur = 0;
	for(int i = 29; i >= 0; i--){
		if(!trie[cur].next[get(x, i)]) trie[cur].next[get(x, i)] = vert++;
		cur = trie[cur].next[get(x, i)];
		trie[cur].flag++;	
	}
}
void del(int x){
	int cur = 0;
	for(int i = 29; i >= 0; i--){
		cur = trie[cur].next[get(x, i)];
		trie[cur].flag--;
	}
}
int get_min_xor(int x){
	int sum = 0, cur = 0;
	for(int i = 29;i >= 0; i--){
		int bit = get(x, i);
		int NXT = trie[cur].next[bit];
		if(NXT and trie[NXT].flag){
			cur = NXT;
			sum|= bit<<i;
		}else{
			sum|= (bit^1)<<i;
			cur = trie[cur].next[bit^1];
		}
	}
	return sum;
}


main(){
   ios::sync_with_stdio(0);
   cin.tie(0); cout.tie(0);
	cin >> n;
	for(int i = 0;i < n; i++){
		cin >> a[i];
		mp[a[i]].push_back(i);
		add(a[i]);
		List[i].push_back(i);
		par[i] = i;
	}
	vector< vector<int> > teams;
	for(int i = 0;i < n; i++){
		teams.push_back({i});
	}
	set<int> used;
	long long MST = 0;
	while(List[find_set(0)].size() < n){
		for(int i = 0;i < teams.size(); i++){
			if(used.count(find_set(teams[i][0]))) continue;
			for(int j : teams[i]){
				del(a[j]);
			}
			int mn = INT_MAX, mn_edge = -1;
			for(int j : teams[i]){
				int MN = get_min_xor(a[j]);
				if(mn > (MN^a[j])){
					mn_edge = MN;
					mn = (MN^a[j]);
				}
			}
			int v = find_set(teams[i][0]);
			int u = -1;
			for(int k : mp[mn_edge]){
				if(find_set(k) != v){
					u = k;
					break;
				}
			}
			if(u != -1){
				MST+= mn;
				merge(u, v);
			}
			for(int j : teams[i]){
				add(a[j]);
			}
			used.insert(find_set(teams[i][0]));
		}
		teams.clear();
		used.clear();
		for(int i = 0;i < n; i++){
			if(used.count(find_set(i))) continue;
			teams.push_back(List[find_set(i)]);
			used.insert(find_set(i));
		}
		used.clear();
		
	}
	
	cout << MST;
	return 0;
}

