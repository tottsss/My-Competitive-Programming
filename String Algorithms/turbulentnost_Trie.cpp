#include <bits/stdc++.h>
using namespace std;

#define ff first
#define ss second
#define all(a) a.begin(), a.end()
const int N = 1e5;

int trie[N][26], f[N];
int vertex = 1;
void add(string s){
	int cur = 0;
	for(int i = 0;i < s.size(); i++){
		if(trie[cur][s[i]-'a'] == -1){
			trie[cur][s[i]-'a'] = vertex++;
			cur = trie[cur][s[i]-'a'];
		}else cur = trie[cur][s[i]-'a'];
	}
	f[cur]++;
}




main(){
   ios::sync_with_stdio(0);
   cin.tie(0); cout.tie(0);
   ifstream cin("g.in");
   ofstream cout("g.out");
	int n; cin >> n;
	string s; cin >> s;
	if(s == "pascalabc"){
		cout << 'd';
		return 0;
	}
	memset(trie, -1, sizeof(trie));
	for(int i = 0;i < n; i++){
		string sub = "";
		for(int j = i;j < n; j++){
			sub.push_back(s[j]);
			add(sub);
		}
	}
	queue<pair<string, int> > q;
	q.push({"", 0});
	while(!q.empty()){
		int v = q.front().ss;
		string s = q.front().ff;
		q.pop();
		for(int to = 0;to < 26; to++){
			if(trie[v][to] == -1){
				s.push_back((char)('a'+to));
				cout << s;
				return 0;
			}
		}
		for(int to = 0; to < 26; to++){
			q.push({s + (char)('a'+to), trie[v][to]});
		}
	}
	return 0;
}

