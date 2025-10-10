#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

typedef tree<int, null_type, less<int>, rb_tree_tag,
	tree_order_statistics_node_update> ordered_set;
	
const unsigned gen_seed = std::chrono::system_clock::now().time_since_epoch().count();
		std::mt19937_64 gen(gen_seed);	

int read_int (){
	bool minus = false;
	int result = 0;
	char ch;
	ch = getchar();
	while (true) {
		if (ch == '-') break;
		if (ch >= '0' && ch <= '9') break;
		ch = getchar();
	}
	if (ch == '-') minus = true; else result = ch-'0';
	while (true) {
		ch = getchar();
		if (ch < '0' || ch > '9') break;
		result = result*10 + (ch - '0');
	}
	if (minus)
		return -result;
	else
		return result;
}
const int N = 1e5 + 1;
const int INF = 1e9 + 7;
const double PI = acos(-1.0);
const double EPS = (1e-9);
#define ff first
#define ss second
#define all(a) a.begin(), a.end();
#define int long long
int di[] = {-1, 1, 0, 0};
int dj[] = {0, 0, -1, 1};
int dx_horse[] = {2,2,-2,-2, 1, 1, -1, -1};
int dy_horse[] = {1,-1, -1,1, 2, -2, -2, 2};
void fast(){
	ios::sync_with_stdio(0); 
	cin.tie(0);  cout.tie(0);
}
int in(int i, int j){
	if(min(i, j) < 0 or max(i, j) >= n) return 0;
	return 1;
}
void file(){
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
}

main(){
	
	
	return 0;
}