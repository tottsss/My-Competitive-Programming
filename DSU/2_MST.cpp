#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ff first
#define ss second
#define all(a) a.begin(), a.end()
const int INF = 1e9 + 7;
const int N = 1000;
int p[N], a[N], b[N], c[N];
int n, m;
int get(int v){
    if(v == p[v]) return v;
    return p[v] = get(p[v]);
}
void unite(int a, int b){
    a = get(a); b = get(b);
    if(a != b) p[b] = a;
}
 
 main(){
    cin >> n >> m;
    vector< pair<int, pair<int, int> > > g;
    for(int i = 0;i < m; i++){
    	cin >> a[i] >> b[i] >> c[i];
        g.push_back({c[i], {a[i], b[i]}});
    }
    for(int i = 1;i <= n; i++) p[i] = i;
    sort(g.begin(), g.end());
    int cost = 0, A, B, W;
    vector<int> used(m, 0);
    for(int i = 0;i < m; i++){
        W = g[i].ff; B = g[i].ss.ss;
        A = g[i].ss.ff;
        if(get(A) != get(B)){
            cost+= W;
            used[i] = 1;
            unite(A, B);
        }
    } 
    // https://acmp.ru/asp/do/index.asp?main=task&id_course=2&id_section=32&id_topic=55&id_problem=1044
    int S = cost;
    cout << cost << ' ';
    cost = INT_MAX;
    for(int i = 0;i < m; i++){
    	W = g[i].ff; B = g[i].ss.ss;
        A = g[i].ss.ff;
    	if(used[i]){
    		int sum = 0;
			for(int k = 1;k <= n; k++){
        		p[k] = k;
    		}
    		for(int j = 0;j < m; j++){
    			W = g[j].ff; B = g[j].ss.ss;
		        A = g[j].ss.ff;
    			if(j != i){
    				if(get(A) != get(B)){
		            	sum+= W;
		            	unite(A, B);
		        	}	
				}
			}
			int ok = 0;
			for(int i = 1;i <= n; i++) if(get(1) == get(i)) ok++;
			if(ok==n) cost = min(cost, sum);
		}
	}
	cout << cost;
    return 0;
}