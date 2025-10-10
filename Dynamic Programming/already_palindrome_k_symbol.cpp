#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ff first
#define ss second
#define all(a) a.begin(), a.end()
const int N = 5000;
int odd[N], even[N];
int n, k;
string s;


int manaker(){
	int ans = 0;
	for(int i = 0;i < n; i++){
        int need = k;
        odd[i] = 1;
        while(i-odd[i] >= 0 and i + odd[i] < n){
            if(s[i + odd[i]] != s[i-odd[i]]){
                if(need <= 0) break;
                need--;
            }
            odd[i]++;
        }
 // https://informatics.msk.ru/mod/statements/view.php?id=1480&chapterid=491#1
        even[i] = 0, need = k;
        while(i - even[i] - 1 >= 0 and i + even[i] < n){
            if(s[i-even[i] - 1] != s[i + even[i]]){
                if(need <= 0) break;
                need--;
            }
            even[i]++;
        }
        ans+= odd[i]+even[i];
    }
    return ans;
}


main(){
   ios::sync_with_stdio(0);
   cin.tie(0); cout.tie(0);
	cin >> n >> k >> s;
	cout << manaker();
	return 0;
}

