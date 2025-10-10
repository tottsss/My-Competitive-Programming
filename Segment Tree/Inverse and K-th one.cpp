#include <bits/stdc++.h>

using namespace std;

const int inf = 1e9 + 7, sz = 2e5 + 9, mod = 1e9 + 7;

#define TL ios::sync_with_stdio(0); cin.tie(0);
#define rall(s) s.rbegin(),s.rend()
#define all(s) s.begin(),s.end()
#define pb push_back
#define fi first
#define se second
#define ll long long
#define YES cout<<"YES\n"
#define Yes cout<<"Yes\n"
#define yes cout<<"yes\n"
#define NO cout<<"NO\n"
#define No cout<<"No\n"
#define no cout<<"no\n"

ll size1,size2;

ll tree[1200009] = {},Mx[12000009] = {},le[1200009] = {},ri[1200009] = {},Tm[1200009] = {};

ll ans , sum , ind = 0, dif;

void build_tree(){
     for(ll i = size2; i >= 1; i--){
          if(i >= size1){
          le[i] = i;
          ri[i] = i;
          }else {
               le[i] = le[2 * i];
               ri[i] = ri[2 * i + 1];
          }
     }
}

int get(int i,int l,int r, int o){
     if(Tm[i] != 0){
          if(Tm[i] % 2 == 1)
               tree[i] = (ri[i] - le[i] + 1) - tree[i];
          Tm[2 * i] += Tm[i];
          Tm[2 * i + 1] += Tm[i];
          Tm[i] = 0;
     }
     if(o  == 0){
          if(tree[i] + sum < dif){
               sum += tree[i];
               return 0;
          }
          if(ri[i] == le[i]){
          if(ans == -1 && tree[i] + sum == dif)
          ans = i;
          sum += dif;
          return 0;
          }
     }
     if(o == 1){
     if(le[i] > r || ri[i] < l)
          return 0;
          if(le[i] >= l && ri[i] <= r){
                    Tm[i]++;
                    if(Tm[i] % 2 == 1)
                         tree[i] = (ri[i] - le[i] + 1) - tree[i];
                    Tm[2 * i] += Tm[i];
                    Tm[2 * i + 1] += Tm[i];
                    Tm[i] = 0;
           return 0;
          }
     }
          if(o == 1 || ans == -1){
          get(2 * i, l , r , o);
          get(2 * i + 1, l , r , o);}
          if(o == 1)
          tree[i] = tree[2 * i] + tree[2 * i + 1];

}

void solve()
{
     ll  q , f , l , r ,  s , x , y , i , n , m , j , k , mn = 1e9,mx = -1e9;
     cin>>n>>q;
     size1 = (1 << 18);
     size2 = (1 << 19);
     build_tree();
     while(q--){
          cin>>k;
          if(k == 1){
               cin>>l>>r;
               l += size1;
               r-- , r += size1;
               get(1, l , r , 1 );
          }else {
          cin>>k;
          dif = k + 1, sum = 0, ans = -1;
          get(1 , size1 , n + size1 - 1 , 0 );
          cout<<ans - size1 <<"\n";
          }
     }
     }

int main(){
     TL

     #ifndef ONLINE_JUDGE
     freopen("input.txt", "r", stdin);
     freopen("output.txt", "w", stdout);
     #endif

    auto start = std::chrono::system_clock::now();

int t = 1;
//cin>>t;
while(t--)
     {
     solve();
     }

    auto end = chrono::system_clock::now();
     chrono::duration<double> elapsed_seconds = end - start;
     time_t end_time = chrono::system_clock::to_time_t(end);

//------//

#ifndef ONLINE_JUDGE
         cout<<"\n\n";
         cout << "RUN TIME : " << elapsed_seconds.count() << "s" << endl;
#endif
}