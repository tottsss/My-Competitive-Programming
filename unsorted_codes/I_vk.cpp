#include <bits/stdc++.h>
 
#define ff first
#define ss second
#define pb push_back
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
#define int long long
 
using namespace std;
 
void fp(string name){freopen((name+".in").c_str(),"r",stdin); freopen((name+".out").c_str(),"w",stdout);}
int pow(int a,int b,int m){int ans=1;while(b){if(b&1){ans=(ans*a)%m;}b>>=1;a=(a*a)%m;}return ans;}
int binpow(int a,int b){int ans=1;while(b){if(b&1){ans=(ans*a);}b>>=1;a=(a*a);}return ans;}
 
const int N = 2e5 + 100, mod = 1e9 + 7, inf = 1e9;
 
  
int a[N], b[N];
int n;
 
int t[N * 4];
map <int,int> ind;
  
void update(int pos, int x, int v = 1,int tl = 1, int tr = n){
    if(tl == tr){
        t[v] = x;
    }else{
        int mid = (tl + tr) >> 1;
        if(pos <= mid)
            update(pos, x, v * 2, tl, mid);
        else
            update(pos, x, v * 2 + 1,mid + 1, tr);
        t[v] = max(t[v * 2], t[v * 2 + 1]);
    }
}
  
int get(int l, int r, int v = 1, int tl = 1, int tr = n){
    if(tl > r || tr < l)
        return 0;
    if(tl >= l && tr <= r){
        return t[v];
    }
    int mid = (tl + tr) >> 1;
    return max(get(l, r, v * 2, tl, mid), get(l, r, v * 2 + 1, mid + 1, tr));
}
 
int calc(int l ,int r){
    if(l > r)return 0;
    if(l == r) return b[l];
    int mid = (l + r) >> 1;
    int mx = get(l, r);
    int idx = ind[mx];
    //cout << ind << endl;
    int res =  b[idx]+ min(calc(l, idx - 1), calc(idx + 1, r));
    return res;
}
main(){
    iostream::sync_with_stdio(false);   
    cin.tie(nullptr);
    cout.tie(nullptr);
   // memset(dp, -1, sizeof(dp));
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        ind[a[i]] = i;
        update(i, a[i]);
    }
     for(int i = 1; i <= n; i++){
        cin >> b[i];
    }
    cout << calc(1, n)<< endl;
 
}