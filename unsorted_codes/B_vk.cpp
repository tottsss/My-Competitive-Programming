#include <bits/stdc++.h>
using namespace std;
 
const int n = 10;
char a[n][n];
#define ff first
#define ss second
int in(int i, int j){
    return (i >= 0 && j >= 0 && i < n && j < n);
}
 
 
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
 
int da[4] = {-1, 1, 1, -1};
int db[4] = {1, -1, 1, -1};
 
main(){
    for(int i = 0;i < n; i++){
        for(int j = 0;j < n; j++){
            cin >> a[i][j];
        }
    }
    int s = 0;
    for(int i = 0;i < n; i++){
        for(int j = 0;j < n; j++) s+= (a[i][j] == '#');
    }
    if(s != 4 + 6 + 6 + 4){
        cout << "NO";
        return 0;
    }
//  cout << 't';
    vector< vector<int> > used(11, vector<int>(11, 0));
    vector<int> sz(100, 0);
    for(int i = 0;i < n; i++){
        for(int j = 0;j < n; j++){
            if(a[i][j] != '#') continue;
            if(used[i][j]) continue;
            int sos = 0;
            pair<int, int> go;
            queue<pair<int, int> > q;
            for(int k = 0;k < 4; k++){
                int ni = i + dx[k];
                int nj = j + dy[k];
                if(!in(ni, nj)) continue;
                if(a[ni][nj] == '#'){
                    sos++;
                    go = {dx[k], dy[k]};
                }
            }
            if(sos > 1){
                continue;
            }
            sos = 0;
            for(int k = 0;k < 4; k++){
                int ni = i + da[k];
                int nj = j + db[k];
                if(!in(ni, nj)) continue;
                if(a[ni][nj] == '#'){
                    sos++;
                }
            }
            if(sos > 0){
            //  cout << 's';
                cout << "NO";
                return 0;
            }
            int ni = i, nj = j;
            sos = 0;
            while(in(ni, nj)){
                 
                if(a[ni][nj] != '#') break;
            //  cout << ni+1 << ' ' << nj+1 << '\n';
                if(used[ni][nj]){
                    cout << 's';
                    cout << "NO";
                    return 0;
                }
                used[ni][nj] = 1;
                sos++;
                if(go.ff == 0 && go.ss == 0) break;
                ni+= go.ff;
                nj+= go.ss;
            }
        //  cout << "\n" << "___" << '\n';
            sz[sos]++;
        }
    }
//  cout << "to";
    if(sz[4] != 1){
        cout << "NO";
        return 0;
    }
    if(sz[3] != 2){
        cout << "NO";
        return 0;
    }
    if(sz[2] != 3){
        cout << "NO";
        return 0;
    }
    if(sz[1] != 4){
        cout << "NO";
        return 0;
    }
    cout << "YES";
     
    return 0;
}