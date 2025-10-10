#include <bits/stdc++.h>
  
using namespace std;
#define ff first
#define ss second
const int M = 1e9+9;
const int N = 10001;
int dp[N][10][10];


bool isprime(int n){
    for(int i = 2;i * i<= n; i++){
        if(n%i==0) return false;
    }
    return true;
}

int zero(int n){
    if(n%10 == 0) return true;
    if((n/10) % 10==0) return true;
    return false;
}
main(){
    int n; cin >> n;
    int ans3 = 0;
    for(int i = 100;i < 1000; i++){
        if(isprime(i)){
            ans3++;
            // cout << i << endl;
            if (!zero(i)) dp[3][(i/10)%10][i%10]++;
        }
    }
    if(n == 3){
        cout << ans3;
        exit(0);
    }
    for(int len = 4; len <= n; len++){
        for(int x = 1; x < 10; x++){
            for(int y = 1; y < 10; y++){
                for(int z = 1; z < 10; z++){
                    if(isprime((x*100 )+ (y*10) + z)){
                        dp[len][y][z]+= dp[len-1][x][y]%M;
                      dp[len][y][z] %= M;
                    }
                }
            }
        }
    }
    int sum = 0;
    for(int x = 1; x < 10; x++){
        for(int y = 1; y  < 10; y++){
            sum+= dp[n][x][y]%M;
          sum%=M;
        }
    }
    cout << sum%M;

    return 0;
 
}