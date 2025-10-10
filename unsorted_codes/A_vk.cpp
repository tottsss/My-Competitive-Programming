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
    int n, m, k;
    cin >> n >> m >> k;
    cout << ((n + k - 1) / k) * ((m + k - 1) / k) << endl;
}