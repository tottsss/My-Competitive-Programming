#include <bits/stdc++.h>
  
#define ff first
#define ss second
#define pb push_back
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
#define int long long
 
using namespace std;
 
int pow(int a,int b,int m){int ans=1;while(b){if(b&1){ans=(ans*a)%m;}b>>=1;a=(a*a)%m;}return ans;}
int binpow(int a,int b){int ans=1;while(b){if(b&1){ans=(ans*a);}b>>=1;a=(a*a);}return ans;}
 
const int N = 2e5 + 100;
 
main(){
    iostream::sync_with_stdio(false);
    cin.tie(nullptr);   
    cout.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector <int> v(m);
    map <int,int> mp;
    for(int i = 0; i < m; i++){
        cin >> v[i];
        mp[v[i]]++;
    }
    vector <int> ans;
    for(int i = 0; i < m; i++){
        if(mp[v[i]] >= n){
            ans.pb(v[i]);
            mp[v[i]] = 0;
        }
    }
    cout << ans.size() << endl;
    for(auto x : ans)
        cout << x <<" ";
}