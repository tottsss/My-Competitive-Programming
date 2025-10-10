#include <bits/stdc++.h>
     
using namespace std;
#define ff first
#define ss second
const int N = 1e5;
int n, b, k,m, id;
int a[N+5], dp[N+5], p[N+5];
pair<int, int> tree[4*N+5];
vector<int> idx[N];
pair<int, int> combine(pair<int, int> a, pair<int, int> b){
    if(a.ff > b.ff) return a;
    return b;
}
 
void update(int pos, int x, int v, int vl, int vr){
    if(vl == vr){
      if(tree[v].ff < x)
         tree[v] = {x, vl};
        return;
    }
    int mid = (vl + vr)>>1;
    if(mid>= pos) update(pos, x, v<<1|1, vl, mid);
    else update(pos, x, (v<<1) +2, mid+1, vr);
    tree[v] = combine(tree[v<<1|1], tree[(v<<1) +2]);
}  
pair<int,int> getmax(int l, int r, int v, int vl, int vr){
    if(l > vr or vl > r or l > r) return {0, -1};
    if(l <= vl and r >= vr) return tree[v];
    int mid = (vl + vr) / 2;
    pair<int, int> L = getmax(l, r, 2*v+1, vl, mid);
    pair<int, int> R = getmax(l, r, 2*v+2, mid+1, vr);
    return combine(L, R);
}
int index(int x, int i){
    int L = lower_bound(idx[x].begin(), idx[x].end(), i) - idx[x].begin();
    return idx[x][L-1];
}
 
main(){
    cin >> n >> a[0] >> k >> b >> m;
    idx[a[0]].push_back(0);
    for(int i = 0;i < 4*N; i++){
        tree[i] = {0, -1};
    }
    for(int i = 1;i < n; i++){
        a[i] = (k * a[i-1] + b) % m;
        idx[a[i]].push_back(i); 
    } 
    update(a[0], 1, 0, 0, N);
    p[0] = -1;
    for(int i = 1;i < n; i++){
        pair<int, int> last = getmax(0, a[i]-1, 0, 0, N);
        dp[i] = last.ff + 1;
        update(a[i], dp[i], 0, 0, N);
        if(dp[i] > dp[id]) id = i;
        if(last.ss == -1) p[i] = -1;
        else p[i] = index(last.ss, i);
    }
    vector<int> ans;
    for(int par = id; par != -1; par = p[par]) ans.push_back(a[par]);
    reverse(ans.begin(), ans.end());
    for(int x : ans) cout << x << ' ';
    return 0;
}