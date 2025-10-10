#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef tree<pair<int, int>, null_type, less<pair<int, int> >, rb_tree_tag, 
tree_order_statistics_node_update> ordered_set;
 
#define int long long
 
struct range{
    int l, r, index;
    bool operator<(const range &other) const{
        if(l == other.l) return r > other.r;
        return l<other.l;
    }
};
 
main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n; cin >> n;
    ordered_set st;
    vector<int> contains(n,0), contained(n,0);
    map<int, int> mp;
    vector< range> ranges(n);
    for(int i = 0;i < n; i++){
        cin>>ranges[i].l>>ranges[i].r;
        ranges[i].index=i;
        mp[ranges[i].r]++;
    }
    sort(ranges.begin(), ranges.end());
    
    for(int i = 0;i < n; i++){
        contained[ranges[i].index] =i- st.order_of_key({ranges[i].r, -1});
        st.insert({ranges[i].r, i});
    }
    st.clear();
    for(int i = n-1; i >= 0; i--){
        contains[ranges[i].index] = st.order_of_key({ranges[i].r, n});
        st.insert({ranges[i].r, i});
    }
 
    for(auto x : contains) cout<<x<<" ";
        cout<<endl;
    for(auto x : contained) cout <<x<< " ";
    // for(auto x : ranges) cout << x.l << " " << x.r << "\n";
    return 0;
}