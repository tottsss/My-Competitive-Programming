#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ff first
#define ss second
#define all(a) a.begin(), a.end()

int g[4][4];
main(){
   ios::sync_with_stdio(0);
   cin.tie(0); cout.tie(0);
	int n; cin >> n;
	vector<int> a(n);
	for(auto &i : a){
		cin >> i; i--;
	}
//	for(int i = 0;i < n; i++) cout << a[i] << ' ';
	vector<int> b;
	for(int j=1;j<=4;j++)for(int i=0;i<n;i++)if(a[i]==j-1)b.push_back(j-1);
	for(int i=0;i<n;i++){
		if(a[i] != b[i])g[a[i]][b[i]]++;
	}
	int ans = 0;
    for ( int i = 0; i < 4; i++ ){
        for ( int j = 0; j < 4; j++ ){
            int Mn = min(g[i][j], g[j][i]);
            ans += Mn;
            g[i][j] -= Mn, g[j][i] -= Mn;
        }
    }
    for ( int i = 0; i < 4; i++ ){
        for ( int j = 0; j < 4; j++ ){
            for ( int k = 0; k < 4; k++ ){
                int Mn = min({g[i][j], g[j][k], g[k][i]});
                ans += Mn * 2; g[i][j] -= Mn;
                g[j][k] -= Mn, g[k][i] -= Mn;
            }
        }
    }
    for ( int i = 0; i < 4; i++ ){
        for ( int j = 0; j < 4; j++ ){
            for ( int k = 0; k < 4; k++ ){
                for ( int s = 0; s < 4; s++ ){
                    int Mn = min({g[i][j], g[j][k], g[k][s], g[s][i]});
                    ans += Mn * 3;
                    g[i][j] -= Mn, g[j][k] -= Mn;
                    g[k][s] -= Mn, g[s][i] -= Mn;
                }
            }
        }
    }
    cout << ans;
	return 0;
}

