#include <bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
#define all(a) a.begin(), a.end()

int dp[20][300][200][20][20];
int dp1[20][300][200][20][20];

/*
vector<int> factor(int x){
	vector<int> p;
	for(int i = 2; i * i <= x; i++){
		while(x > 1 && x % i == 0){
			p.push_back(i);
			x/= i;
		}
	}
	if(x > 1) p.push_back(x);
	vector<int> cnt;
	int c2 = 0, c5 = 0, c7 = 0, c3 = 0;
	for(int i = 0;i < p.size(); i++){
	    if(p[i] == 2){
	        c2++;
	    }else if(p[i] == 3) c3++;
	    else if(p[i] == 5) c5++;
	    else c7++;
	}
    cnt.push_back(c2);
    cnt.push_back(c3);
    cnt.push_back(c5);
    cnt.push_back(c7);
	return cnt;
}
	
*/
void solve(int n, string s){
	s = "#" + s;
	dp[0][0][0][0][0] = 1;
	
	for(int i = 1;i <= n; i++){
		for(int c = 0; c <= 216; c++){
			for(int c1 = 0; c1 <= 162; c1++){
				for(int c2 = 0; c2 <= n; c2++){
					for(int c3 = 0; c3 <= n; c3++){
						
						vector<int> d;
						if(s[i] == '?'){
							for(int j = 1;j < 10; j++) d.push_back(j);
						}else d.push_back(s[i] - '0');
						for(auto dig : d){
							//vector<int> cnt = factor(dig);
							vector<int> cnt = {0, 0, 0, 0};
							dp[i][c+cnt[0]][c1+cnt[1]][c2+cnt[2]][c3+cnt[3]]+= dp[i-1][c][c1][c2][c3];
						}
						
					}
				}
			}
		}
	}
	
	
}

main(){
	ios::sync_with_stdio(0); 
	cin.tie(0); cout.tie(0);
	
	
	
	
	
	
	int n; cin >> n;
	string a = "", b = "";
	for(int i = 0;i < n; i++){
		char ch; cin >> ch;
		a.push_back(ch);
	}	
	for(int i = 0;i < n; i++){
	    char ch; cin >> ch;
	    b.push_back(ch);
	}
//	solve(n, a);
	
	for(int i = 0;i < 10; i++){
		for(int j = 0;j < 300; j++){
			for(int c = 0; c < 200; c++){
				for(int c1 = 0; c1 < 20; c1++){
					for(int c2 = 0; c2 < 20; c2++){
						dp1[i][j][c][c1][c2] = dp[i][j][c][c1][c2];
					} 
				}
			}
		}
	}
//	solve(n, b);
	long long ans = 0;
	for(int i = 0;i < 300; i++){
		for(int j = 0;j < 200; j++){
			for(int c  =0; c < 20; c++){
				for(int c1 = 0; c1 < 20; c1++){
					ans+= (dp[n][i][j][c][c1] * dp1[n][i][j][c][c1]);
				}
			}
		}
	}
	cout << ans;
	
	return 0;
}
