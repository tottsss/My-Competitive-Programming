#include <bits/stdc++.h>

using namespace std;
#define ff first
#define ss second

const int N = 2e5+1;
int p[N], sz[N], n, q, comp;
stack< array<int, 5> > st;


int find_set(int v){
	while(v!= p[v]) v = p[v];
	return v;
}

void union_set(int a, int b, int persist){
	a = find_set(a);
	b = find_set(b);
	if(sz[b] > sz[a]) swap(a,b);
	if(a == b){
		if(persist > 0)
		st.push({b, p[b], a, sz[a], 0});
		return;
	}
	
	if(persist > 0){
		st.push({b, p[b], a, sz[a], 1});
	}
	p[b] = a;
	sz[a]+= sz[b];
	comp--;
}



main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n >> q;
	int flag = 0;
	comp = n;
	for(int i = 1;i <= n; i++){
		p[i] = i, sz[i] = 1;
	}
	while(q--){
		string s; cin >> s;
		if(s[0] == 'p'){
			flag++;
			st.push({-1, -1, -1, -1, -1});
		}else if(s[0] == 'u'){
			int x, y; cin >> x >> y;
			union_set(x, y, flag);
			cout << comp << "\n";
		}else{
			while(!st.empty()){
				int b = st.top()[0], Pb = st.top()[1], a = st.top()[2], szA = st.top()[3];
				if(b == -1){
					st.pop();
					flag--;
					break;
				}
				p[b]=Pb;
				sz[a] = szA;
				if(st.top()[4] == 1) comp++;
				st.pop();
			}
			cout <<comp << "\n";
		}
	}
	

	return 0;
}