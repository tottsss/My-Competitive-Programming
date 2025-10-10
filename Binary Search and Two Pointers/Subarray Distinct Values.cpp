#include <bits/stdc++.h>
using namespace std;
 
int main(){
    int n, k;
    cin >> n >> k;
    vector<long long> a(n);
    for(int i = 0;i < n; i++) cin >> a[i];
    map<int, int> mp;
    long long count_num = 0;
    long long num = 0;
    
    for(int r = 0, l = 0;r < n; r++){
        mp[a[r]]++;
        if(mp[a[r]] == 1) num++;
        while(num > k and l < n){
            mp[a[l]]--;
            if(mp[a[l]] == 0) num--;
            l++;
        }
        if(num <= k){
            count_num+= (r - l) + 1;
        }
        
    }
    
    
    cout << count_num;
    return 0;
}
 
const int Time=[](){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    return 0;
}();