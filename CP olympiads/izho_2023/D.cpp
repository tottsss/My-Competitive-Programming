#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ff first
#define ss second
#define all(a) a.begin(), a.end()
const int N = 1e5;
int n;
int a[N],c[N],b[N],cost[N];
int mx_cost, minC=INT_MAX, maxA;
void subtask1(){
	int mx = 0;
	vector<int> A = {0, 1, 2}, C = {0, 1, 2};
	do{	
		do{
			int sum = 0;
			for(int j = 0;j < 3; j++){
				if(a[A[j]] <= b[j] and b[j] <= c[C[j]]){
					sum+= cost[j];
				}
			}	
			mx = max(mx, sum);
		}while(next_permutation(all(C)));
	}while(next_permutation(all(A)));
	cout << mx;
	
}
void subtask4(){
	sort(a, a + n);
	sort(b, b + n);
	sort(c, c + n);
	int i = 0, j = 0, k = 0, sum = 0;
	while(i < n){
		if(max({i, j, k}) >= n){
			break;
		}
		int f = 0;
		while(j < n){
			if(b[j] >= a[i]){
				f = 1;
				int f1 = 0;
				while(k < n){
					if(c[k] >= b[j]){
						sum++, k++, j++;
						f1 = 1;
						break;
					}else{
						k++;
					}
				}
				if(f1 == 0){
					cout << sum;
					return;
				}else break;
			}else{
				j++;
			}
		}
		if(f == 0){
			cout << sum;
			return;
		}
		i++;
	}
	cout << sum;
}
void subtask2(){
	sort(a, a + n);
	sort(c, c + n);
	vector<pair<int, int> > B;
	for(int i =0 ;i < n; i++){
		B.push_back({b[i], cost[i]});
	}
	sort(B.rbegin(), B.rend());
	int i = 0, j = 0, k = 0, sum = 0;
	while(i < n){
		if(max({i, j, k}) >= n){
			break;
		}
		int f = 0;
		while(j < n){
			if(B[j].ff >= a[i]){
				f = 1;
				int f1 = 0;
				while(k < n){
					if(c[k] >= B[j].ff){
						sum+= B[j].ss, k++, j++;
						f1 = 1;
						break;
					}else{
						k++;
					}
				}
				if(f1 == 0){
					cout << sum;
					return;
				}else break;
			}else{
				j++;
			}
		}
		if(f == 0){
			cout << sum;
			return;
		}
		i++;
	}
	cout << sum;
}

void subtask3(){
	vector<int> A;
	for(int i = 0;i < n; i++) A.push_back(a[i]);
	vector<pair<int, int> > B;
	for(int i =0 ;i < n; i++){
		B.push_back({b[i], cost[i]});
	}
	sort(B.rbegin(), B.rend());
	sort(A.rbegin(), A.rend());
	multiset<int> money;
	int i = 0, j = 0, sum = 0;
	while(i < n){
		while(j < n){
			if(B[j].ff >= A[i]){
				money.insert(B[j].ss);
				j++;
			}else break;
		}
		i++;
		if(money.empty()){
			continue;
		}
		sum+= *money.rbegin();
		auto it = money.find(*money.rbegin());
		money.erase(it);
	}
	cout << sum;
}


void subtask5(){
	vector<int> A,C;
	for(int i = 0;i < n; i++){
		C.push_back(c[i]);
		A.push_back(a[i]);
	}
	vector<pair<int, int> > B;
	for(int i =0 ;i < n; i++){
		B.push_back({b[i], cost[i]});
	}
	sort(B.rbegin(), B.rend());
	sort(A.rbegin(), A.rend());
	vector<int> used(n, 0);
	sort(C.rbegin(), C.rend());
	multiset<pair<int, int> > money;
	int i = 0, j = 0, sum = 0;
	while(i < n){
		while(j < n){
			if(B[j].ff >= A[i]){
				money.insert({B[j].ss, j});
				j++;
			}else break;
		}
		i++;
		if(money.empty()){
			continue;
		}
		auto it = money.begin();
		auto ans = money.end();
		int mx = 0, idx = -1;
		for(; it != money.end(); it++){
			for(int k = 0;k < n; k++){
				if(used[k] == 0 and C[k] >= B[it->ss].ff){
					if(mx <= B[it->ss].ss){
						mx = B[it->ss].ss;
						idx = k;
						ans = it;
					}
				}
			}
		}
		if(ans!=money.end()){
			sum+= ans->ff;
			money.erase(ans);
			used[idx] = 1;
		}
	}
	cout << sum;
}

main(){
   ios::sync_with_stdio(0);
   cin.tie(0); cout.tie(0);
	cin >> n;
	for(int i = 0;i < n; i++){
		cin >> a[i];
		maxA = max(maxA, a[i]);
	}
	for(int i = 0;i < n; i++){
		cin >> c[i];
		minC = min(minC, c[i]);
	}
	set<int> SET;
	for(int i = 0;i < n; i++){
		cin >> b[i];
		SET.insert(b[i]);
	}
	for(int i = 0;i < n; i++){
		cin >> cost[i];
		mx_cost = max(mx_cost, cost[i]);
	}
	if(n == 3){
		subtask1();
		return 0;
	}
	if(mx_cost == 1){
		subtask4();
		return 0;
	}
	if(SET.size() ==1){
		subtask2();
		return 0;
	}
	if(minC >= maxA and minC >= *SET.rbegin()){
		subtask3();
		return 0;
	}
	if(n <= 2000){
		subtask5();
		return 0;
	}
	return 0;
}