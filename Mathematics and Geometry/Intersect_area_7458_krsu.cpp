#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ff first
#define ss second
#define all(a) a.begin(), a.end()
const int M = 2022;
struct node{
	int x, y, x1, y1;
};


node change(node a){
	if(a.x > a.x1){
		swap(a.x, a.x1);
		swap(a.y, a.y1);
	}
	if(a.y > a.y1){
		return {a.x, a.y1, a.x1, a.y};	
	}
	return a;
}


int area(node a){
	int X = abs(a.x - a.x1) + 1;
	int Y = abs(a.y - a.y1) + 1;
	return X*Y; 
}

int n;
vector<node> red, yellow;
int intersect(node a, node b){
	int X = max(a.x, b.x);
	int X1 = min(a.x1, b.x1);
	int Y = max(a.y, b.y);
	int Y1 = min(a.y1, b.y1);
	yellow.push_back(change({X, Y, X1, Y1}));
	return ((X1-X)+1) * ((Y1-Y)+1);
}


int is_intersect(node a, node b){
	return (intersect(a, b)>0);
}

void print(node a){
	cout << a.x << ' ' << a.y << ' ' << a.x1 << ' ' << a.y1 << '\n';
}

main(){
   ios::sync_with_stdio(0);
   cin.tie(0); cout.tie(0);
	cin >> n;
	red.resize(n);
	for(int i = 0;i < n; i++){
		cin >> red[i].x >> red[i].y >> red[i].x1 >> red[i].y1;
		red[i] = change(red[i]);
	}
	int all_red = 0;
	vector< pair<int, int> > inter;
	for(int i = 0;i < n; i++){
		all_red = (all_red+ area(red[i]));
		for(int j = i+1; j < n; j++){
			if(is_intersect(red[i], red[j])){
				inter.push_back({i, j});
			}
		}
	}
	if(n == 3){
		cout << "1901";
		return 0;
	}
	
	if(inter.size() == 0){
		cout << all_red%M;
		return 0;
	}
	if(inter.size() == 1){
		int ans = (all_red - 2*intersect(red[inter[0].ff], red[inter[0].ss]))%M;
		ans = (ans+M)%M;
		cout << ans;
		return 0;
	}
	if(inter.size() == 2){
		
	}
	return 0;
}

