
/*
There is only one character 'A' on
 the screen of a notepad. You can perform one of two operations on this notepad for each step:

    Copy All: You can copy all the characters 
	present on the screen (a partial copy is not allowed).
    Paste: You can paste the characters which are copied last time.

Given an integer n, return the minimum number of 
operations to get the character 'A' exactly n times on the screen.

*/

class Solution {
public:
    int minSteps(int n) {
        vector<int> dp(n + 10, INT_MAX);
        dp[0] = 0, dp[1] = 0;
        for(int i = 1;i <= n; i++){
        	for(int j = 1;i+(j*i) <= n; j++){
        		dp[i+(j*i)] = min(dp[i+(i*j)], dp[i] + 1 + j);
			}
		}
        return dp[n];
    }
};

class Solution {
public:
    int minSteps(int n) {
       int ans = 0;
       for(int div = 2; div <= n / div; div++){
           while(n%div==0){
               n/= div;
               ans+= div;
           }
       }
       if(n > 1) ans+= n;
       return ans;
    }
};