#include <bits/stdc++.h>
using namespace std;
#define ff  first
#define ss second
int n, m; 
vector< vector<int> > a(2500, vector<int>(2500, -1));
vector< vector<int> > pref(2500, vector<int>(2500, 0));
vector< vector<int> > Can(2500, vector<int>(2500, 0));

int subs[300][300][300];
int no_block, S, mx;
struct node{
	int l, r, sum;
};
vector<node> row[2500];
int get_sum(int i, int l, int r){
	if(l == 0){
		return pref[i][r];
	}else{
		return pref[i][r]-pref[i][l-1];
	}
}
int good(int i, int l, int r){
	if(l == 0) return (Can[i][r] == 0);
	return ((Can[i][r]-Can[i][l-1])==0);
}

void brute_lr(int i){
//	for(auto e : row[i]){
//		int l = e.l, r = e.r;
//		mx = max(mx, e.sum);
//		while(r >= l){
//			subs[i][l][r] = e.sum;
//			if(r == l){
//				break;
//			}
//			if(r-1 >= l) subs[i][l][r-1] = e.sum-a[i][r];
//			if(l+1<= r) subs[i][l+1][r] = e.sum-a[i][l];
//			e.sum-= a[i][r]; e.sum-= a[i][l];
//			r--, l++;
//		}
//	}
	for(int l = 0; l < m; l++){
		int sum = 0, can = 0;
		for(int r = l; r < m; r++){
			sum+= a[i][r];
			can+= (a[i][r] == -1);
			if(can > 0) break;
			subs[i][l][r] = max(subs[i][l][r], sum);
			mx = max(mx, sum);
		}
	}
}

void calc_max(int i){
	for(int l = 0; l < m; l++){
		for(int r = l+1; r < m; r++){
			subs[i][l][r] = max(subs[i][l][r], subs[i][l][r-1]);
		}
	}
	for(int l = m-2;l >=0; l--){
		for(int r = l; r < m; r++){
			subs[i][l][r] = max(subs[i][l][r], subs[i][l+1][r]);
		}
	}
}

void calc_best(){
	for(int i = 0;i < n; i++){
		int j = 0, L = 0, s = 0, cnt=0;
		while(j < m){
			if(a[i][j] != -1){
				L = j;
				break;
			}
			j++;
		}
		while(j < m){
			if(a[i][j] == -1){
				if(cnt > 0){
					row[i].push_back({L, j-1, s});
				}
				cnt = 0, s = 0;
				while(j < m){
					if(a[i][j] != -1){
						L = j;
						break;
					}
					j++;
				}
			}else{
				s+= a[i][j];
				j++, cnt++;
			}
		}
		if(cnt > 0){
			row[i].push_back({L, m-1, s});
		}
	}
}

/*
3 5
64X24
X7608
674XX
*/

main(){
	cin >> n >> m;
	for(int i = 0;i < n; i++){
		for(int j = 0;j < m; j++){
			char c; cin >> c;
			if(c >= '0' and c <= '9'){
				a[i][j] = c-'0';
				S+= a[i][j];
				no_block++;
			}
			if(j == 0){
				pref[i][j] = a[i][j];
				Can[i][j] = (a[i][j] == -1);
			}else{
				pref[i][j] = pref[i][j-1]+a[i][j];
				Can[i][j] = Can[i][j-1]+(a[i][j] == -1);
			}
		}
	}
	if(no_block == n*m){
		cout << S;
		return 0;
	}
	calc_best();
	if(n == 1){
		brute_lr(0);
		cout << mx;
		return 0;
	}
	brute_lr(0);
	calc_max(0);
	for(int i = 1;i < n; i++){
		for(int l = 0;l < m; l++){
			for(int r = l; r < m; r++){
				if(good(i, l, r)){
					subs[i][l][r] = get_sum(i, l, r);
					subs[i][l][r] += subs[i-1][l][r];
					mx = max(mx, subs[i][l][r]);	
				}
			}
		}
		calc_max(i);
	}
	cout << mx;
	return 0;
}