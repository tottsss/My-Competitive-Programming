#include <bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
const int N = 2e5;
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
int n;
map<int, set<int> > mp;
vector<int> a;
int tree[4*N + 10];
map<int, int> cnt;
 
void update(int v, int x, int vl, int vr, int depth){
    tree[v] = x;
//  cout << vl << " " << vr << ", " << depth << " = " << x << '\n';
    if(cnt[x]){
         
        mp[cnt[x]].erase(x);
    } 
    cnt[x] = 0;
//  mp[cnt[x]].erase(x);
     
    if(vl == vr) return;
    int mid = (vl + vr)>>1;
    if(mp[depth-1].empty() == false){
        auto it = mp[depth-1].lower_bound(x);
//      cout << "+++++++++++  ";
    //  cout << *it << '\n';
        if(it != mp[depth-1].end() && *it > x){
            update(v<<1, *it, vl, mid, depth-1);
        }
    }
 
    update(v<<1|1, x, mid+1, vr, depth-1);
}
 
int get(int pos, int v, int vl, int vr){
    if(vl == vr){
        return tree[v];
    }
    int mid = (vl + vr)>>1;
    if(mid >= pos) return get(pos, v<<1, vl, mid);
    else return get(pos, v<<1|1, mid+1, vr);
}
int k;
 
main(){
    cin >> n;
    a.resize(n);
    for(int i = 0;i < n; i++){
        cin >> a[i];
        cnt[a[i]]++;
    }
    for(auto x : cnt){
        //cout << x.ff << " " << x.ss << '\n';
        mp[x.ss].insert(x.ff);
    }
     
    for(int i = 1;i <= n; i++){
        int sum = 0;
        int x = i;
        while(x > 0){
            sum+= x;
            x/= 2;
        }
        if(sum == n){
            k = i;
        }
    }
    if(!k){
        assert(false);
    }
    int x = k, lg = 0;
    while(x > 0){
        lg++, x/= 2;
    }
//  cout << k << " = " << lg << '\n';
    set<int> st(all(a));
    if(st.size() != k){
        cout << "-1";
        return 0;
    }
    update(1, *min_element(a.begin(), a.end()), 1, k, lg);
    vector<int> srt;
    for(int i = 0;i < 4*N+10; i++){
        if(tree[i]){
            srt.push_back(tree[i]);
        }
    }   
     
    if(srt.size() != a.size()){
        cout << "-1";
        return 0;
    }
    //cout << 't';
    sort(all(srt));
    sort(all(a));
    for(int i = 0;i < srt.size(); i++){
        if(srt[i] != a[i]){
            cout << "-1";
            return 0;
        }   
    }
    vector<int> ans;
     
    for(int i = 1;i <= k; i++){
        ans.push_back(get(i, 1, 1,k));
    }
    st.clear();
    for(int x : ans) st.insert(x);
    if(st.size() != k){
        cout << "-1";
        return 0;
    }
    for(auto x : ans) cout << x << ' ';
    return 0;
}