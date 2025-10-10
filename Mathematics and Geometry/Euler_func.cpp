#include <bits/stdc++.h>
using namespace std;
 
#define int long long
 main(){
    int n;
   cin >> n;
        if(n == 0) return 0;
        int c = n;
        for(int x = 2;x * x < n + 1LL; x++){
            if(n % x == 0){
                    c  = c - (c / x);
                while(n %x == 0){
                    n/= x;
                }
            }
        }
        if(n > 1LL) c = c - (c / n);
        cout << c << "\n";
     
    return 0;
}