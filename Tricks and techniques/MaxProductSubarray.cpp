class Solution {
public:
    int maxProduct(vector<int>& a) {
        int best = *max_element(a.begin(), a.end()), prod=0;
        int n = a.size();
		for(int i = 0;i<n; i++){
            if(prod==0) prod = a[i];
            else prod*= a[i];
            best = max(best, prod);
        }
        prod = 0;
        for(int i = n-1; i >= 0; i--){
            if(prod==0) prod = a[i];
            else prod*= a[i];
            best = max(best, prod);
        }
        return best;
    }
};

/*
class Solution {
public:
// Kadanes Algorithm
    int maxProduct(vector<int>& a) {
        int best = a[0], n = a.size();
		int Mn = a[0], Mx = a[0];
        for(int i = 1;i < n; i++){
            int p = min(a[i], min(Mn*a[i], Mx*a[i]));
            Mx = max(a[i], max(Mn*a[i], Mx*a[i]));
            Mn = p;
            best = max(best, max(Mn, Mx));
        }
        return best;
    }
};
*/